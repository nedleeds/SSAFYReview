#include <iostream>
#include <string>
using namespace std;

int main(){
    int x, arr[3][4]={0,};

    cin >> x;

    int y = 0;
    for (int r=0; r<3; r++){
       for (int c=2+y; c<4; c++){
            arr[r][c] = x++;
       }
        y--;
    }

    for (int r=0; r<3; r++){
        for (int c=0; c<4; c++){
            if (arr[r][c] == 0){
                cout << " ";
            }else{
                cout << arr[r][c];
            }
        }
        cout << endl;
    }
    
    return 0;
}