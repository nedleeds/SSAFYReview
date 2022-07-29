#include <iostream>
#include <stack>
using namespace std;

//stack

stack<int> s;

int main() {
	//// stack에 삽입
	//s.push(1);
	//s.push(3);

	//// stack의 맨 위 값 
	//cout << s.top() << '\n'; // 값: 3

	//// stack에 몇 개의 데이터가 있는가?
	//cout << s.size() << '\n'; // 2개
	//s.pop();

	//// stack이 비어있는가 ?? yes(true) / no(false)
	//cout << s.empty() << '\n'; // true(1 있으니깐)

	//// 스택의 맨 위에것을 삭제
	//// pop() -> return을 하지 않음 (삭제)
	//// 맨 위에것을 가져와서 사용 -> top()을 저장하고 삭제하세요
	//int cur = s.top();
	//s.pop();
	

	// problem 1. n개의 숫자를 입력받았을 때 역순으로 출력하시오.(stack 사용)
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s.push(num);
	}

	for (int j = 0; j < n; j++) {
		cout << s.top();
		s.pop();
	}
	// 바로 위 pop 부분은 아래와 같이 while과 empty로 가능.
	//while (!s.empty()) {
	//	cout << s.top() << " ";
	//	// 지금 맨 위에 있는 것을 삭제
	//	s.pop();
	//}


	return 0;
}