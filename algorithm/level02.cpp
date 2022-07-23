#include <iostream>
#include <string>
using namespace std;

int main(){
    int arr[3][3] = {0};
    char x;
    
    cin >> x;

    if ('0' <= x && x <='9'){
        int i=1;
        for(int r=2; r>=0; r--){
            for (int c=2; c>=r; c--){
                arr[r][c] = i++;
            }
        }
    }else if ('A' <= x && x<= 'Z'){
        int i=1;
        for(int r=2; r>=0; r--){
            for (int c=0; c<=r; c++){
                arr[r][c] = i++;
            }
        }
    }

    for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            if (arr[r][c]==0){
                cout << ' ';
            }else{
                cout << arr[r][c];
            }
        }
        cout << endl;
    }

    return 0;
}