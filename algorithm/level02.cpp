#include <iostream>
#include <string>
using namespace std;

void CountLine(string *s){
    cout << (*s).length() << "=" << *s << endl;
}

int main(){
    string s[4];

    int cnt_A = 0;
    int cnt_B = 0;
    for (int i=0; i<4; i++){
        cin >> s[i];
        for (int j=0; j<s[i].length(); j++){
            if (s[i][j] == 'A'){
                cnt_A ++;
            }else if (s[i][j] == 'B'){
                cnt_B ++;
            }
        }
    }

    if (cnt_A*cnt_B>0 && cnt_A+cnt_B>1){
        cout << "대발견" << endl;
    }
    if (cnt_A*cnt_B==0 && (cnt_A>0 || cnt_B>0)){
        cout << "중발견" << endl;
    }
    if (cnt_A == 0 && cnt_B == 0){
        cout << "미발견" << endl;
    }
    

    return 0;
}