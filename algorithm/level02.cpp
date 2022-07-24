#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1, s2; 

    cin >> s1 >> s2;
    
    if (s1 == s2){
        cout << "같음" << endl;
    }else{
        cout << "다름" << endl;
    }

    return 0;
}