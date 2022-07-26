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

/// <summary>
/// DFS + Backtracking + simulation --> 코테 80%
/// BFS + floodfill --> 10%
/// 나머지 알고리즘 --> 10%

void problem1(int i) {
    // 2. 기저 조건
    if (i == 10) {
        cout << "\n";
        return;
    }

    // 1. 재귀 구성
    cout << i+1 << " ";
    problem1(i+1);
}

int problem2(int i, int s) {
    // 2. 기저 조건
    if (i == 0) {
        return s;
    }

    // 1. 재귀 구성
    return problem2(i - 1, s+i);
}


void problem3(int value, int check) {
 
    // 2. 기저 조건
    if (value == check) {
        cout << value << " ";
        return ;
    }

    // 1. 재귀 구성
    cout << value << " ";
    problem3(value + 1, check);
    cout << value << " ";

    
}

int main() {
    
    // 문제 -> 재귀 
    // 문제1. 1~10까지 출력하는 프로그램 

    // 문제2. n을 입력받고, 1~n까지의 합을 출력하는 프로그램\
    // --> 재귀에서 꼭 return X

    // 문제3. n을 입력받고 1~n~1 
    // input : 5 
    // output : 1 2 3 4 5
    problem1(0);

    int n, s=0;
    cin >> n;
    s = problem2(n, s);
    cout << s << "\n";
    
    int check, start = 1;
    cin >> check;
    problem3(start, check);

    

    return 0; 
}