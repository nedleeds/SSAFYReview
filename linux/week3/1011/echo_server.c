#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

// 서비스할 포트 미리 정해둠
const char *PORT = "12345";

int server_sock;
int client_sock;

void interrupt(int arg)
{
	printf("\nYou typed Ctrl + C\n");
	printf("Bye\n");

	close(client_sock);
	close(server_sock);
	exit(1);
}

void removeEnterChar(char *buf)
{
	int len = strlen(buf);
	for (int i = len - 1; i >= 0; i--)
	{
		if (buf[i] == '\n')
			buf[i] = '\0';
		break;
	}
} int main()
{
	// Ctrl + C 누를 경우 안전종료
	signal(SIGINT, interrupt);

	// socket create
	server_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (server_sock == -1) // 소켓 생성 에러 핸들링
	{
		printf("ERROR :: 1_Socket Create Error\n");
		exit(1);
	}

	// option setting
	// 종료 시 3분 정도 동일한 포트 배정 불가 에러 해결
	// default : 실제 서버 운영 시, 같은 프로그램을 재빠르게 다시 켜는걸 막아놓음
	// 우리는 단순 실험이기 때문에 해당 옵션을 꺼둔다
	int optval = 1;
	setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, (void *)&optval, sizeof(optval));

	// 주소 설정: 소켓에 적용될 주소에 필요한 값들을 설정
	// AF_INET : IPv4 
	// INADDR_ANY : 현재 server IP
	// PORT : 현재 server PORT
	// network 에서는 빅엔디안이 기본으로 설정됨
	// 엔디안 변환 함수 : htonl, htons, ntohl, ntohs
	// htonl : host(내PC) to network(서버), long int(IP): 빅엔디안, long int 으로
	// htons : host(내PC) to network(서버), short int(PORT): 빅엔디안, short int 으로 
	// ntohl : network(서버) to host(내PC), long int(IP): 
	// ntohs : network(서버) to host(내PC), short int(PORT)
	struct sockaddr_in server_addr = {0};
	server_addr.sin_family = AF_INET; 
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
	server_addr.sin_port = htons(atoi(PORT));

	// bind
	// struct sockaddr_in -> struct sockadd 로 형변환 (컴퓨터를 위한 변환)
	// server_sock: 소켓 파일 디스크립터(정수형)
	if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
	{
		// error handling
		printf("ERROR :: 2_bind Error\n");
		exit(1);
	}

	// listen -> 대기실 만들기(client 요청대기)
	// 클라이언트의 연결요청 시, 연결이 수락 될 때까지
	// 요청자체를 대기 시킬 수 있는 상태
	// 연결 요청 대기 큐: 연결 요청이 들어가는 대기실
	// 					: 크기를 지정해줘야함
	//					: 대기 큐의 크기는 최대 동시 접속 클라이언트 수가 X
	if (listen(server_sock, 5) == -1)
	{
		printf("ERROR :: 3_listen Error");
		exit(1);
	}

	client_sock = 0;
	struct sockaddr_in client_addr = {0};
	socklen_t client_addr_len = sizeof(client_addr);

	while (1)
	{
		// 새로운 클라이언트를 위해 초기화
		memset(&client_addr, 0, sizeof(client_addr));

		// accept - 통신을 위한 서버의 client 요청 수락
		// accept() : 1) 함수 호출 성공 시 내부적으로 소켓 생성
		// 			  2) 해당 소켓의 파일 디스크립터를 반환
		// 			  3) 연결 요청을 한 클라이언트 소켓을 연결
		client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
		if (client_sock == -1)
		{
			printf("ERROR :: 4_accept Error\n");
			break;
		}

		// read & write
		// read : client_sock 로부터 데이터 읽음->buf 길이반환
		// writhe : client_sock 에 데이터를 씀->전송
		char buf[100];
		while (1)
		{
			memset(buf, 0, 100);
			int len = read(client_sock, buf, 99);

			// remove '\n'
			removeEnterChar(buf);

			// client 와 연결이 끊어졌을 때 클라이언트 종료
			if (len == 0)
			{
				printf("INFO :: Disconnect with client... BYE\n");
				break;
			}

			// client 에서 exit 입력했을 때 클라이언트 종료
			if (!strcmp("exit", buf))
			{
				printf("INFO :: Client want close... BYE\n");
				break;
			}
			write(client_sock, buf, strlen(buf));
		}
		// 클라이언트 소켓 close
		close(client_sock);
	}
	// 서버 소켓 close
	close(server_sock);
	return 0;
}

