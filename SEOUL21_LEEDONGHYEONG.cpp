#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winSock2.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

#pragma warning(disable : 4996)
#pragma comment(lib, "ws2_32.lib")

// 닉네임을 사용자에 맞게 변경해 주세요.
#define NICKNAME "SEOUL21_LEEDONGHYEONG"

// 일타싸피 프로그램을 로컬에서 실행할 경우 변경하지 않습니다.
#define HOST "127.0.0.1"

// 일타싸피 프로그램과 통신할 때 사용하는 코드값으로 변경하지 않습니다.
#define PORT 1447
#define CODE_SEND 9901
#define CODE_REQUEST 9902
#define SIGNAL_ORDER 9908
#define SIGNAL_CLOSE 9909

void ErrorHandling(const char* message);

struct Ball { float x, y; } white, target;
float HOLES[6][2] = { {0, 0}, {127, 0}, {254, 0}, {0, 127}, {127, 127}, {254, 127} };
float radius = 5.71;
int isNegativeTilt;
int mIdx, tIdx;
int cnt = 0;

void findHole(Ball w, Ball t) {
	float mDis = 2134567890.0;
	for (int i = 0; i < 6; i++) {
		float width = fabsf(t.x - HOLES[i][0]);
		float height = fabsf(t.y - HOLES[i][1]);
		double distance = (double)sqrt((width * width) + (height * height));
		if (distance <= mDis) {
			mDis = distance;
			mIdx = i;
		}
	}
	if (HOLES[mIdx][1] < t.y)
		isNegativeTilt = 0;
	else
		isNegativeTilt = 1;
}

void getTarget(int numOfBalls, float ball[6][2]) {
	// 8 ball 처리 필요
	for (int i = 1; i < numOfBalls; i++)
	{
		if (ball[i][0] != -1) {
			target.x = ball[i][0];
			target.y = ball[i][1];
			tIdx = i;
			return;
		}
	}
}

float checkAngle(float a) {

	if (target.x < white.x && target.y < white.y) {
		// 3사분면
		a += 180.0;
		return a;
	}
	else if (target.x < white.x && target.y > white.y) {
		// 2사분면
		a += 270.0;
		return a;
	}
	else if (target.x > white.x && target.y > white.y) {
		// 1사분면
		return a;
	}
	else if (target.x > white.x && target.y < white.y) {
		// 4사분면
		a += 90;
		return a;
	}

}

double getDegree(double w, double h) {
	double radian = h > 0 ? atan(h / w) : 0;
	float angle = (float)((180 / M_PI) * radian);
	return angle;
}

float getMidAngle(float dx, float dy) {
	float mid_angle = 0.0;
	if (target.x > white.x && target.y > white.y) {
		// 1사분면
		double dw = dy;   // dy <- height 
		double dh = dx;  // dx <- width
		mid_angle = getDegree(dw, dh);
	}
	else if (target.x > white.x && target.y < white.y) {
		// 2사분면
		double dw = dx;
		double dh = dy;
		mid_angle = getDegree(dw, dh) + 90;
	}
	else if (target.x < white.x && target.y < white.y) {
		// 3사분면
		double dw = dy;
		double dh = dx;
		mid_angle = getDegree(dw, dh) + 180;
	}
	else if (target.x < white.x && target.y > white.y) {
		double dw = dx;
		double dh = dy;
		mid_angle = getDegree(dw, dh) + 270;
	}
	printf("mid_angle : %lf\n", mid_angle);
	return mid_angle;
}

float getAngle(double d, float mid_angle) {
	radius /= 2;
	float w = sqrt(float(d) * float(d) - radius * radius);

	double radian = radius > 0 ? atan(w / radius) : 0;
	float angle = (float)((180 / M_PI) * radian);
	return angle + mid_angle;
}

int w2h_t2h_degree_compare() {
	float w2h_width = fabsf(HOLES[mIdx][0] - white.x);
	float w2h_height = fabsf(HOLES[mIdx][1] - white.y);

	float t2h_width = fabsf(HOLES[mIdx][0] - white.x);
	float t2h_height = fabsf(HOLES[mIdx][1] - white.y);

	float w2h_degree = getDegree(w2h_width, w2h_height);
	float t2h_degree = getDegree(t2h_width, t2h_height);

	if (t2h_degree < w2h_degree) {
		printf("t2h tilt < w2h tilt\n");
		return -1;
	}
	else if (t2h_degree > w2h_degree) {
		printf("t2h tilt > w2h tilt\n");
		return 1;
	}
	else {
		printf("t2h tilt == w2h tilt\n");
		return 0;
	}

}

int main()
{
	// 게임 환경에 대한 상수입니다.
	int TABLE_WIDTH = 254;
	int TABLE_HEIGHT = 127;
	int NUMBER_OF_BALLS = 6;

	float balls[6][2] = {
		0.0f,
	};
	int order = 0;

	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN sockAddr;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup failure.");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);

	if (hSocket == INVALID_SOCKET)
		ErrorHandling("Socket Creating Failure.");

	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_addr.s_addr = inet_addr(HOST);
	sockAddr.sin_port = htons(PORT);

	printf("Trying Connect: %s:%d\n", HOST, PORT);
	if (connect(hSocket, (SOCKADDR*)&sockAddr, sizeof(sockAddr)) == SOCKET_ERROR)
		ErrorHandling("Connection Failure.");
	else
		printf("Connected: %s:%d\n", HOST, PORT);

	char sendData[1024];

	sprintf(sendData, "%d/%s/", CODE_SEND, NICKNAME);
	send(hSocket, (char*)&sendData, sizeof(sendData), 0);
	printf("Ready to play!\n--------------------");

	while (1)
	{
		// Receive Data
		cnt++;
		char message[1024];
		int strLen;
		int recvCount = 0;
		strLen = recv(hSocket, message, sizeof(message) - 1, 0);
		// printf("Data Received: %s\n", message);

		// Read Game Data
		char* recvData;
		recvData = strtok(message, "/");
		float pos = atof(recvData);

		recvCount++;

		for (int i = 0; i < NUMBER_OF_BALLS; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				balls[i][j] = pos;
				recvData = strtok(NULL, "/");

				if (recvData != NULL)
				{
					pos = atof(recvData);

					recvCount++;
				}
			}
		}

		// Check Signal for Player Order or Close Connection
		if (balls[0][0] == SIGNAL_ORDER)
		{
			order = (int)balls[0][1];
			printf("\n\n* You will be the %s player. *\n\n", order == 1 ? "first" : "second");
			continue;
		}
		else if (balls[0][0] == SIGNAL_CLOSE)
		{
			break;
		}

		float angle = 0.0f;
		float power = 0.0f;

		//////////////////////////////
		// 이 위는 일타싸피와 통신하여 데이터를 주고 받기 위해 작성된 부분이므로 수정하면 안됩니다.
		//
		// 모든 수신값은 변수, 배열에서 확인할 수 있습니다.
		//   - order: 1인 경우 선공, 2인 경우 후공을 의미
		//   - balls[][]: 일타싸피 정보를 수신해서 각 공의 좌표를 배열로 저장
		//     예) balls[0][0]: 흰 공의 X좌표
		//         balls[0][1]: 흰 공의 Y좌표
		//         balls[1][0]: 1번 공의 X좌표
		//         balls[4][0]: 4번 공의 X좌표
		//         balls[5][0]: 마지막 번호(8번) 공의 X좌표

		// 여기서부터 코드를 작성하세요.
		// 아래에 있는 것은 샘플로 작성된 코드이므로 자유롭게 변경할 수 있습니다.

		// whiteBall_x, whiteBall_y: 흰 공의 X, Y좌표를 나타내기 위해 사용한 변수
		white = { balls[0][0], balls[0][1] };

		// targetBall_x, targetBall_y: 목적구의 X, Y좌표를 나타내기 위해 사용한 변수
		// targetBall 찾기
		getTarget(NUMBER_OF_BALLS, balls);
		//float targetBall_x = balls[1][0];
		//float targetBall_y = balls[1][1];

		// Hole 선택 -- 타겟구와 가장 가까운 홀 + 둔각 삼각형인 경우 선택
		findHole(white, target);

		printf("white ball %d: [%f, %f]\n", 0, white.x, white.y);
		printf("target ball %d: [%f, %f](tilt:(%d))\n", tIdx, target.x, target.y, isNegativeTilt);
		printf("nearest Hole : [%f, %f]\n", HOLES[mIdx][0], HOLES[mIdx][1]);

		// width, height: 목적구와 흰 공의 X좌표 간의 거리, Y좌표 간의 거리
		float width = fabsf(target.x - white.x);
		float height = fabsf(target.y - white.y);
		double distance = (double)sqrt((width * width) + (height * height));
		
		float mid_angle = getMidAngle(width, height);

		int diff = w2h_t2h_degree_compare();
		if (target.x == 120.0 && target.y == 8.00)
			angle = mid_angle;
		else{
			angle = mid_angle + diff;
		}
		printf("mid_angle/fin_angle : %lf/%lf\n", mid_angle, angle);

		// 목적구가 상하좌우로 일직선상에 위치했을 때 각도 입력
		if (white.x == target.x)
		{
			if (white.y < target.x)
			{
				angle = 0;
			}
			else
			{
				angle = 180;
			}
		}
		else if (white.y == target.x)
		{
			if (white.y < target.x)
			{
				angle = 90;
			}
			else
			{
				angle = 270;
			}
		}

		//// 목적구가 흰 공을 중심으로 3사분면에 위치했을 때 각도를 재계산
		//if (white.x > target.x && white.y > target.y)
		//{
		//	radian = atan(width / height);
		//	angle = (float)(((180 / M_PI) * radian) + 180);
		//}
		//// 목적구가 흰 공을 중심으로 4사분면에 위치했을 때 각도를 재계산
		//else if (white.x < target.x && white.y > target.y)
		//{
		//	radian = atan(height / width);
		//	angle = (float)(((180 / M_PI) * radian) + 90);
		//}

		// distance: 두 점(좌표) 사이의 거리를 계산
		//double distance = (double)sqrt((width * width) + (height * height));

		// power: 거리 distance에 따른 힘의 세기를 계산
		power = (float)distance * 5;






		// 주어진 데이터(공의 좌표)를 활용하여 두 개의 값을 최종 결정하고 나면,
		// 나머지 코드에서 일타싸피로 값을 보내 자동으로 플레이를 진행하게 합니다.
		//   - angle: 흰 공을 때려서 보낼 방향(각도)
		//   - power: 흰 공을 때릴 힘의 세기
		// 
		// 이 때 주의할 점은 power는 100을 초과할 수 없으며,
		// power = 0인 경우 힘이 제로(0)이므로 아무런 반응이 나타나지 않습니다.
		//
		// 아래는 일타싸피와 통신하는 나머지 부분이므로 수정하면 안됩니다.
		//////////////////////////////

		char mergedData[1024];
		sprintf(mergedData, "%f/%f/", angle, power);
		send(hSocket, (char*)&mergedData, sizeof(mergedData), 0);
		printf("Data Sent: %s\n", mergedData);
	}

	closesocket(hSocket);
	WSACleanup();

	return 0;
}

void ErrorHandling(const char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}