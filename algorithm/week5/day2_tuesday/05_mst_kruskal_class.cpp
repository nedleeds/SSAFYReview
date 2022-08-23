#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// MST
// --> kruskal (�������� ����)
// --> prim    (������� ����)

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

// ���� : ��� ���� ��θ� �����ϴµ��� ��� �ּ� ���
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
    // �� A
    int a;
    // �� B
    int b;
    // �ΰ� ������ cost
    int cost;
};

int n, m; // n : ��尳��, m ; ��������
vector<Edge>v;

bool cmp(Edge a, Edge b) {
    if (a.cost < b.cost)
        return true;
    if (a.cost > b.cost)
        return false;
    return false;
}

int kruskal() {
    // ���� �������� ���ͼ� �����ϴ� �˰��� 
    // ��� ������ �̹� �˰� �ִ� ���¿��� ������� cost�� �����ź��� �������
    // ����
    sort(v.begin(), v.end(), cmp);
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        // ���� ���� �ִ� ���� (�Ѱź���)
        Edge now = v[i];
        // ���� �̹� ��ΰ� �ִ� ����� ���ΰ�? 
        if (Find(now.a) == Find(now.b))
            // ������ �ʿ� ����! ( �� ���� ����� �� �� �ʿ䰡 ����)
            continue;
        // �갡 ���� �� �ٸ���, ���� �� ��� �����ϱ�
        // �긦 �Ǽ��ϴ°� ���� �̵�!
        sum += now.cost;
        cnt++; // �ٸ� �ϳ��� �� ���Ҵ�! 
        // ���� �ٸ��� ���Ҵٴ°� -> �� ���� ������ �Ǿ��� -> �����ش� 
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
    // parent �ʱ� ����
    for (int i = 0; i <= n; i++)
        parent[i] = i;

    // solve
    int ans = kruskal();
    cout << ans << " " << cnt;
}