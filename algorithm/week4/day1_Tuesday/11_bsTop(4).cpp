#include <iostream>
using namespace std;

int n; // �򷯽��� ���� 
int k; // ���� ���� (��� �����ؾ� �ϴ°�?) 
int arr[100001];
int len = -2134567890;

// �򷯽��� ���� ��� 2147----- 

long long  psearch() {
    // 1. left right ����
    long long left = 1;  // ����� �ִ� �򷯽��� �ּ� ���� 
    long long  right = len; // ����� �ִ� �򷯽��� �ִ� ����
    long long ans = 0;

    // 2. �̸����ϴµ��� �����鼭 
    while (left <= right) {
        // 3. ����
        // mid : �� ���̰� �����̴� ! -> ���� 
        long long mid = (left + right) / 2;

        // �� ���̷� ��� ������ �� �� �ִ����� Ȯ��
        long long cnt = 0;
        // ��� �򷯽��� ���� ���� ���� �����̶�� ������ ũ�⸸ŭ���� ��������
        // ���⼭ ���ü� �ִ� �� = ������ ���̷� ������ �ִ� ���ҵ� �򷯽��� ��
        for (int i = 0; i < n; i++)
            cnt += arr[i] / mid;

        // cnt�� �������� ���⼺�� Ȯ��
        // --> 
        if (cnt >= k) {
            // k����ŭ ����������ϱ� -> ���ɼ��� ã�Ҵ�! 
            ans = mid;
            // ���� ã���� �ϴ� ��ǥ�� ���⼺�� ���� �̵�
            // --> �� �� �򷯽��� ����� �ִ°�? 
            left = mid + 1;
        }
        // k����ŭ �ȸ��������! 
        else
            // �򷯽��� �� �߰� �߶�����Ѵ�!
            right = mid - 1;
    }
    return ans;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        // �ִ� �򷯽��� ����
        if (arr[i] > len)
            len = arr[i];
    }

    // ������ ������ (�����̶�� �����Ͽ� --> �߶󺸰� --> ���ɼ��� Ȯ��) 
    long long ans = psearch();
    cout << ans;

    // int 21��
    // long long 9,000,000,000,000,000,000
}