#include <iostream>
#include <vector>
using namespace std;
// 그래프 data를 전역 변수 <- 모든 함수에서 공통적으로 볼 수 있도록
int arr[10][10] = { 0, }; // -> arr[2][????]   arr[2][to] : 2에서 to로 갈 수 있는가?
int cntNode;
vector<int> v[10];
//void dfsArray(int now) { // 지금 now라는 node에 있다.
//
//	//if (끝날 조건) // 기저 조건(필수 X, option)
//	//{
//	//	return;
//	//}
//
//	cout << now << " ";
//
//	// now에서 갈 수 있는 next라는 node로 가라!
//	// arr[now][?????????] == 1
//	// 특정 node에서 갈 수 있는 node 찾기
//	for (int next = 1; next <= cntNode; next++)
//	{
//		// 가지치기 : 가능성이 없으면, 잘못된 것은 할 필요 없다.
//		if (arr[now][next] == 0 ) // now->next로 갈 수 없는가?
//			continue; // 갈 수 없으면 무시
//
//		dfsArray(next);
//	}
//}
// 인접 리스트로 DFS해보기!!!!!
/*
5   <-node개수
1 2 <-parent child
1 3
2 4
2 5
*/
// 인접 리스트 방식
//void dfsVector(int now)
//{
//	cout << now << " ";
//
//	// now->next찾기
//	// 특정 node에서 갈 수 있는 node 찾기
//	for (int i = 0; i < v[now].size(); i++)
//	{
//		int next = v[now][i];
//		dfsVector(next);
//	}
//}
// 2. - 1)
// B라는 점을 갈 수 있는가? -> dfs2를 통해서 B를 들리는가? 
//int ans = 0;
//int B;
//void dfs2(int now)
//{
//	if (now == B) // B가 끝점이라고 생각해도 괜찮음
//	{
//		ans = 1;
//		return;
//	}
//
//	for (int next = 1; next <= cntNode; next++)
//	{
//		if (arr[now][next] == 0) continue; // now->next로 갈 수 없으면 무시
//
//		// now->next로 갈 수 있음
//		dfs2(next);
//	}
//}
// 2. - 2)
// 내가 어떤 점들을 들렸는가를 기록
//int used[100] = {0, };
////index : 점 번호
////value : 들렸는가?
//
//void dfs2(int now)
//{
//	for (int next = 1; next <= cntNode; next++)
//	{
//		if (arr[now][next] == 0) continue;
//
//		used[next] = 1; // next라는 점을 들린다.
//		dfs2(next);
//	}
//}
// 2. -3)
// 지금 내가 어떤 경로로 이동중인가?
//vector<int> path; // 현재 경로를 기록
//void dfs2(int now)
//{
//	for (int next = 1; next <= cntNode; next++)
//	{
//		if (arr[now][next] == 0) continue;
//		path.push_back(next); // next로 갈거니까 next도 경로에 추가해라.
//		dfs2(next);
//		path.pop_back(); // vector.pop_back() : vector의 맨 뒤에 있는 data를 삭제, 공간도 지움
//	}
//}
// 2. -4)
// used와 path를 합치기
// 지금 경로 : path
// used <- path와 알맞게 갱신
// 1-> 2 -> 5
//1 2 3 4 5 6 7
//1 1     1
//vector<int> path;
//int used[10] = { 0, };
//// index : node번호, value : 해당 점을 들렸는가?
//
//
//void dfs2(int now)
//{
//	// ---------------- 
//	// 끝나는 것에 대한 처리
//	// 기저조건
//	/*
//	if(~~~~~~){
//		끝나면서 무언가 처리
//		return;
//	}
//	*/
//
//	for (int next = 1; next <= cntNode; next++)
//	{
//		// ---------------- 
//		// 1.가지치기
//		// 애초에 갈 수 없다면(가치지기가 가능)
//		if (arr[now][next] == 0) continue;
//
//		//------------------
//		// now->next로 갈때 무언가 처리, 기록
//		used[next] = 1; // next라는 점을 들린다!
//		path.push_back(next); // next로 가니까 path에 추가
//		
//		// -----------------
//		// 2.가지치기
//		// 어떤 계산을 한 후에야 가지치기
//
//		//------------------
//		dfs2(next); // next로 가라!
//
//		//------------------
//		// next로 갔다온 후(next는 끝남)
//		// now->next로 갔다왔으니 기록을 지우거나 복구(초기화)
//		path.pop_back();
//		used[next] = 0;
//	}
//}
// 3. 무방향에서 무한 재귀가 발생하지 않도록 used로 처리
//int used[10] = {0, };
//void dfs3(int now)
//{
//	cout << now << " ";
//	for (int next = 1; next <= cntNode; next++)
//	{
//		if (arr[now][next] == 0) continue;
//
//		// next로 가려고 봤더니 내가 기록하기도 전에 이미 기록이 있으면 무시 -> 갔던 점
//		if (used[next] == 1) continue; 
//
//		used[next] = 1; //next로 간다.
//		dfs3(next);
//	}
//}
// 3. - 1) 1->
int used[10] = { 0, };
vector<int> path;// <- 현재 경로를 기록
void dfs3(int now)
{
	if (now == 5) // 5까지 왔을 때, 경로(5가 끝점)
	{
		for (int i = 0; i < path.size(); i++)
			cout << path[i] << " ";
		cout << "\n";
		return;
	}
	// cout << now << " ";
	for (int next = 1; next <= cntNode; next++)
	{
		if (arr[now][next] == 0) continue;
		// next로 가려고 봤더니 내가 기록하기도 전에 이미 기록이 있으면 무시 -> 갔던 점
		if (used[next] == 1) continue;
		used[next] = 1; //next로 간다.
		path.push_back(next);
		dfs3(next);
		path.pop_back();
		used[next] = 0;
	}
}
//1 -> 2
//1 -> 3 -> 4 -> 5
// now에서 갈 수 있는 next는 어떤 data들을 확인하면 알 수 있을까요??????
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	/*
	5
	1 2
	1 3
	2 4
	2 5
	*/
	//DFS : depth first search <- 재귀
	//     - 완전 탐색 <- 모든 것을 다 들려본다.
	
	// 1. 트리에서 모든 node를 전부 다 들려보겠다.
	// 인접 행렬 저장
	//cin >> cntNode;
	//for (int i = 0; i < cntNode - 1; i++) // tree구조에서는 edge개수 == node개수-1
	//{
	//	int parent, child; // parent -> child
	//	cin >> parent >> child;
	//	arr[parent][child] = 1;
	//}
	//dfsArray(1);
	// 인접 리스트 저장
	//cin >> cntNode;
	//for (int i = 0; i < cntNode - 1; i++)
	//{
	//	int parent, child;
	//	cin >> parent >> child;
	//	v[parent].push_back(child); // parent는 child라는 node로 갈 수 있다.
	//}
	//dfsVector(1);
	// 2. 두 그룹의 그래프
	/*
7 <- node개수
5 <- edge개수
1 2 <- edge에 대한 정보
2 4
2 5
3 6
6 7
1 3 <- A에서 B로 갈 수 있는가?
	*/
	//int cntEdge;
	//cin >> cntNode >> cntEdge;
	//for (int i = 0; i < cntEdge; i++)
	//{
	//	int from, to;
	//	cin >> from >> to;
	//	arr[from][to] = 1;
	//}
	//// A -> B로 가능?
	//int A, B;
	//cin >> A >> B;
	//// 2. -1)
	////dfs2(A);
	////cout << ans;
	//// 2. -2)
	////used[A] = 1; // A라는 점을 들린다.
	////dfs2(A);
	//// 2. -3)
	//path.push_back(A);
	//dfs2(A);
	//path.pop_back();
	
	/*
5
6
1 2
1 3
1 4
2 5
3 4
4 5
무방향 그래프의
모든점 들려보기!!!
	*/
	int cntEdge;
	cin >> cntNode >> cntEdge;
	for (int i = 0; i < cntEdge; i++)
	{
		int from, to;
		cin >> from >> to;
		arr[from][to] = 1;
		arr[to][from] = 1; // 무방향(양방향)
	}
	// 시작점도 따지고보면 찾은 점(손으로 직접)
	path.push_back(1);
	used[1] = 1;
	dfs3(1);
	return 0;
}