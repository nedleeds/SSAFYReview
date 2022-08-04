#include <iostream>
#include <queue>
#include<vector>
using namespace std;

/*
1. ���� Ȯ������ ���� node�� �� ���� �����(���������κ���) node�� �ϳ� select
2. select�� node�� ������� �� �� �ִ� ��� node�� ���� �Ÿ��� ����
*/
/*
5
7
0 1 10 
0 2 7
1 3 5
1 2 2
2 3 3
2 4 8
3 4 4
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
    vector<Edge> v[10];// ���� ����Ʈ : cost (now->next�� ���� �Ÿ�)

    for (int i = 0; i < cntEdge; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({ to, cost });
        v[to].push_back({ from, cost });
    } // 1. �׷��� ����

    // 2. �ʿ��� data �غ� : �Ÿ�, Ȯ�� ����

    // ã�Ҵ� �Ÿ��� �߿��� ���� ª�� �Ÿ�
    // priority_queue <- ����ϴ� ����????
    //      � �켱������ ���ϰ�, �ش� �켱������� data�� ���� ���
    priority_queue< Edge > pq; // ��� ���ΰ�?, ���������κ��� �󸶳� �ָ� �ִ°�(�Ÿ�)?
                                // cost (������->to�� ���� �Ÿ�)
    int dist[10];
    int used[10] = { 0, }; // index : node��ȣ, value : �ش� ���� Ȯ���ߴ°�?
    for (int i = 0; i < cntNode; i++)
        dist[i] = 2134567890; // dist�� ū������ '�� �� ����'�� ���·� �ʱ�ȭ

    // 3. ������ ����
    dist[0] = 0; // ������ ����
    pq.push({ 0, 0 }); // 1�̶�� �������� 0�� �Ÿ��� �� �� �ִ�.

    // 7. 4~6�ܰ� �ݺ�
    // cntNode-1�� ������ ó���ϸ� X <- �������� �� ���� �� �־
    while (!pq.empty()) {
        //4. now������
        // (1. ���� ����� ��(now) �ϳ� ����(Ȯ������ ���� �� �߿���))
        int now = pq.top().to;
        int nowDist = pq.top().cost;
        pq.pop();

        if (used[now] == 1) continue; // �̹� Ȯ���� �ƴ� ���̴�.

        // ���� Ȯ��
        used[now] = 1;

        // 5. next->next
        // Ȯ���� now�� ������� next���� ���� -> ���ο� ��(���)�� ã�Ҵ�.
        for (int i = 0; i < v[now].size(); i++)
        {
            Edge edge = v[now][i];
            int next = edge.to; // now->next ��� �� ��ȣ
            int edgeDist = edge.cost;// now->next�� ���� ���(�Ÿ�)
            // ������ -> now -> next
            if (dist[now] + edgeDist > dist[next]) continue;

            // 6. next�� queue�� �߰�
            dist[next] = dist[now] + edgeDist;
            pq.push({ next, dist[next] });
        }
    }
    int de = 1;

    cout << dist[4];

    return 0;
}