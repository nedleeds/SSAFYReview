#include <iostream>
using namespace std;

int arr[3][3] = {{1, 1, 1},
                 {1, 2, 1}, 
                 {3, 6, 3}};

int Count(int *n){
    int cnt=0;
    for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            if (arr[r][c] == *n){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int num;

    cin >> num;

    cout << Count(&num) << endl;;

    return 0;
}