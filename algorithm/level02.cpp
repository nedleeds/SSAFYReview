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
    int arr[2][5] = {{3, 2, 6, 2, 4},
                     {1, 4, 2, 6, 5}};
    int target;

    cin >> target;
    if (KFC(target, arr)){
        cout << "값이 존재합니다" << endl;
    }else{
        cout << "값이 없습니다" << endl;
    }

    return 0;
}