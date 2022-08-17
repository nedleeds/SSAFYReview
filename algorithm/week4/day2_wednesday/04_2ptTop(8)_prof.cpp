#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 메모리 
int A[4001];
int B[4001];
int C[4001];
int D[4001];

int n;

// 4000 x 4000 = 1600만개
vector<int>AB; // A+B의 모든 조합 
vector<int>CD; // C+D의 모든 조합 

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    // AB와 CD조합으로 두개의 배열 완성 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    // Two Pointer탐색 
    // 정렬 
    // 시간복잡도 : O(NlogN) --> 1600만logbase21600만 --> 3억6천8백만
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    // NlogN

    int len = CD.size();

    // 범위 설정
    int left = 0; // 한 배열의 첫번째 index 
    int right = len - 1; // 한 배열의 마지막 index

    // ** 합은 항상 정수 범위내 -> 문제에서 주어짐
    // ** 경우의 수는 엄청 많을수도 있음 
    long long cnt = 0;

    // O(NxN)
    while (left < len && right >= 0) {
        int sum = AB[left] + CD[right];

        // sum == 0
        if (sum == 0) {
            // 중복되는 값이 매우 많을수 있습니다. 
            // 이 값들을 어디서부터 어디까지가 지금 left가 가리키고 있는 값이고, 
            // 어디서부터 어디까지가 지금 right가 가리키는 값인지를 찾아 줘야 함 
            int ab = AB[left];// left가 가리키고 있는 값
            int cd = CD[right]; // right가 가리키고 있는 값

            long long acnt = 0;
            long long bcnt = 0;

            // AB -> 지금 가리키는 ab랑 같은 값일동안 계속해서 left++ 
            while (left < len && AB[left] == ab) {
                left++;
                acnt++;
            }

            // CD -> 지금 가리키는 cd와 같은 값일동안 계속해서 right-- 
            while (right >= 0 && CD[right] == cd) {
                right--;
                bcnt++;
            }
            // 누적 
            cnt += acnt * bcnt;
        }
        // sum > 0 
        // --> right 포인터가 가리키는 값이 너~무 크다
        else if (sum > 0) {
            right--;
        }
        // sum < 0 
        // --> left 포인터가 가리키는 값이 너~무 작다
        else if (sum < 0) {
            left++;
        }
    }
    cout << cnt;
}