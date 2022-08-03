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
	// a: ���ʿ� �ִ� ��
	// b: �����ʿ� �ִ� ��
	// ��Ȳ�� �°� return
	// ���� �� a�� b�� ���� �� -> ���� ���ϴ� �������� ��Ȳ -> true
	// �ƴϴ�. ���� �̰� �ٲ����Ѵ� -> �߸��� ��Ȳ�̴� -> false

    // y�� ū�� 
    // ���� ����� y�� > ������ ����� y --> �������� ���� 
    if (a.y > b.y)
        return true;
    if (a.y < b.y)
        return false;

    // x�� ������
    // ���� ����� x�� < ������ ����� x --> �������� ���� 
    if (a.x < b.x)
        return true;
    // ���� ����� x�� > ������ ����� x --> ���������� ���� 
    if (a.x > b.x)
        return false;

    // �� ���������� �׻�
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