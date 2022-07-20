#include <iostream>
using namespace std;

int main(){
    char c;

    cin >> c;

    if ( int('a') <= int(c) && int(c) <= int('z')){
        cout << "소문자입니다" << endl;
    }else if ( int('A') <= int(c) && int(c) <= int('Z')){
        cout << "대문자입니다" << endl;
    }
    
    return 0;
}