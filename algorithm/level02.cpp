#include <iostream>
#include <string>
using namespace std;

void Output(int arr[3][3]){
    for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            if (arr[r][c] == 0){
                cout << " ";
            }else{
                cout << arr[r][c];
            }
        }
        cout << endl;
    }
}

void Magic(int arr[3][3]){
    int i = 1;
    for (int r=0; r<3; r++){
        for (int c=r; c<3; c++){
            arr[r][c] = i++;
        }
    }
}

int main(){
    int arr[3][3] = {0};

    Magic(arr);
    Output(arr);

    return 0;
}