#include <iostream>
using namespace std;

void process(char arr[3][3]){
    for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            if ('a' <= arr[r][c] && arr[r][c] <= 'z'){
                cout << char(arr[r][c] - ('a'-'A')) << " ";
            }else if ('A' <= arr[r][c] && arr[r][c] <= 'Z'){
                cout << char(arr[r][c] - ('A'-'a')) << " ";
            }else if ('0' <= arr[r][c] && arr[r][c] <= '9'){
                cout << char(arr[r][c] - '0' + '5') << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    char arr[3][3] = {
        {'a', 'b', 'E'},
        {'E', '2', 'W'},
        {'3', '2', '4'}
    };

    process(arr);

    return 0;
}