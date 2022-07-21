#include <iostream>
using namespace std;

void input(char arr[17], char a, char b, char c){
    for (int i=0; i<7; i++){
        arr[i] = a;
    }
    for (int i=7; i<13; i++){
        arr[i] = b;
    }
    for (int i=13; i<17; i++){
        arr[i] = c;
    }
}

int main(){
    char arr[17] = {0,};
    char a, b, c;

    cin >> a >> b >> c;

    input(arr, a, b, c);

    for (int i=16; i>=0; i--){
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
