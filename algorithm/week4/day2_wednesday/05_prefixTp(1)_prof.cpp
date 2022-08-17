#include <iostream>
using namespace std;

// prefix sum
// ���� : �������� ��û �����ӵ��� ó��
// ���� : �迭�� ��ȭ�� �������� ��� ���� (update -> segment tree)

// �迭 ũ��� 0���� �����ϵ�, 1������ �Է� ������ �ֵ���
// ũ�� = N + 1
int arr[100001];
int sumarr[100001];

int n, m;

int main() {
    cin >> n >> m;
    // �迭�� �Է� ������ 1������ ������
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        // sumarr ���� 
        // sumarr[i] = i-1��°������ �� + ���� i��°�� ��
        sumarr[i] = sumarr[i - 1] + arr[i];
    }

    // solve 
    for (int i = 0; i < m; i++) {
        int st, en;
        cin >> st >> en;
        // st ���� en������ ������ 
        // sumarr[en] - sumarr[st-1] 
        cout << sumarr[en] - sumarr[st - 1] << '\n';
    }
}