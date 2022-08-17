// 9:00 ~ 9:44 ( bsTop(6) ���� )
// 9:44 ~ 10:05 ( bsTop(6) ���� )
#include <iostream>
using namespace std;

int n, t;
int arr[501];
int maxval = -1;
int total = 0;

int maketeam(int val) {
    // val�� ��� ���� ������ִ°�? --> �� val�� ����� �ִ� "�ּ�" �� ������ ��ΰ�? 
    int ans = 2134567890;

    // ������ �������� �����Ұ��ΰ�?
    for (int i = 0; i < n; i++) {
        // �� ���� �ΰ����κ��� �� �ٷ����� 
        int sum = 0; // ���� �� : �� ���� ���� ���� 
        int cnt = 1; // <-- ������ ������ ��������� 1���� ���� 
        for (int j = i; j < i + n; j++) {
            // ����: ���������� �� ���ϱ�? 
            // ���� ���� ���� ��������� �����տ� ���� ����� ���Խ������� 
            // -> �츮�� �������� �����ϰ��ִ� headsum�� ���� �Ѿ�� �ʴ´ٸ�
            if (sum + arr[j % n] <= val) {
                // �� ���� �Ͽ��� �ȴ� (j�� �����)
                sum += arr[j % n];
            }
            // ���� �� ����� �� ���� �շ��ϸ� --> ���� ������! (���� �Ѿ��!
            else {
                // ���ο� �� ����
                sum = arr[j % n]; // �� ������� ���ο� ���� ����!
                cnt++; // ���� �ϳ� �þ���!
            }
        }
        // i�� �������� �� ����� �Ϸ�
        // ���ο� �ּ� ���� ������ ã���� ����
        if (cnt < ans)
            ans = cnt;
    }
    return ans;
}

int psearch() {
    // 1. left�� right ����
    int left = maxval; // �ּ� headsum
    int right = total; // �ִ� headsum
    int ans = 0;

    // 2. parametric search 
    while (left <= right) {
        // mid : �� ������ �����̴�! ��°� ���� --> �� ������ ���� ���ϴ� t���� ���� ����� �ֳ�? 
        int mid = (left + right) / 2;

        // mid�� ������ t���� ���� ����� ���ϴ�. 
        int cnt = maketeam(mid);

        // ���� ���� -> ���� �������� ���ϴ°�? --> mid�� �ּ�ȭ --> �� ���� mid�� t���� ������ִ°�? 
        // == < > 
        if (cnt <= t) {
            // ���ɼ� Ȯ��! 
            ans = mid;
            // �� ���� ���� �������� t���� ���� ����� �ִ��� ����!
            right = mid - 1;
        }
        // �ʹ� ���� ���� ��������� -> ���� ���� ������ �ʹ� ����
        else if (cnt > t) {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n >> t;

    // ��� �Է�
    // ���� ���� �ҋ� -> �ּ� headsum �ִ� headsum 
    // �ּ� headsum : T = 1 -> ���� �Է¹޴� ������� ���� ������ ���� �� 
    // �ִ� headsum : T = N -> ���� �� ������� ��ü �� 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        // �ּ� headsum 
        if (arr[i] > maxval)
            maxval = arr[i];
        // �ִ� headsum
        total += arr[i];
    }
    // cout << maxval << " " << total;
    int ans = psearch();
    cout << ans;
}