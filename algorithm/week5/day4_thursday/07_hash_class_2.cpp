#include <iostream>
#include <vector>
#include <unordered_map> 
#include<string>
#include <map> 
#include<queue>
// map �� ������ <- hash�� �ƴ�
using namespace std;

struct Data {
    string PW;
    string name;
};



/*
�Է�����
ù ��° �ٿ� data�� ���� N�� �־���.
�̾����� N���� �ٿ� ���� 1~100������ ������ 1���� �־���
�������
N���� �������� � ������ �� ���� �ִ��� ���
1~100�� ������

ex)
5 <- N
2
1
1
5
4

1 : 2
2 : 1
3 : 0
4 : 1
5 : 1
...........
*/

void solution1()
{
    int DAT[101] = { 0, }; // index : �Է¹��� ����, value : �ش� ������ ����
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp; cin >> temp;
        DAT[temp]++;
    }
    for (int i = 1; i < 101; i++)
        cout << i << " : " << DAT[i] << "\n";
}

/*
�Է�����
ù ��° �ٿ� data�� ���� N�� �־���.
�̾����� N���� �ٿ� ���� 3,000,000,000~3,000,000,100������ ������ 1���� �־���
�������
N���� �������� � ������ �� ���� �ִ��� ���
3,000,000,000~3,000,000,100�� ������

ex)
5
3000000002
3000000001
3000000001
3000000005
3000000004

3000000001 : 2
3000000002 : 1
3000000003 : 0
3000000004 : 1
3000000005 : 1
...........
*/

int hashFunction2(long long key)
{
    return key - 3000000000;
}

void solution2()
{
    int DAT[101] = { 0, }; // index : �Է¹��� ����, value : �ش� ������ ����
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long long temp; cin >> temp;
        DAT[hashFunction2(temp)]++;
    }

    for (long long i = 3000000001; i < 3000000101; i++)
        cout << i << " : " << DAT[hashFunction2(i)] << "\n";
}

//void solution3()
//{
//    // "abc" => 842947
//    string name = "abc";
//    int ID = 842947;
//    name2ID[name] = ID;
//    cout << name2ID[name];
//}

/*
    ID�� ������� �ش� ID�� ���� ����� �̸��� PW�� �������� ���α׷�

    ù ��° �ٿ� ��ϵ� ID, PW, name�� �Ʈ�ִ���
    �ش� ��Ʈ�� ������ŭ ID, PW, name�� ���� �Է¹���

    �̾����� �������ٿ� ID�� �Է��ϸ� �ش� ID�� ����� ���� �̸��� PW�� ���
*/

unordered_map<string, Data> ID2Data;
void solution4()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string ID, PW, Name;
        cin >> ID >> PW >> Name;
        ID2Data[ID] = { PW, Name };
    }

    string ID;
    cin >> ID;
    cout << ID2Data[ID].name << " " << ID2Data[ID].PW;
}

/*
�Է�
    ù ��° �ٿ� ����� �ο��� N�� �־���
    �� ��° �ٺ��� N���� �ٿ� ���� ��� �̸��� �� ��ȣ(1 or 0)
    ������ �ٿ� ��� �̸� 1�� �־���

���
    ������ �ٿ� �Է¹��� ����� ���� ������ ���
    ��, ���� �������� ���ߴ� ����� ��� -1�� ���
*/

//void solution5()
//{
//    unordered_map<string, int> name2team;
//    int N;
//    cin >> N;
//    for (int i = 0; i < N; i++)
//    {
//        string name;
//        int team;
//        cin >> name >> team;
//        name2team[name] = team;
//    }
//    string name;
//    cin >> name;
//    // unordered_map[key] <- key�� ������� hash value�� ����ϴ� ���� data�� ����(value = 0����)
//    if (name2team.find(name) != name2team.end()) // ���翩�θ� �Ǵ�
//        cout << "�̾�";
//    else
//        cout << "����";
//}

// map vs unordered_map



/*
�ݹ�ȣ(0~10), �л���ȣ(0~30)
�������
�ش� �л��� �̸��� ã�� ���α׷�
*/

struct Da {
    int classNum;
    int studentNum;
    bool operator==(Da right) const {
        return classNum == right.classNum && studentNum == right.studentNum;
    }
};

// hash function, �浹 ����
struct HF {
    size_t operator()(Da key) const {
        return key.classNum * 100 + key.studentNum;
    }
}; // HashFunction ����

//struct HF {
//    size_t operator()(pair<int, int> key) const {
//        return key.first * 100 + key.second;
//    }
//}; // HashFunction ����

void solution6()
{
    unordered_map<Da, string, HF> Da2name;

    //unordered_map<pair<int, int>, string, HF> Da2name;
    // pair<ty1, ty2> = ty1�� ty2�� data�� ��� ����ϴ� ����

    Da2name[{21, 1}] = "�̵���";
    Da2name[{22, 0}] = "�ּ���";

    cout << Da2name[{22, 0}] << "\n";
    for (auto it = Da2name.begin(); it != Da2name.end(); it++)// Da2name������ data�� ���� ����
    {
        cout << (*it).first.classNum << " " << (*it).first.studentNum << " " << (*it).second << "\n";
    }
    for (auto data : Da2name) // Da2name������ data�� ���� �ȵ�
    {
        cout << data.first.classNum << " " << data.first.studentNum << " " << data.second << "\n";
    }

    priority_queue<pair<int, int>> pq;
    pq.push({ 5,3 });
    pq.push({ 1,3 });
    pq.push({ 6,3 });
    pq.push({ 5,7 });
    pq.push({ 5,4 });
    while (!pq.empty())
    {
        cout << pq.top().first << ", " << pq.top().second << "\n";
        pq.pop();
    }
}

// python���� �̿� ����� ����� ���� : dictionary : key->value

int main()
{

    solution6();
    return