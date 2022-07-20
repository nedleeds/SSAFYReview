#include <iostream>
using namespace std;

int main(){
    char c;

    cin >> c;

    if ( 'a' <= c && c <= 'z'){
        cout << "소문자입니다" << endl;
    }else if ( 'A' <= c && c <= 'Z'){
        cout << "대문자입니다" << endl;
    }
    
    return 0;
}