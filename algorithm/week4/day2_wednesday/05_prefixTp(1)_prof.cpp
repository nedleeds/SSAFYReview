#include <iostream>
using namespace std;

// prefix sum
// 장점 : 구간합을 엄청 빠른속도로 처리
// 단점 : 배열에 변화가 없을떄만 사용 가능 (update -> segment tree)

// 배열 크기는 0부터 시작하되, 1번부터 입력 받을수 있도록
// 크기 = N + 1
int arr[100001];
int sumarr[100001];

int n, m;

int main() {
    cin >> n >> m;
    // 배열에 입력 받을떄 1번부터 받을것
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        // sumarr 구성 
        // sumarr[i] = i-1번째까지의 합 + 지금 i번째의 값
        sumarr[i] = sumarr[i - 1] + arr[i];
    }

    // solve 
    for (int i = 0; i < m; i++) {
        int st, en;
        cin >> st >> en;
        // st 부터 en까지의 구간합 
        // sumarr[en] - sumarr[st-1] 
        cout << sumarr[en] - sumarr[st - 1] << '\n';
    }
}