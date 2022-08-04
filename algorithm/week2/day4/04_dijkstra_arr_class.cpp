#include <iostream>
#include <queue>
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
int main()
{
    int cntNode, cntEdge;
    cin >> cntNode >> cntEdge;
    int arr[10][10] = { 0, };// 인접 행렬
    for (int i = 0; i < cntEdge; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from][to] = cost;
        arr[to][from] = cost;
    } // 1. 그래프 구성

    // 필요한 data : *시작점으로부터의 거리*, 확정 유무
    int dist[10];
    int used[10] = { 0, }; // index : 점 번호, value : 해당 '점의 거리를 확정 했는가?'
    for (int i = 0; i < 10; i++)
    {
        dist[i] = 2134567890; // 계산상으로 나올 수 없는 크기의 값(계산을 한건지 아니면 우리가 아직 모르는지)
    } // 거리 세팅(초기화)

    dist[1] = 0;// 딱 한점은 정확한 거리를 알고 시작가능 <- 시작점은 거리가 0으로 시작



    // 목표 : 모든 점의 최단 거리
    // 아래 반복문에 1번 반복 : 점 1개 확정
    // 점의 개수

    for (int times = 1; times < cntNode; times++) // cntNode횟수 or cntNode-1횟수의 두 가지 모두 가능
    {
        // 1. 아직 확정하지 않은 node들 중 가장 가까운(시작점으로부터) node를 하나 select <- 직접 구현 가능(for문으로)
        int now = -1; // <- 이번에 확정할 점(시작점으로부터 가장 가까운 점)
        int mindist = 2134567890; // 지금까지 본 (확정되지 않은 거리중 최단 거리)
        for (int i = 1; i <= cntNode; i++) // i는 node번호
        {
            if (dist[i] < mindist && used[i] == 0) // used[i] == 0 : 확정하지 않은 점, dist[i] < mindist : 제일 짧은 거리
            {
                mindist = dist[i];
                now = i;
            }
        }
        // now : 이번에 확정할 수 있는 node, 현재 확정되지 않은 점 중 제일 가까운 점
        used[now] = 1;// now는 확정됐다라고 기록

        // 2. select한 node(now)를 기반으로 갈 수 있는 모든 node(next)에 대한 거리를 갱신
        //    now->next찾기
        for (int next = 1; next <= cntNode; next++)
        {
            if (arr[now][next] == 0) continue; // now->next로 갈 수 없으면 무시
            // 일단 next는 now에서 '갈 수는 있다'
            //dist[now]       : 시작점->now까지의 거리
            //arr[now][next]  : now->next까지의 거리
            // 시작점 -> now를 거쳐 -> next까지 가는 거리 : dist[now] + arr[now][next]
            if (dist[now] + arr[now][next] > dist[next]) continue; // now를 거쳐 가는게 '앞에서 구했던 거리'보다 더 먼 경우

            dist[next] = dist[now] + arr[now][next]; // now를 거쳐가는게 더 이득이니, now를 거쳐가는 거리로 next의 거리를 갱신
        }
    }

    return 0;
}