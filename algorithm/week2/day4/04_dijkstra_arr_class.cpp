#include <iostream>
#include <queue>
using namespace std;

/*
1. ���� Ȯ������ ���� node�� �� ���� �����(���������κ���) node�� �ϳ� select
2. select�� node�� ������� �� �� �ִ� ��� node�� ���� �Ÿ��� ����
*/
/*
8 <- node����
11<- edge����
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
    int arr[10][10] = { 0, };// ���� ���
    for (int i = 0; i < cntEdge; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from][to] = cost;
        arr[to][from] = cost;
    } // 1. �׷��� ����

    // �ʿ��� data : *���������κ����� �Ÿ�*, Ȯ�� ����
    int dist[10];
    int used[10] = { 0, }; // index : �� ��ȣ, value : �ش� '���� �Ÿ��� Ȯ�� �ߴ°�?'
    for (int i = 0; i < 10; i++)
    {
        dist[i] = 2134567890; // �������� ���� �� ���� ũ���� ��(����� �Ѱ��� �ƴϸ� �츮�� ���� �𸣴���)
    } // �Ÿ� ����(�ʱ�ȭ)

    dist[1] = 0;// �� ������ ��Ȯ�� �Ÿ��� �˰� ���۰��� <- �������� �Ÿ��� 0���� ����



    // ��ǥ : ��� ���� �ִ� �Ÿ�
    // �Ʒ� �ݺ����� 1�� �ݺ� : �� 1�� Ȯ��
    // ���� ����

    for (int times = 1; times < cntNode; times++) // cntNodeȽ�� or cntNode-1Ƚ���� �� ���� ��� ����
    {
        // 1. ���� Ȯ������ ���� node�� �� ���� �����(���������κ���) node�� �ϳ� select <- ���� ���� ����(for������)
        int now = -1; // <- �̹��� Ȯ���� ��(���������κ��� ���� ����� ��)
        int mindist = 2134567890; // ���ݱ��� �� (Ȯ������ ���� �Ÿ��� �ִ� �Ÿ�)
        for (int i = 1; i <= cntNode; i++) // i�� node��ȣ
        {
            if (dist[i] < mindist && used[i] == 0) // used[i] == 0 : Ȯ������ ���� ��, dist[i] < mindist : ���� ª�� �Ÿ�
            {
                mindist = dist[i];
                now = i;
            }
        }
        // now : �̹��� Ȯ���� �� �ִ� node, ���� Ȯ������ ���� �� �� ���� ����� ��
        used[now] = 1;// now�� Ȯ���ƴٶ�� ���

        // 2. select�� node(now)�� ������� �� �� �ִ� ��� node(next)�� ���� �Ÿ��� ����
        //    now->nextã��
        for (int next = 1; next <= cntNode; next++)
        {
            if (arr[now][next] == 0) continue; // now->next�� �� �� ������ ����
            // �ϴ� next�� now���� '�� ���� �ִ�'
            //dist[now]       : ������->now������ �Ÿ�
            //arr[now][next]  : now->next������ �Ÿ�
            // ������ -> now�� ���� -> next���� ���� �Ÿ� : dist[now] + arr[now][next]
            if (dist[now] + arr[now][next] > dist[next]) continue; // now�� ���� ���°� '�տ��� ���ߴ� �Ÿ�'���� �� �� ���

            dist[next] = dist[now] + arr[now][next]; // now�� ���İ��°� �� �̵��̴�, now�� ���İ��� �Ÿ��� next�� �Ÿ��� ����
        }
    }

    return 0;
}