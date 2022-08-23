//#include <iostream>
//#include <vector>
//using namespace std;
//
//int t; // 충전기의 개수
//int n; // 차의 개수
//
//int parent[100001]; 
//
//int Find(int node) {
//    if (node == parent[node])
//        return node;
//    return parent[node] = Find(parent[node]);
//}
//
//void Union(int a, int b) {
//    int pa = Find(a);
//    int pb = Find(b);
//    if (pa == pb)
//        return;
//    parent[pb] = pa; 
//}
//
//int main() {
//    cin >> t;
//    cin >> n; 
//
//    // parent setting
//    // 버젼이 있는 만큼 parent setting
//    for (int i = 0; i <= t; i++)
//        parent[i] = i; 
//
//    int cnt = 0; 
//    for (int i = 0; i < n; i++) {
//        int car;
//        cin >> car;
//        // 지금 들어온 차가 어디에 연결될수 있는가? 
//        // Find -> 지금 충전기가 차선책으로 passing할수 있는 다른 충전기에 연결됬는가? 
//        int charger = Find(car); 
//        // 만약 더이상 연결할수 있는 하위호환 충전기가 없다면 -> 종료
//        if (charger == 0)
//            break; // 이 차부터는 더 연결할수 없다
//        // -------------------------------------
//        // 이 차는 도킹이 어딘가에는 일단 가능하다! 
//        cnt++; // 차 하나를 더 충전할 수 있다!
//        // 이제, 지금 얘가 연결된 충전기는 사용할 수 X 
//        // 이거보다 낮은 버젼의 충전기중 비어있는곳이 있다면 -> 여기로 passing하도록 연결
//        // 만약 없다면 (이 아래의 충전기들이 모두 차있다면)--> 0번으로 연결이 된다. 
//        Union(charger - 1, charger); 
//    }
//    cout << cnt;
//}
//
//// 이 코드는 시간 초과 뜸
////int used[100001];
////int arrived[100001];
////vector<int> charger;
////
////int main() {
////	ios_base::sync_with_stdio(false);
////	cin.tie();
////	cout.tie();
////
////	int numCharger;
////	cin >> numCharger;
////
////	for (int i = 1; i < numCharger; i++) {
////		charger.push_back(i);
////	}
////
////	int carNum;
////	cin >> carNum;
////
////	int possible = 0;
////	for (int i = 0; i < carNum; i++) {
////		int car;
////		cin >> car; // 차가 들어왔다
////
////		int flag = false;
////
////		for (int charger = numCharger; charger > 0; charger--) { // 모든 충전소 탐색
////			if (used[charger] == 0 && charger <= car) { // 미사용 + 차 버전과 호환
////				//v.erase(remove(v.begin(), v.end(), 3), v.end());
////				used[charger] = 1;
////				possible++;
////				flag = true;
////				break;
////			}
////		}
////		if (flag == false) {
////			cout << possible;
////			return 0;
////		}
////	}
////
////
////	return 0;
////}
///*
//[ PineApple의 전기 차 ]
//1. 낮은 버젼의 차량은 높은 버젼의 차량의 충전기가 호환되지 않는다.
//2. 충전이 완료되기까지는 매우 오랜 시간이 걸린다.
//3. 갈 수 있는 충전소가 없는 경우 교통이 막혀 이후의 모든 차량은 충전기에 연결할 수 없다.
//
//PineApple Car 1은 PineApple Car 2 또는 3의 충전기를 사용할 수 없다.
//하지만 반대로 높은 버젼의 차량은 낮은 버젼의 충전기를 사용할 수 있다.
//PineApple Car 3은 PineApple Car 1 또는 2의 충전기를 사용할 수 있다.
//* 차-> 오름차순 -> 낮은 버전은 무조건 본인한테 맞춰야하기 때문
//
//충전소에서는 항상 차량과 동일 버젼의 충전기에 먼저 충전을 시도
//
//A지역의 충전소에는 G개의 충전기
//1번부터 G버젼까지의 충전기가 하나씩 비치
//
//첫 차부터 충전을 위해 충전기에 도킹
//동일한 버젼의 충전기에 도킹할 수 없다면, 하위 버젼의 충전기에 도킹을 시도
//충전이 가능한 충전기가 남아있지 않은 경우,
//남아있는 차들은 앞에 도킹된 차들의 충전 시간을 기다릴 수 없어 다음 충전소를 향해 이동
//
//A지역의 정보가 주어졌을 때, 충전이 가능한 최대 전기차의 수를 구하는 프로그램을 작성
//[1][2][3][4] -> c1 + c4
//		  c4
// c1
// c1
// [ 1 ][ 2 ][ 3 ][ 4 ] -> c2 + c3 + c4
//  c4   c2    c3   c4
//	   c2    c3
//*/