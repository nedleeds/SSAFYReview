#include <iostream>
using namespace std;

int KFC(int target, int arr[2][5]){
    for (int r=0; r<2; r++){
        for (int c=0; c<5; c++){
            if (arr[r][c] == target){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int arr[4][4] = {{1, 3, 6, 2},
                     {4, 2, 4, 5},
                     {6, 3, 7, 3},
                     {1, 5, 4, 6}};
    int n, select[16], s_i=0;

    cin >> n;
    
    for (int r=0; r<4; r++){
        for (int c=0; c<4; c++){
            if (arr[r][c] > n){
                select[s_i++] = arr[r][c];
            }
        }
    }

    for (int i=0; i<s_i; i++){
        cout << select[i] << " ";
    }
    cout << endl;

    return 0;
}