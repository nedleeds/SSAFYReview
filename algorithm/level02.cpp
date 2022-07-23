#include <iostream>
using namespace std;


void Process(char *c, char arr[3][3]){
    char t = *c - 'A' + 'a';
    for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            if (arr[r][c] == t){
                cout << "존재" << endl;
                return ;
            }
        }
    }
    cout << "없음" << endl;
    return ;
}

void Input(char arr[3][3]){
    char c; 
    cin >> c;
    Process(&c, arr);
}

int main(){
    int flag = 0;
    char arr[3][3] = {
        {'a', 'b', 'd'},
        {'e', 'w', 'z'},
        {'q', 'v', 'a'}
    };

    Input(arr);


    return 0;
}