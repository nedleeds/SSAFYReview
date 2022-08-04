#include <iostream>
#include <queue>
#include<vector>
using namespace std;

/*
1. 아직 확정하지 않은 node들 중 가장 가까운(시작점으로부터) node를 하나 select
2. select한 node를 기반으로 갈 수 있는 모든 node에 대한 거리를 갱신
*/
/*
8 <- node개수
11<- edge개수
1 2 10 <- from, to, cost
1 5 1
2 3 5
3 5 2
3 6 4
3 7 8
3 4 6
4 8 11
5 6 7
6 7 9
7 8 3
*/

struct Edge {
    int to;
    int cost;
};

bool operator<(Edge A, Edge B)
{
    if (A.cost < B.cost) return false;
    if (A.cost > B.cost) return true;

    if (A.to < B.to) return false;
    if (A.to > B.to) return true;

    return false;
}

int main()
{
    int cntNode, cntEdge;
    cin >> cntNode >> cntEdge;
    vector<Edge> v[10];// 인접 리스트 : cost (now->next로 가는 거리)
    for (int i = 0; i < cntEdge; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({ to, cost });
        v[to].push_back({ from, cost });
    } // 1. 그래프 구성

    // 2. 필요한 data 준비 : 거리, 확정 여부

    // 찾았던 거리들 중에서 제일 짧은 거리
    // priority_queue <- 사용하는 이유????
    //      어떤 우선순위를 정하고, 해당 우선순위대로 data를 꺼내 사용
    priority_queue< Edge > pq; // 어느 점인가?, 시작점으로부터 얼마나 멀리 있는가(거리)?
                                // cost (시작점->to로 가는 거리)
    int dist[10];
    int used[10] = { 0, }; // index : node번호, value : 해당 점을 확정했는가?
    for (int i = 1; i <= cntNode; i++)
        dist[i] = 2134567890; // dist를 큰값으로 '갈 수 없다'의 형태로 초기화

    // 3. 시작점 세팅
    dist[1] = 0; // 시작점 세팅
    pq.push({ 1, 0 }); // 1이라는 시작점은 0의 거리로 갈 수 있다.

    // 7. 4~6단계 반복
    // cntNode-1번 꺼내서 처리하면 X <- 같은점을 또 꺼낼 수 있어서
    while (!pq.empty()) {
        //4. now꺼내기
        // (1. 가장 가까운 점(now) 하나 고르기(확정하지 않은 점 중에서))
        int now = pq.top().to;
        int nowDist = pq.top().cost;
        pq.pop();

        if (used[now] == 1) continue; // 이미 확정이 됐던 점이다.

        // 점을 확정
        used[now] = 1;

        // 5. next->next
        // 확정된 now를 기반으로 next들을 갱신 -> 새로운 점(방법)을 찾았다.
        for (int i = 0; i < v[now].size(); i++)
        {
            Edge edge = v[now][i];
            int next = edge.to; // now->next 라는 점 번호
            int edgeDist = edge.cost;// now->next로 가는 비용(거리)
            // 시작점 -> now -> next
            if (dist[now] + edgeDist > dist[next]) continue;

            // 6. next를 queue에 추가
            dist[next] = dist[now] + edgeDist;
            pq.push({ next, dist[next] });
        }
    }
    int de = 1;
    return 0;
}