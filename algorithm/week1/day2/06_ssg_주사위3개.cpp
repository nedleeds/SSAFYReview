#include <iostream>
using namespace std;

// 문제
// 3개의 주사위를 굴려서 나올 수 있는 모든 눈금 조합을 출력
// 단, 조합은 작은순 부터
// 예) 111 112 113 114 115 116 121.... 666

// SSG -> 층이 몇개인가? branch가 몇개인가? 
// path의 크기는 어떻게 설정해야하는가? 

// 모든 조합을 구하는 문제 

// branch : 1~6 (총 6개, 주사위의 눈금의 수 -> 경우의 수)
// level : 3개 (주사위의 수)

// path
int path[10];

void func(int level) {
    // 기저조건
    if (level == 3) {
        // path에 기록된 여태까지 레벨의 나의 결정들을 출력 (경로출력)
        for (int i = 0; i < 3; i++) {
            cout << path[i];
        }
        cout << '\n';
        return;
    }

    // 재귀 구성
    // 다음 층으로 내려가는 경로 = 6 
    for (int i = 1; i <= 6; i++) {

        // 들어가면서 : 지금 층에서 다음층으로 갈떄의 선택 기록
        path[level] = i;

        func(level + 1);

        // 나오면서 : 위 층에서 선택한 기록을 해제
        path[level] = 0;
    }
}

int main() {
    // 0 level에서 시작!
    func(0);
}