#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int arr[3][5] = {
        {1, 3, 3, 5, 1},
        {3, 6, 2, 4, 2},
        {1, 9, 2, 6, 5},
    };
    int DAT[10]={0};
    int n;
    cin >> n;
    for (int r=0; r<3; r++){
        for (int c=0; c<5; c++){
            DAT[arr[r][c]]++;
        }
    }

    for (int j=1; j<=9; j++){
        if (DAT[j]==n){
            cout << j << " ";
        }
    }
    cout << "\n";
    
    return 0;
} 
