#include <iostream>
#include <vector>
#include <unordered_map> 
#include<string>
#include <map> 
#include<queue>
// map 도 존재함 <- hash가 아님
using namespace std;

struct Data {
    string PW;
    string name;
};



/*
입력으로
첫 번째 줄에 data의 개수 N이 주어짐.
이어지는 N개의 줄에 걸쳐 1~100사이의 정수가 1개씩 주어짐
출력으로
N개의 정수에서 어떤 정수가 몇 개씩 있는지 출력
1~100의 순서로

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
    int DAT[101] = { 0, }; // index : 입력받은 정수, value : 해당 정수의 개수
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
입력으로
첫 번째 줄에 data의 개수 N이 주어짐.
이어지는 N개의 줄에 걸쳐 3,000,000,000~3,000,000,100사이의 정수가 1개씩 주어짐
출력으로
N개의 정수에서 어떤 정수가 몇 개씩 있는지 출력
3,000,000,000~3,000,000,100의 순서로

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
    int DAT[101] = { 0, }; // index : 입력받은 정수, value : 해당 정수의 개수
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
    ID를 기반으로 해당 ID를 갖는 사람의 이름과 PW를 가져오는 프로그램

    첫 번째 줄에 등록된 ID, PW, name이 몇세트있는지
    해당 세트의 개수만큼 ID, PW, name을 각각 입력받음

    이어지는 마지막줄에 ID를 입력하면 해당 ID의 사람에 대한 이름과 PW를 출력
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
입력
    첫 번째 줄에 사람의 인원수 N이 주어짐
    두 번째 줄부터 N개의 줄에 걸쳐 사람 이름과 팀 번호(1 or 0)
    마지막 줄에 사람 이름 1개 주어짐

출력
    마지막 줄에 입력받은 사람이 무슨 팀인지 출력
    단, 팀을 배정받지 못했던 사람인 경우 -1을 출력
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
//    // unordered_map[key] <- key를 기반으로 hash value를 계산하는 순간 data가 생성(value = 0으로)
//    if (name2team.find(name) != name2team.end()) // 존재여부를 판단
//        cout << "이씀";
//    else
//        cout << "음씀";
//}

// map vs unordered_map



/*
반번호(0~10), 학생번호(0~30)
기반으로
해당 학생의 이름을 찾는 프로그램
*/

struct Da {
    int classNum;
    int studentNum;
    bool operator==(Da right) const {
        return classNum == right.classNum && studentNum == right.studentNum;
    }
};

// hash function, 충돌 방지
struct HF {
    size_t operator()(Da key) const {
        return key.classNum * 100 + key.studentNum;
    }
}; // HashFunction 제작

//struct HF {
//    size_t operator()(pair<int, int> key) const {
//        return key.first * 100 + key.second;
//    }
//}; // HashFunction 제작

void solution6()
{
    unordered_map<Da, string, HF> Da2name;

    //unordered_map<pair<int, int>, string, HF> Da2name;
    // pair<ty1, ty2> = ty1과 ty2의 data를 묶어서 사용하는 구조

    Da2name[{21, 1}] = "이동형";
    Da2name[{22, 0}] = "최세진";

    cout << Da2name[{22, 0}] << "\n";
    for (auto it = Da2name.begin(); it != Da2name.end(); it++)// Da2name내부의 data가 수정 가능
    {
        cout << (*it).first.classNum << " " << (*it).first.studentNum << " " << (*it).second << "\n";
    }
    for (auto data : Da2name) // Da2name내부의 data가 수정 안됨
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

// python에서 이와 비슷한 기능이 있음 : dictionary : key->value

int main()
{

    solution6();
    return