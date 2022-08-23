#include <iostream>
using namespace std;

// ��ǥ ��� ����
// --> cycle �˻� -> ��ȯȸ�� ��� 
// --> �������� / �׷�(DAT �Ǵ� UF) �� ��Ų��

// Union Find
// ������ �ø��� �ִ� ����� 2����
// --> path compression (��� ����)
//     --> ���� : �ӵ��� ��������� �������� O(N) -> O(a(N)) ->  O(logN)
//     --> ���� : ���� �ѹ� �ϸ� ������ ����
// --> level by rank (�� �ʿ䰡 ����)

// parent ����
int parent[10]; // parent[N] <-- ��� ����� ��ȣ�� ������ �ִ� ��

// Find : � ȸ���� ��ǥ�� ã�ư��� �Լ�
int Find(int node) {
    // 1. �� �ڽ��� ��ǥ�϶�
    if (node == parent[node]) {
        cout << "�θ� ã�� : " << node << '\n';
        return node;
    }
    cout << "��� ã�ư����� : " << parent[node] << "\n";
    // 2. ���� ��ǥ�� �ƴҶ�
    return parent[node] = Find(parent[node]);
}

// Union : A�� Bȸ�縦 �պ� 
void Union(int a, int b) {
    // �ϴ� ��ǥ ã�ư��ϴ�
    int pa = Find(a);
    int pb = Find(b);

    // �պ��ҷ��� �ôµ�, �̹� ���� ȸ��
    if (pa == pb)
        return;

    // ** �߰� �ڵ� ** 
    // �պ��ÿ� �������� �Ͼ���ϴ°�? 
    // --> A���� �ο� + B���� �ο��� ��������? 
    // --> ���� : A�� B�� ���� --> �ο� ����
    //          : A�� B�� ���� --> ��� 

    cout << "�պ� �Ϸ�!" << '\n';
    // �ƴϸ� �ѱ����� �ٸ� �ϳ��� ��� �պ�
    parent[pb] = pa;
}

int main() {
    // parent�� �ʱ�ȭ
    // ����� ���� ���� �������� ��ŸƮ���� ���·�
    // �ڱ� �ڽ��� ȸ���� ��ǥ�� �Ӹ� 
    for (int i = 0; i < 10; i++)
        parent[i] = i;

    Union(1, 2);
    Union(3, 4);
    Union(2, 4);

    for (int i = 1; i <= 4; i++)
        cout << parent[i] << " ";

    // a�� b�� ���� �׷��ΰ�? 
    // parent[a] == parent[b] X
    // Find(a) == Find(b)     O 
}