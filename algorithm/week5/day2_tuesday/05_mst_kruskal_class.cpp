#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// MST
// --> kruskal (간선위주 선택)
// --> prim    (노드위주 선택)

/*
5 7
1 2 10
1 3 20
2 3 30
3 4 5
1 4 60
3 5 40
4 5 50
*/

// 문제 : 모든 섬의 경로를 연결하는데에 드는 최소 비용
int parent[10];
int cnt = 0;

int Find(int node) {
    if (node == parent[node])
        return node;
    return parent[node] = Find(parent[node]);
}

void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);
    if (pa == pb)
        return;
    parent[pb] = pa;
}

struct Edge {
    // 섬 A
    int a;
    // 섬 B
    int b;
    // 두개 사이의 cost
    int cost;
};

int n, m; // n : 노드개수, m ; 간선개수
vector<Edge>v;

bool cmp(Edge a, Edge b) {
    if (a.cost < b.cost)
        return true;
    if (a.cost > b.cost)
        return false;
    return false;
}

int kruskal() {
    // 작은 간선부터 빼와서 선택하는 알고리즘 
    // 모든 간선을 이미 알고 있는 상태에서 순서대로 cost가 작은거부터 빼오면됨
    // 정렬
    sort(v.begin(), v.end(), cmp);
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        // 지금 보고 있는 간선 (싼거부터)
        Edge now = v[i];
        // 둘이 이미 경로가 있는 연결된 섬인가? 
        if (Find(now.a) == Find(now.b))
            // 연결할 필요 없음! ( 이 간선 비용을 더 낼 필요가 없다)
            continue;
        // 얘가 제일 싼 다리고, 아직 이 경로 없으니까
        // 얘를 건설하는게 제일 이득!
        sum += now.cost;
        cnt++; // 다리 하나를 더 놓았다! 
        // 이제 다리를 놓았다는것 -> 두 섬이 연결이 되었다 -> 합쳐준다 
        Union(now.a, now.b);
    }
    return sum;
}

int main() {
    // input
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        v.push_back({ a, b, cost });
    }
    // parent 초기 세팅
    for (int i = 0; i <= n; i++)
        parent[i] = i;

    // solve
    int ans = kruskal();
    cout << ans << " " << cnt;
}