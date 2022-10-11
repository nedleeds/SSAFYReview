#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

// AWS IP
const char *IP = "127.0.0.1";
const char *PORT = "12345";

int sock;

void interrupt(int arg)
{
	printf("\nYou typped Ctrl + C\n");
	printf("Bye\n");

	close(sock);
	exit(1);
}

int main()
{
	//client 는 server 와의 '연결'에 목적
	signal(SIGINT, interrupt);

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		printf("ERROR :: 1_Socket Create Error\n");
		exit(1);
	}

	// inet_addr(IP): 1) string2int 2) bigendian 3) long int 
	struct sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(IP);
	addr.sin_port = htons(atoi(PORT));

	// connect()
	// : 연결할 서버의 주소 정보를 받음
	// : 원격 연결할 서버의 주소 정보를 소켓에 담는 함수
	// sock: connect 성공 시 소켓의 파일 디스크립터
	if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1)
	{
		printf("ERROR :: 2_Connect Error\n");
		exit(1);
	}

	char buf[100];
	while (1)
	{
		// 입력 받을 버퍼 초기화
		memset(buf, 0, 100);
		scanf("%s", buf);// 입력 받음
		if (!strcmp(buf, "exit")) // exit 입력 시
		{
			write(sock, buf, strlen(buf)); // exit 을 서버에 송신
			break; // 멈춤
		}
		write(sock, buf, strlen(buf)); // exit 아닐 시 서버에 송신
		memset(buf, 0, 100);
		int len = read(sock, buf, 99); // 서버에서 보낸 메세지를 read
		if (len == 0) // EOF
		{
			printf("INFO :: Server Disconnected\n");
			break;
		}
		printf("%s\n", buf);
	}

	// close sock
	close(sock);
	return 0;
}
