#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// custom sort
// sort <-- nlogn

struct Node {
	int y;
	int x;
};

Node arr[4];

bool cmp(Node a, Node b) {
	// a: 왼쪽에 있는 값
	// b: 오른쪽에 있는 값
	// 상황에 맞게 return
	// 지금 이 a와 b를 봤을 때 -> 내가 원하는 정상적인 상황 -> true
	// 아니다. 지금 이건 바뀌어야한다 -> 잘못된 상황이다 -> false

    // y는 큰순 
    // 왼쪽 노드의 y값 > 오른쪽 노드의 y --> 정상적인 상태 
    if (a.y > b.y)
        return true;
    if (a.y < b.y)
        return false;

    // x는 작은순
    // 왼쪽 노드의 x값 < 오른쪽 노드의 x --> 정상적인 상태 
    if (a.x < b.x)
        return true;
    // 왼쪽 노드의 x값 > 오른쪽 노드의 x --> 비정상적인 상태 
    if (a.x > b.x)
        return false;

    // 맨 마지막에는 항상
    return false;
}

int main() {
    arr[0] = { 1, 1 };
    arr[1] = { 1, 100 };
    arr[2] = { 100, 1 };
    arr[3] = { 50, 50 };

    sort(arr, arr + 4, cmp);

    for (int i = 0; i < 4; i++) {
        cout << arr[i].y << " " << arr[i].x << "\n";
    }
}