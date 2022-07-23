#include <iostream>
#include <string>
using namespace std;

void input(int *x, int *y, int *z){
    cin >> *x >> *y >> *z;
}

void process(int *x, int *y, int *z, int arr[2][6], int cnt[3]){
    for (int r=0; r<2; r++){
        for (int c=0; c<6; c++){
            if (arr[r][c] == *x){
                cnt[0]++;
            }else if (arr[r][c] == *y){
                cnt[1]++;
            }else if (arr[r][c] == *z){
                cnt[2]++;
            }
        }
    }
}

void output(int *x, int *y, int *z, int cnt[3]){
    cout << *x << "=" << cnt[0] << "개" << endl;
    cout << *y << "=" << cnt[1] << "개" << endl;
    cout << *z << "=" << cnt[2] << "개" << endl;
}

int main(){
    int arr[2][6] = {
        {4, 5, 6, 1, 3, 1},
        {2, 1, 3, 6, 3, 6}
    };

    int x, y, z, cnt[3]={0};
    
    input(&x, &y, &z);
    process(&x, &y, &z, arr, cnt);
    output(&x, &y, &z, cnt);

    return 0;
}