#include <iostream>
using namespace std;

// 재귀 
// 다시 재, 돌아올 귀 -> 다시 돌아오다
// CS : 재귀 함수 -> 다시 돌아오는 함수
// 정의 1 : 함수가 자기 자신을 호출하는 것. 
// 특징 1 : 모든 재귀 == 모두 반복문 "***이론상으로***"
// 구성 : 
// 1. 재귀 구성 -> 어떻게 다시 내 함수로 들어갈 것이냐? 
// 2. 기저 조건 -> 언제 끝낼것이냐? 

// 장점 : elegant 하다.
// 단점 : 어렵다...

void hello(int i) {
    // 2. 기저 조건
    if (i == 5)
        return; 

    // 1. 재귀 구성
    cout << "hello\n";
    hello(i+1); 
}

int main() {
    
    // hello 5번 출력
    //int i = 0;
    //while (true) {
    //    if (i == 5)
    //        break; 
    //    cout << "hello\n";
    //    i++; // 1 2 3 4 5 
    //}

    hello(0);

    return 0; 
}