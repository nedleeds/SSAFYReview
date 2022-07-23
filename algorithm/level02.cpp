#include <iostream>
#include <string>
using namespace std;

int main(){
    int x, arr[5][5]={0};
    
    cin >> x;

    for (int r=0; r<5; r++){
        if (r==0 || r==4){
            for (int c=0; c<5; c++){
                arr[r][c] = x;
            }
        }else{
            arr[r][0] = x;
            arr[r][4] = x;
        }
    }

    for (int r=0; r<5; r++){
        for (int c=0; c<5; c++){
            if (arr[r][c]==0){
                cout << "_";
            }else{
                cout << arr[r][c];
            }
        }
        cout << endl;
    }

    return 0;
}