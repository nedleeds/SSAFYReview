#include <iostream>
using namespace std;

void input(char* a){
    cin >> *a;
}

void output(char* a, char arr1[5], char arr2[5]){
    if ('a'<= *a && *a <='z'){
        for (int i=0; i<5; i++){
            cout << arr1[i];
        }
    }else if('A' <= *a && *a <= 'Z'){
        for (int j=0; j<5; j++){
            cout << arr2[j];
        }
    }else if('0' <= *a && *a <= '9'){
        for (char k='H'; k>='A'; k--){
            cout << k;
        }
    }
    cout << endl;
}

int main(){
    char arr1[5] = {'B', 'D', '5', 'Q', 'A'};
    char arr2[5] = {'Q', 'E', 'R', 'E', 'F'};
    char a;

    input(&a);
    output(&a, arr1, arr2);


    return 0;
}
