#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// C - 문자열(!!! null 값 반드시 포함 !!!)
	// 그래서 character 배열로 문자열 사용시 -> 크기는 넉넉하게 !!!
	char ch[3] = "AB";
	
	// C++ -  문자배열
	char ch[2] = { 'A', 'B' };

	// 기본 : 배열 -> 포인터. 배열의 이름은 첫번째 요소의 주소값
	int arr[] = { 1, 2, 3 };
	cout << arr << '\n';
	cout << &arr[0] << '\n';

	return 0;
}