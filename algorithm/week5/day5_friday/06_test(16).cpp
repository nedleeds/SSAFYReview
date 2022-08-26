//#include <iostream>
//#include<vector>
//#include<queue>
//#include <string>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//int arr[1002][1002] = { 0, };
//int n, d;
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//
//bool calc_range(int x, int y)
//{
//    if (x >= 0 && x <= n && y >= 0 && y <= n)
//        return true;
//    return false;
//}
//
//struct info {
//    int n;
//    int d;
//};
//
//bool comp(info a, info b)
//{
//    if (a.n > b.n)
//        return true;
//    else if (a.n == b.n)
//        return a.d < b.d;
//    else
//        return false;
//}
//
//int main()
//{
//    cin >> n;
//    //너비 해당 블록의 수
//    //플러드필을 하면서 둘레 BFS를 했을 때 근처가 0인 수
//    for (int i = 1; i <= n; i++)
//    {
//        string map;
//        cin >> map;
//        for (int j = 1; j <= n; j++)
//        {
//            if (map[j - 1] == '#')
//            {
//                arr[i][j] = 1;
//            }
//            else
//            {
//                arr[i][j] = 0;
//            }
//        }
//
//
//    }
//    int de = 1;
//
//    vector<info>array;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//
//            if (arr[i][j] == 1)
//            {
//                int tmp_n = 1;
//                int tmp_d = 0;
//                queue<pair<int, int>>q;
//                arr[i][j] = -1;
//                q.push({ i,j });
//                while (!q.empty())
//                {
//                    int x, y;
//                    tie(x, y) = q.front();
//                    q.pop();
//                    for (int d = 0; d < 4; d++)
//                    {
//                        int mov_x = x + dx[d];
//                        int mov_y = y + dy[d];
//                        if (calc_range(mov_x, mov_y))
//                        {
//                            if (arr[mov_x][mov_y] == 0)
//                            {
//                                tmp_d++;
//                            }
//                            else if (arr[mov_x][mov_y] == 1)
//                            {
//                                tmp_n++;
//                                arr[mov_x][mov_y] = -1;
//                                q.push({ mov_x,mov_y });
//                            }
//                        }
//                    }
//                }
//                array.push_back({ tmp_n,tmp_d });
//            }
//        }
//    }
//    sort(array.begin(), array.end(), comp);
//    cout << array[0].n << ' ' << array[0].d << endl;
//}