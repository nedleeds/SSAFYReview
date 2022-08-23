#include <iostream>
using namespace std;

// 대표 사용 문제
// --> cycle 검사 -> 순환회로 모든 
// --> 합쳐진다 / 그룹(DAT 또는 UF) 을 시킨다

// Union Find
// 성능을 올릴수 있는 방법이 2가지
// --> path compression (경로 압축)
//     --> 장점 : 속도가 비약적으로 빨라진다 O(N) -> O(a(N)) ->  O(logN)
//     --> 단점 : 연결 한번 하면 해제를 못함
// --> level by rank (할 필요가 없음)

// parent 세팅
int parent[10]; // parent[N] <-- 모든 노드의 번호를 담을수 있는 수

// Find : 어떤 회사의 대표를 찾아가는 함수
int Find(int node) {
    // 1. 내 자신이 대표일때
    if (node == parent[node]) {
        cout << "부모 찾음 : " << node << '\n';
        return node;
    }
    cout << "계속 찾아가는중 : " << parent[node] << "\n";
    // 2. 내가 대표가 아닐때
    return parent[node] = Find(parent[node]);
}

// Union : A와 B회사를 합병 
void Union(int a, int b) {
    // 일단 대표 찾아갑니다
    int pa = Find(a);
    int pb = Find(b);

    // 합병할려고 봤는데, 이미 같은 회사
    if (pa == pb)
        return;

    // ** 추가 코드 ** 
    // 합병시에 무슨일이 일어나야하는가? 
    // --> A사의 인원 + B사의 인원이 합쳐진다? 
    // --> 전쟁 : A와 B가 동맹 --> 인원 증가
    //          : A와 B가 전쟁 --> 멸망 

    cout << "합병 완료!" << '\n';
    // 아니면 한군데서 다른 하나를 흡수 합병
    parent[pb] = pa;
}

int main() {
    // parent를 초기화
    // 희망과 꿈을 가진 개별적인 스타트업의 상태로
    // 자기 자신이 회사의 대표로 임명 
    for (int i = 0; i < 10; i++)
        parent[i] = i;

    Union(1, 2);
    Union(3, 4);
    Union(2, 4);

    for (int i = 1; i <= 4; i++)
        cout << parent[i] << " ";

    // a와 b가 같은 그룹인가? 
    // parent[a] == parent[b] X
    // Find(a) == Find(b)     O 
}