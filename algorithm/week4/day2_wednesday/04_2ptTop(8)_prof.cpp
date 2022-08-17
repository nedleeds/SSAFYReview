#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// �޸� 
int A[4001];
int B[4001];
int C[4001];
int D[4001];

int n;

// 4000 x 4000 = 1600����
vector<int>AB; // A+B�� ��� ���� 
vector<int>CD; // C+D�� ��� ���� 

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    // AB�� CD�������� �ΰ��� �迭 �ϼ� 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    // Two PointerŽ�� 
    // ���� 
    // �ð����⵵ : O(NlogN) --> 1600��logbase21600�� --> 3��6õ8�鸸
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    // NlogN

    int len = CD.size();

    // ���� ����
    int left = 0; // �� �迭�� ù��° index 
    int right = len - 1; // �� �迭�� ������ index

    // ** ���� �׻� ���� ������ -> �������� �־���
    // ** ����� ���� ��û �������� ���� 
    long long cnt = 0;

    // O(NxN)
    while (left < len && right >= 0) {
        int sum = AB[left] + CD[right];

        // sum == 0
        if (sum == 0) {
            // �ߺ��Ǵ� ���� �ſ� ������ �ֽ��ϴ�. 
            // �� ������ ��𼭺��� �������� ���� left�� ����Ű�� �ִ� ���̰�, 
            // ��𼭺��� �������� ���� right�� ����Ű�� �������� ã�� ��� �� 
            int ab = AB[left];// left�� ����Ű�� �ִ� ��
            int cd = CD[right]; // right�� ����Ű�� �ִ� ��

            long long acnt = 0;
            long long bcnt = 0;

            // AB -> ���� ����Ű�� ab�� ���� ���ϵ��� ����ؼ� left++ 
            while (left < len && AB[left] == ab) {
                left++;
                acnt++;
            }

            // CD -> ���� ����Ű�� cd�� ���� ���ϵ��� ����ؼ� right-- 
            while (right >= 0 && CD[right] == cd) {
                right--;
                bcnt++;
            }
            // ���� 
            cnt += acnt * bcnt;
        }
        // sum > 0 
        // --> right �����Ͱ� ����Ű�� ���� ��~�� ũ��
        else if (sum > 0) {
            right--;
        }
        // sum < 0 
        // --> left �����Ͱ� ����Ű�� ���� ��~�� �۴�
        else if (sum < 0) {
            left++;
        }
    }
    cout << cnt;
}