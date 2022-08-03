#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// sort
// 정렬 알고리즘 진짜 많다 !!
// 버블 정렬, 삽입 정렬, 선택 정렬 --> 효율 나쁜 정렬 --> n^2
// 병합 정렬, 퀵소트 --> 효율 좋은 정렬 --> nlogn

// stl에서 제공하는 sort --> 아주 안정적으로 nlogn

// 우리가 쓸 C++에서의 sort 알고리즘
// BASE : Intro Sort + Quicksort + Heap sort
// Quicksort -> nlogn을 넘어가면 heap sort로 전환
// 배열의 크기가 너무 크다 -> Intro sort

int arr[] = { 3, 4, 5, 1, 2 };
vector<int> v = { 3, 4, 5, 1, 2 };
char c[] = { 'A' , 'B', 'D', 'F', 'Z' };

bool cmp(int a, int b) {
	// a: 왼쪽에 있는 값
	// b: 오른쪽에 있는 값
	// 상황에 맞게 return
	// 지금 이 a와 b를 봤을 때 -> 내가 원하는 정상적인 상황 -> true
	// 아니다. 지금 이건 바뀌어야한다 -> 잘못된 상황이다 -> false

	if (a > b) // 왼쪽이 오른쪽이 더 크다 --> 정상 내림차순.
	{
		return true;
	} 
	// ** 주의 ** 
	// 항상 반대 상황들도 같이 넣어야 한다 !
	// 내림차순에 어긋나는 상황
	if (a < b) {
		return false;
	}

	// 두 조건이 아니면 false
	return false;
}

int main() {
	// 정렬 -> algorithm 라이브러리 불러온다!!!
	
	// 1. 오름차순
	// sort(포인터, 포인터) 
	// -> sort(배열 이름, 배열 이름 + 배열 크기) 
	// -> sort(첫번째 요소의 주소값, 마지막 요소의 주소값)
	sort(arr, arr + 5);
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';

	cout << '\n';
	// 벡터 소팅 -> sort(벡터의 시작, 벡터의 끝)
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	// 문자열
	cout << '\n';
	sort(c, c + 5);
	for (int i = 0; i < 5; i++)
		cout << c[i] << " ";

	// 2. 내림차순
	// sort(포인터, 포인터, 함수 포인터) 
	// -> sort(첫번째 요소의 주소값, 마지막 요소의 주소값, 정렬 기준 함수)
	cout << '\n';
	sort(arr, arr + 5, cmp);
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';

	cout << '\n';
	// 벡터 소팅 -> sort(벡터의 시작, 벡터의 끝)
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	// 문자열
	cout << '\n';
	sort(c, c + 5, cmp);
	for (int i = 0; i < 5; i++)
		cout << c[i] << " ";

	return 0;
}