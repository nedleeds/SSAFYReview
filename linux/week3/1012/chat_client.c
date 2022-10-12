#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

#define NAME_SIZE 20
#define MSG_SIZE 100

// SERVER IP & PORT
const char *IP = "127.0.0.1";
const char *PORT = "12345";

pthread_t send_tid;
pthread_t receive_tid;
int exitFlag; // thread 간 종료 상태 체크용
int sock;  	  // socket

// 채팅창에 보여질 이름의 형태
// 개발자가 코드를 열었을 때 확인하기 위함
char name[NAME_SIZE] = "[DEFAULT]"; // max: 20
char msg[MSG_SIZE]; 				// max:100

void *sendMsg()
{
	// data parsing: 미리 사이즈 할당
	// -> NAME과 MSF 크기 모두 고려 (효율적)
	char buf[NAME_SIZE + MSG_SIZE];

	// exitFlag 는, 다른 한 쪽의 쓰레드를 종료하는 용도
	while (!exitFlag)
	{
		// MSG 들어오면 초기화 진행
		memset(buf, 0, NAME_SIZE + MSG_SIZE);
		// 띄어쓰기는 반드시 들어가야 -> fgets 사용
		// 그래서 fgets 사용하며, 엔터까지 입력됨을 유의하라
		fgets(msg, MSG_SIZE, stdin);
		if (!strcmp(msg, "exit\n"))
		{
			// thread 종료 깃발 올림
			exitFlag = 1;
			// 서버에 메세지를 적음(보냄) 
			write(sock, msg, strlen(msg));
			break;
		}
		if (exitFlag)
			break;
		// 실제로 서버에 보낼 메세지 형태
		// buf = "[ssafy] 안녕 얘들아"
		sprintf(buf, "%s %s", name, msg);
		// 서버에 데이터 적음(보냄)
		write(sock, buf, strlen(buf));
	}
}

void *receiveMsg()
{
	char buf[NAME_SIZE + MSG_SIZE];
	while (!exitFlag)
	{
		memset(buf, 0, MSG_SIZE);
		// server 에서 메세지 읽음(대기)
		int len = read(sock, buf, NAME_SIZE + MSG_SIZE - 1);
		if (len == 0)
		{
			// server 에서 종료한 경우
			printf("INFO :: Server Disconnected\n");
			kill(0, SIGINT); // interrupt 핸들러 진행
			exitFlag = 1;
			break;
		}
		printf("%s\n", buf);
	}
}

void interrupt(int arg)
{
	printf("\nYou typped Ctrl + C\n");
	printf("Bye\n");

	// thread 강제 종료 - 둘 다
	pthread_cancel(send_tid);
	pthread_cancel(receive_tid);
	// 종료 대기 + 메모리 할당 해제
	pthread_join(send_tid, 0);
	pthread_join(receive_tid, 0);

	// 종료가 되고 나면
	// 소켓을 깔끔하게 닫는다
	close(sock);
	exit(1);
}

// 커멘드 아규먼트 필요로 함: 사용할 닉네임
int main(int argc, char *argv[])
{
	signal(SIGINT, interrupt);

	// 잘못 사용했을 경우, 프로그램 사용법 안내
	if (argc != 2)
	{
		printf("Usage : %s <name>\n", argv[0]);
		exit(1);
	}

	// sprintf 사용해서, [닉네임] 형태로 name 저장
	// python 의 f"{argv[1]}" 와 동일
	sprintf(name, "[%s]", argv[1]);

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		printf("ERROR :: 1_Socket Create Error\n");
		exit(1);
	}

	// sockaddr 로 형변환
	struct sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(IP);
	// inet_addr : str -> int, int -> long int, 빅엔디안
	addr.sin_port = htons(atoi(PORT));

	// Connect
	// sock(int): File descriptort
	if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1)
	{
		printf("ERROR :: 2_Connect Error\n");
		exit(1);
	}

	// Thread Run
	pthread_create(&send_tid, NULL, sendMsg, NULL);
	pthread_create(&receive_tid, NULL, receiveMsg, NULL);

	pthread_join(send_tid, 0);
	pthread_join(receive_tid, 0);

	// close sock
	close(sock);
	return 0;
}
