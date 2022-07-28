#include <iostream>
#include <vector>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    //// 입력 : 누가 누구에게 투표했는가
    //// 첫 번째 줄에 반의 인원 수 N(1 <= N <= 10)
    //// 두 번째 줄부터 N개의 줄에 걸쳐 각 사람이 투표한 정보
    //// ex)
    //// 4
    //// 1 0 1 0
    //// 0 0 0 1
    //// 1 1 0 0
    //// 1 1 0 1

    //// 출력 : 제일 많이 받은 사람과 제일 적게 받은 사람


    //int N;
    //cin >> N;
    //int arr[11][11] = {0,};
    //// arr[from][to] <- value : from->to로 갈 수 있는가?
    ////                            투표를 했는가?

    //for (int from = 1; from <= N; from++)
    //{
    //    for (int to = 1; to <= N; to++)
    //    {
    //        cin >> arr[from][to]; // 해당하는 from에서 to로 가는 정보
    //    }
    //}

    ////1이 3번에게 투표했는가? <- 
    ////arr[1][3] 

    ////받은게 중심 <- to
    //int maxSum = -1; // 최대 받은 표수
    //int maxTo = -1; // 표를 최대로 많이 받은 사람 번호
    //int minSum = 2134567890;
    //int minTo = -1;
    //for (int to = 1; to <= N; to++)
    //{
    //    int sum = 0;
    //    for (int from = 1; from <= N; from++)
    //    {
    //        //sum += arr[from][to];
    //        if (arr[from][to] == 1)
    //            sum++;
    //    }
    //    cout << to << ":" << sum << "\n";
    //    if (sum > maxSum)
    //    {
    //        maxSum = sum;
    //        maxTo = to;
    //    }
    //    if (sum < minSum)
    //    {
    //        minSum = sum;
    //        minTo = to;
    //    }
    //}
    //cout << maxTo << "\n" << minTo;


    //cout << sizeof(int); // 4byte




    //입력 정보를 토대로 인접 행렬 방식 저장
    //    4 < -node 개수
    //    6 < -edge 개수
    //    1 2 < -from to정보가 edge개수
    //    2 3
    //    2 4
    //    3 4
    //    4 2
    //    4 3
    //int cntNode, cntEdge;
    //cin >> cntNode >> cntEdge;
    //int arr[100][100] = {0, };
    //for (int i = 0; i < cntEdge; i++)
    //{
    //    int from, to;
    //    cin >> from >> to;
    //    arr[from][to] = 1; // 인접 행렬 방식으로 저장
    //    arr[to][from] = 1; // edge에 방향이 없는 경우
    //}

    //int de = 1;
    //for (int from = 1; from <= cntNode; from++)
    //{
    //    for (int to = 1; to <= cntNode; to++)
    //    {
    //        cout << arr[from][to] << " ";
    //    }
    //    cout << "\n";
    //}


    //// 인접 리스트
    //vector<int> v[100]; // vector<벡터 안에 어떤 data형태를 저장할 것인가?>
    //int cntNode, cntEdge;
    //cin >> cntNode >> cntEdge;
    //for (int i = 0; i < cntEdge; i++)
    //{
    //    int from, to;
    //    cin >> from >> to;
    //    v[from].push_back(to); 
    //    v[to].push_back(from); // 무방향
    //    // vector.push_back(data) : vector의 맨 뒤에 공간을 추가하여 data를 저장
    //}

/*
5 8 <- node개수 edge개수
1 2 <- edge정보
1 5
2 4
2 3
3 4
3 5
4 1
4 3
2 <- 특정 node
*/

    // 인접 행렬 - 특정 node에서 갈 수 있는 node들 찾기
    //int cntNode, cntEdge;
    //cin >> cntNode >> cntEdge;
    //int arr[100][100] = { 0, };
    //for (int i = 0; i < cntEdge; i++)
    //{
    //    int from, to;
    //    cin >> from >> to;
    //    arr[from][to] = 1;
    //}
    //int node = -1;
    //cin >> node;

    ////활용 : 특정 node에서 갈 수 있는 node들 찾기
    //for (int to = 1; to <= cntNode; to++)
    //{
    //    if (arr[node][to] == 1)
    //    {
    //        cout << to << " ";
    //    }
    //}




    // 인접 리스트 - 특정 node에서 갈 수 있는 node들 찾기
    int cntNode, cntEdge;
    cin >> cntNode >> cntEdge;
    vector<int> v[100]; // 인접 리스트
    for (int i = 0; i < cntEdge; i++)
    {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
    }
    int node = -1;
    cin >> node;

    //v[node][0];
    //v[node][1];
    //v[node][2];
    //......
    //몇 개의 data를 꺼내야 할까? v[node]가 갖고 있는 data 개수 만큼
    //v[node][v[node]가 갖고 있는 data 개수 - 1]
    for (int i = 0; i < v[node].size(); i++) // vector.size() : vector가 갖고있는 data 개수
    {
        cout << v[node][i] << " ";
    }
    




    return 0;
}