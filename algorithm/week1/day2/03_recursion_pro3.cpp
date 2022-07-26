#include <iostream>
using namespace std;

// path -> DAT
// index : 층 번호
// value : 내가 현재 층에서 다음 층으로 내려가기 위해 "선택한 경로"


int path[10];
int branch, lvl;
int cnt = 0;

// level : 층 -> 어느 층까지 도달해야 종료되는가? 
// 주사위를 3번 던지니깐 3층까지.
void func(int level) {
    cnt++;

    // 기저 조건 
    if (level == lvl) {
        return ;
    }

    // 재귀 구성
    for (int i = 0; i < branch; i++) {
        func(level + 1);
    }
}

int main() {
    cin >> branch >> lvl;
    func(0);
    cout << cnt << "\n";
}