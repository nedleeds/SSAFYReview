#include<iostream>
#include<stack> 
using namespace std;

int MAP[5][5] = {
    {0, 1, 1, 0, 0},
    {0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

// stack dfs
stack<int> s;
int visited[10];

void dfs(int node) {

    visited[node] = 1;
    s.push(node);
    cout << node << " ";

    while (!s.empty()) {
        // ���� ���
        int now = s.top();

        // �� �� ���ִ� ��尡 �ִ��� Ȯ���ϱ� ���� ���� 
        int flag = 0;

        // ������İ� �����ϰ� ������ �� �ִ� ��� Ȯ�� 
        for (int i = 0; i < 5; i++) {

            // �� �� ���ٸ� continue 
            if (MAP[now][i] == 0)
                continue;

            // �湮������ �ִٸ� continue
            if (visited[i] == 1)
                continue;

            // ���
            cout << i << " ";

            // ---- ������� �Դٸ� -> ���� �ִ� ����!
            s.push(i);
            visited[i] = 1;
            // ������ �ִ� ��尡 �ִٸ�
            flag = 1;
            break;
        }
        // �� üũ�غôµ�, ������ �ִ� ��尡 �� ���׿�? 
        // �׷��ٸ� ���� �����ϰ��ִ� ����� ������ ����
        if (flag == 0) {
            s.pop();
        }
    }
}

int main() {
    // dfs -> 0�� ������
    dfs(0);
}