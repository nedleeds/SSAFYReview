#include <iostream>
#include <string>
using namespace std;

struct Point
{
    int M; 
    int m;
    int M_r, M_c;
    int m_r, m_c;
}p1;


int main(){
    int arr[4][4] = {
        {3, 4, 1, 6},
        {3, 5, 3, 6},
        {0, 0, 0, 0},
        {5, 4, 6, 0}
    };

    for (int c=0; c<4; c++){
        cin >> arr[2][c];
    }
    
    p1.M = 0;
    p1.m = 9999;
    for (int r=0; r<4; r++){
        for (int c=0; c<4; c++){
            if (p1.M < arr[r][c]){
                p1.M = arr[r][c];
                p1.M_r = r;
                p1.M_c = c;
            }else if(p1.m > arr[r][c]){
                p1.m = arr[r][c];
                p1.m_r = r;
                p1.m_c = c;
            }
        }
    }
    
    cout << "MAX=" << p1.M << "(" << p1.M_r << "," << p1.M_c << ")" << endl;
    cout << "MIN=" << p1.m << "(" << p1.m_r << "," << p1.m_c << ")" << endl;

    return 0;
}