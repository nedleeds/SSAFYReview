#include <iostream>
using namespace std;

int main(){
    char a;
    cin >> a;
    if ('a'<= a && a<='z'){
        cout << "소문자입력!!" << endl;
    }
    else if ('A'<= a && a<='Z'){
        cout << "대문자입력!!" << endl;
    }
    else if ('0'<= a && a<='9'){
        cout << "숫자문자입력!!" << endl;
    }
    return 0;
}