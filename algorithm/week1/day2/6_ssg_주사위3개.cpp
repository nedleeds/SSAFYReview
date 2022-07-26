#include <iostream>
using namespace std;

// path -> DAT
// index : 층 번호
// value : 내가 현재 층에서 다음 층으로 내려가기 위해 "선택한 경로"

int choice[] = {1, 2, 3, 4, 5, 6};
int path[10];

// level : 층 -> 어느 층까지 도달해야 종료되는가? 
// 주사위를 3번 던지니깐 3층까지.
void func(int level) {
        // 기저 조건 
        if (level == 3) {
            // cout << "RETURN\n";

            // 최종 레벨에 도달했다면 -> 지금까지의 choice를 출력
            for (int i = 0; i < 3; i++) {
                cout << path[i];
            }
            cout << '\n';
            return;
        }

        // 재귀 구성
        // 반복문 -> 가지의 개수
        /*
        for (int i = 0; i < 2; i++)
            func(level + 1);
        */
        for (int i = 0; i < 6; i++) {
            // 지금 층에서 선택하는 경로 -> path에 저장
            // 다음 choice에 들어갈때 선택 
            // 현재의 choice 는 현재 주사위 값 (choice[i])
            path[level] = choice[i]; 

            func(level + 1); 

            // 해당 경로를 나올때 -> 초이스를 해제
            path[level] = 0; 
        }
}

int main() {
    func(0); 
}