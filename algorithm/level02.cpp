#include <iostream>
#include <string>
using namespace std;

void getName(char *a, char *b){
    cin >> *a >> *b;
}

int main(){
    char a, b;

    getName(&a, &b);

    if (a > b){
        cout << b << endl;
    }else{
        cout << a << endl;
    }

    return 0;
}