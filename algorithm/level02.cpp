#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;

    for (int i=0; i<s.length(); i++){
        if (i%2==0){
            if ('A' <= s[i] && s[i] <= 'Z'){
                ;
            }else{
                cout << "일반문장" << endl;
                return 0;
            }
        } else {
            if('a' <= s[i] && s[i] <= 'z'){
                ;
            }else{
                cout << "일반문장" << endl;
                return 0;
            }
        }
    }
    cout << "개구리문장" << endl;

    return 0;
}