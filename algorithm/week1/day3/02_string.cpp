#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// C's string -> "" : null included
	// considering with this, 
	// you need to make the size big enough
	char ch[3] = "AB";
	
	// C++ - character array : no null
	char ch[2] = { 'A', 'B' };

	//기본 : 배열 -> 포인터. 배열의 이름은 첫번째 요소의 주소값
	int arr[] = { 1, 2, 3 };
	cout << arr << '\n';
	cout << &arr[0] << '\n';

	return 0;
}