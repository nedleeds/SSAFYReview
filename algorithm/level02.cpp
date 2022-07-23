#include <iostream>
using namespace std;
int main(){
    int r1, r2;
    int arr[6][3], i=10;

    cin >> r1 >> r2;

    for (int c=0; c<3; c++){
        for (int r=0; r<6; r++){
            if (r1<=r && r<=r2){
                arr[r][c] = 7;
            }else{
                arr[r][c] = i;
            }
            i++;
        }
    }

    for (int r=0; r<6; r++){
        for (int c=0; c<3; c++){
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }



    return 0;
}
