#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> path;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

    int numNode, numEdge, costLimit;
    cin >> numNode >> numEdge >> costLimit;

    int arr[10][10] = { 0, }; // ���� ���
    for (int i = 0; i < numEdge; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from][to] = cost;
    } // 1. �׷��� ����

    // 2. Queue ����
    queue<int> q; // queue�� �ִ� ���� : node����
    int cost[10] = { 0, }; // index : ��� ��ȣ, value : �ش� node������ ���

    // 3. ���۳�� ����
    cost[0] = 0;
    q.push(0); // 1������ �������̹Ƿ� �־���

    //7. 4~6�ܰ� �ݺ�
    while (!q.empty()) // queue�� ������� �ʾҴ� : ���� ���ѳ��� ������ node�� ���Ҵ�.
    {
        //4. queue���� node(now)�� �ϳ� ����
        int now = q.front(); // now : �̹��� ������ ���ѳ��� node
        q.pop();

        

        // 5. now���� �� �� �ִ� node(next)�� ã��
        for (int next = 1; next <= 9; next++)
        {
            if (arr[now][next] == 0) continue; // now->next�� ���� ���ϸ� ����

            // now�� next�� ������ų �� �ִ�.
            // -------- ���ο� next��� ���� ã�Ҵ�.

            // 6. next���� queue�� �߰�
            cost[next] = cost[now] + arr[now][next];

            if (cost[next] > costLimit) continue;
            path.push_back(next);
            q.push(next);
        }
    }

    for (int i = 0; i < path.size()-1; i++) {
        for (int j = i + 1; j < path.size(); j++) {
            if (path[i] > path[j]) {
                int tmp = path[i];
                path[i] = path[j];
                path[j] = tmp;
            }
        }
    }

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << ' ';
    }

    // ����� �� ó�� : now������ ��� �� �� ���� ��
    // ã���� �� ó�� : now,next�� �ΰ����� ���� Ȯ���Ҷ�
    // next������ �Ÿ� = now������ �Ÿ� + (now->next)�� �Ÿ�    <= (ó��, ���) now,next


    return 0;
}