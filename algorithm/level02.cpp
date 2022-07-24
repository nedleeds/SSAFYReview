#include <iostream>
#include <string>
using namespace std;

int main(){
    char x;
    char arr[3][3] = {'\0'};
    cin >> x;

    for (int r=2; r>-1; r--){
        for (int c=0; c<=2-r; c++){
            arr[r][c] = x++;
        }
    }

    for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            if (arr[r][c]=='\0'){
                cout << " ";
            }else{
                cout << arr[r][c];
            }
        }
        cout << endl;
    }


    return 0;
}