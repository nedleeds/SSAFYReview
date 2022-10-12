#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

//최대 client 수 500 -> max thread: 500
#define MAX_CLIENT_CNT 500

const char *PORT = "12345";
// server_sock: 파일 디스크립터 (안내원)
int server_sock;
// client_sock[500]: 파일 디스크립터 500개 
int client_sock[MAX_CLIENT_CNT];
// sockaddr_in: 사람을 위한 자료구조
// sockaddr: 컴퓨터를 위한 자료구조로 형변환 진행
struct sockaddr_in client_addr[MAX_CLIENT_CNT];

// thread 500개 선언
pthread_t tid[MAX_CLIENT_CNT];
// 각 client의 thread가 종료되었을 때 flag
int exitFlag[MAX_CLIENT_CNT];

// mutex 선언
pthread_mutex_t mutx;

void interrupt(int arg)
{
	printf("\nYou typed Ctrl + C\n");
	printf("Bye\n");

	for (int i = 0; i < MAX_CLIENT_CNT; i++)
	{
		// client_sock이 있으면
		if (client_sock[i] != 0)
		{
			pthread_cancel(tid[i]); // 멈춤(강제종료)
			pthread_join(tid[i], 0);// 종료대기+할당해제
			close(client_sock[i]);  // 해당 소켓을 닫음
		}
	}
	close(server_sock);
	exit(1);
}

// 개행제거 함수
void removeEnterChar(char *buf)
{
	int len = strlen(buf);
	for (int i = len - 1; i >= 0; i--)
	{
		if (buf[i] == '\n')
			buf[i] = '\0';
		break;
	}
}

// client_sock 의 비어있는 곳의 index를 반환
// client data가 저장될 곳을 알게됨
int getClientID()
{
	for (int i = 0; i < MAX_CLIENT_CNT; i++)
	{
		if (client_sock[i] == 0)
			return i;
	}
	return -1;
}

// thread 함수 - server는 안내원 한명이라
// 멀티 스레딩을 할 필요가 없다
void *client_handler(void *arg)
{
	int id = *(int *)arg;

	char name[100];
	// inet_ntoa 는,빅 엔디안  long int ip 를 문자열로 바꿈
	strcpy(name, inet_ntoa(client_addr[id].sin_addr));
	printf("INFO :: Connect new Client (ID : %d, IP : %s)\n", id, name);

	// wait & write
	char buf[100];
	while (1)
	{
		memset(buf, 0, 100);
		int len = read(client_sock[id], buf, 99);
		// 종료 조건 -> clinet 가 ctrl+c / exit 쳤을 때
		if (len == 0)
		{
			printf("INFO :: Disconnect with client.. BYE\n");
			exitFlag[id] = 1;
			break;
		}

		if (!strcmp("exit", buf))
		{
			printf("INFO :: Client want close.. BYE\n");
			exitFlag[id] = 1;
			break;
		}

		// remove '\n'
		removeEnterChar(buf);

		// send new message
		// mutex -> client_sock 을 전역변수로 멀티 스레딩이 일어나기 때문
		pthread_mutex_lock(&mutx); // 잠그고
		for (int i = 0; i < MAX_CLIENT_CNT; i++)
		{
			if (client_sock[i] != 0) // 파일 디스크립터에 내용이 있으면
			{
				write(client_sock[i], buf, strlen(buf)); // 데이터 전송
			}
		}
		pthread_mutex_unlock(&mutx); // 잠금해제
	}
	close(client_sock[id]);
}

int main()
{
	// Ctrl + C 누를 경우 안전종료
	// SIGINT : ctrl + c
	// 이게 없으면, 메모리 해제없이 종료하게됨
	// 해제를 안하면 나중에 멈춤
	signal(SIGINT, interrupt);

	// mutex init
	pthread_mutex_init(&mutx, NULL);
	// socket create
	// PF_INET : IPv4
	// SOCK_STREAM
	// 0 : PF_INET과 SOCK_STREAM 모두 만족하는 조건은 0 하나만 존재
	server_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (server_sock == -1)
	{
		// 소켓 생성에 실패하는 경우 : 보통 메모리 부족으로 인한 것
		// 에러 핸들링
		printf("ERROR :: 1_Socket Create Error\n");
		exit(1);
	}

	// option setting
	// 종료 시 3분 정도 동일한 포트 배정 불가 에러 해결
	int optval = 1;
	setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, (void *)&optval, sizeof(optval));

	// 주소 설정
	// sockaddr_in -> sockaddr 형변환
	// 내 컴퓨터가 빅엔디안이어도 모든 사용자가 빅엔디안 cpu를 사용할 거란 보장이 없다
	struct sockaddr_in server_addr = {0};
	server_addr.sin_family = AF_INET; // AF_INET: IPv4
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 서버 본인의 IP(int)
	server_addr.sin_port = htons(atoi(PORT)); // 서버 본인의 PORT(string)

	// bind
	if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
	{
		printf("ERROR :: 2_bind Error\n");
		exit(1);
	}

	// listen
	// 대기실 생성, 사이즈: 5
	if (listen(server_sock, 5) == -1)
	{
		printf("ERROR :: 3_listen Error");
		exit(1);
	}

	// socket 처리시 길이를 필요로 한 순간이 많다
	// 따라서 해당 길이 값을 저장한다
	socklen_t client_addr_len = sizeof(struct sockaddr_in);

	// pthread argument bug fix
	int id_table[MAX_CLIENT_CNT];
	printf("Wait for next client...\n");

	while (1)
	{
		// get Client ID
		int id = getClientID(); 
		id_table[id] = id; // thread create 시 버그 발생 방지 Line:208

		if (id == -1) // client socket 이 꽉 차있으면 실행
		{
			printf("WARNING :: Client FULL\n");
			sleep(1);
		}

		// 새로운 클라이언트를 위해 초기화
		// client 주소 정보를 초기화
		memset(&client_addr[id], 0, sizeof(struct sockaddr_in));

		// accpet -> 장사 시작!
		// 현재 소유한 client_addr 을 가지고server_sock 과 통신하기 시작
		client_sock[id] = accept(server_sock, (struct sockaddr *)&client_addr[id], &client_addr_len);
		if (client_sock[id] == -1)
		{
			printf("ERROR :: 4_accept Error\n");
			break;
		}

		// Create Thread
		// &id_table[id] 를 id로 바꾸면 thread 가 생성될때 넘겨주는 argument
		// 값을 확실히 보장해주게 된다.
		pthread_create(&tid[id], NULL, client_handler, (void *)&id_table[id]);

		// check ExitFlag
		for (int i = 0; i < MAX_CLIENT_CNT; i++)
		{
			// 끝난다는 신호를 받은 경우
			// 다음 경우를 위해 준비한다
			if (exitFlag[i] == 1)
			{
				// 플래그 0으로 변환
				exitFlag[i] = 0;
				// ?
				pthread_join(tid[i], 0);
				// ?
				client_sock[i] = 0;
			}
		}
	}
	// 서버 소켓 close
	close(server_sock);
	return 0;
}
