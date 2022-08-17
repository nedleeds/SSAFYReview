// 9:00 ~ 9:44 ( bsTop(6) 문제 )
// 9:44 ~ 10:05 ( bsTop(6) 설명 )
#include <iostream>
using namespace std;

int n, t;
int arr[501];
int maxval = -1;
int total = 0;

int maketeam(int val) {
    // val로 몇개의 팀을 만들수있는가? --> 이 val로 만들수 있는 "최소" 팀 개수는 몇개인가? 
    int ans = 2134567890;

    // 누구를 기준으로 시작할것인가?
    for (int i = 0; i < n; i++) {
        // 이 시작 인간으로부터 팀 꾸려보기 
        int sum = 0; // 지능 합 : 한 팀의 현재 합을 
        int cnt = 1; // <-- 무조건 한팀은 만들어지니 1부터 시작 
        for (int j = i; j < i + n; j++) {
            // 조건: 언제까지가 한 팀일까? 
            // 만약 지금 팀의 현재까지의 지능합에 다음 사람을 포함시켰을떄 
            // -> 우리가 정답으로 가정하고있는 headsum의 값을 넘어가지 않는다면
            if (sum + arr[j % n] <= val) {
                // 이 팀에 일원이 된다 (j번 사람이)
                sum += arr[j % n];
            }
            // 지금 이 사람이 이 팀에 합류하면 --> 팀이 터진다! (합이 넘어간다!
            else {
                // 새로운 팀 구성
                sum = arr[j % n]; // 이 사람부터 새로운 팀이 시작!
                cnt++; // 팀이 하나 늘었다!
            }
        }
        // i를 기준으로 팀 만들기 완료
        // 새로운 최소 팀의 개수를 찾으면 갱신
        if (cnt < ans)
            ans = cnt;
    }
    return ans;
}

int psearch() {
    // 1. left와 right 설정
    int left = maxval; // 최소 headsum
    int right = total; // 최대 headsum
    int ans = 0;

    // 2. parametric search 
    while (left <= right) {
        // mid : 이 점수가 정답이다! 라는것 가정 --> 이 점수로 내가 원하는 t개의 팀을 만들수 있나? 
        int mid = (left + right) / 2;

        // mid를 가지고 t개의 팀을 만들어 봅니다. 
        int cnt = maketeam(mid);

        // 방향 설정 -> 지금 문제에서 원하는것? --> mid을 최소화 --> 더 작은 mid로 t개를 만들수있는가? 
        // == < > 
        if (cnt <= t) {
            // 가능성 확인! 
            ans = mid;
            // 더 낮은 기준 지능으로 t개의 팀을 만들수 있는지 보자!
            right = mid - 1;
        }
        // 너무 많은 팀이 만들어졌다 -> 지금 기준 지능이 너무 낮다
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

    // 사람 입력
    // 범위 설정 할떄 -> 최소 headsum 최대 headsum 
    // 최소 headsum : T = 1 -> 지금 입력받는 사람들중 가장 지능이 높은 것 
    // 최대 headsum : T = N -> 지금 이 사람들의 전체 합 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        // 최소 headsum 
        if (arr[i] > maxval)
            maxval = arr[i];
        // 최대 headsum
        total += arr[i];
    }
    // cout << maxval << " " << total;
    int ans = psearch();
    cout << ans;
}