#include <iostream>
using namespace std;

int n; // 츄러스의 개수 
int k; // 분할 개수 (몇개로 분할해야 하는가?) 
int arr[100001];
int len = -2134567890;

// 츄러스의 값이 모두 2147----- 

long long  psearch() {
    // 1. left right 세팅
    long long left = 1;  // 만들수 있는 츄러스의 최소 길이 
    long long  right = len; // 만들수 있는 츄러스의 최대 길이
    long long ans = 0;

    // 2. 이름값하는동안 돌리면서 
    while (left <= right) {
        // 3. 수행
        // mid : 이 길이가 정답이다 ! -> 가정 
        long long mid = (left + right) / 2;

        // 이 길이로 몇개의 분할을 할 수 있는지를 확인
        long long cnt = 0;
        // 모든 츄러스를 지금 내가 정한 정답이라고 가정한 크기만큼으로 나눴을떄
        // 여기서 나올수 있는 몫 = 지금의 길이로 만들어낼수 있는 분할된 츄러스의 수
        for (int i = 0; i < n; i++)
            cnt += arr[i] / mid;

        // cnt를 기준으로 방향성을 확인
        // --> 
        if (cnt >= k) {
            // k개만큼 만들어졌으니까 -> 가능성을 찾았다! 
            ans = mid;
            // 저희가 찾고자 하는 목표의 방향성에 따라 이동
            // --> 더 긴 츄러스를 만들수 있는가? 
            left = mid + 1;
        }
        // k개만큼 안만들어진다! 
        else
            // 츄러스를 더 잘게 잘라봐야한다!
            right = mid - 1;
    }
    return ans;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        // 최대 츄러스의 길이
        if (arr[i] > len)
            len = arr[i];
    }

    // 기준을 가지고 (정답이라는 가정하에 --> 잘라보고 --> 가능성을 확인) 
    long long ans = psearch();
    cout << ans;

    // int 21억
    // long long 9,000,000,000,000,000,000
}