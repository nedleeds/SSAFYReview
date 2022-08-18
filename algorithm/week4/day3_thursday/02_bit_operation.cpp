#include <iostream>
using namespace std;

int main() {
	// &  : and <- 특정 bit를 추출, 특정 bit를 0으로 만들고 싶을 때
	// |  : or  <- 특정 bit를 1로 만들고 싶을 때
	// ^  : xor, 다르면 1, 같으면 0
	// >> : /2 (오른쪽으로 1bit 이동, 나누기 2)
	//    : a >> b ( a를 2의 b제곱만큼 나누어줌)
	// << : *2 (왼쪽으로 1bit 이동, 곱하기 2)
	//    : a << b ( a를 2의 b제곱만큼 나누어줌)

	//int a = 10;
	//int b = 12;
	//int c = 10 | 12; 
	//// 디버깅시 --> 변수, b 하면 이진수로 표현된다

	//// 그거아나, -1, b 디버깅하면 1계속 나옴.
	//int origin = 2135;
	//int bit = 0b000100000001; // 0으로 만들고 싶은 bit 선택
	//int step1 = -1 ^ bit;	  // bit의 1,0을 뒤집어
	//int step2 = origin & step1; // 이렇게 하면 bit에서 선택한 bit값 1이 0으로 바뀜

	/*int a = 65;
	int b = 123;
	int c = 213;

	int d = a ^ b ^ c ^ c ^ b;

	cout << d;*/

	/*int n = 1;
	for (int i = 0; i < 5; i++) {
		n <<= 1;
		cout << n << '\n';
	}
	for (int i = 0; i < 5; i++) {
		n >>= 1;
		cout << n << '\n';
	}*/

	//int a = 4865132; // <- 1의 개수
	//int temp = a;
	//int cnt = 0;
	//while (temp)
	//{
	//    if (temp & 1) // 1의 자리에 bit가 존재하는가?
	//    {
	//        cnt++;
	//    }
	//    temp = temp >> 1;
	//}

	int a = 4865132; // <- 연속해서 1이 있는경우가 몇 가지? ex) 0b 111 => 2가지
	int temp = a;
	int cnt = 0;
	while (temp)
	{
		if ((temp & 0b11) == 0b11) // 1의 자리에 bit가 존재하는가?
		{
			cnt++;
		}
		temp = temp >> 1;
	}

	return 0;

	return 0;
}