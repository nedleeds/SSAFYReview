#include <iostream>
#include <string>
using namespace std;

void KFC(string *s, int *c_up, int *c_lo){
    for (int i=0; i<(*s).length()+1; i++){
        if ('a' <= (*s)[i] && (*s)[i] <= 'z'){
            (*c_lo)++;
        }else if ('A' <= (*s)[i] && (*s)[i] <= 'Z'){
            (*c_up)++;
        }
    }
}

int main(){
    string s;
    int cnt_up=0, cnt_lo=0;
    
    cin >> s;
    KFC(&s, &cnt_up, &cnt_lo);

    cout << "대문자" << cnt_up << "개" << endl;
    cout << "소문자" << cnt_lo << "개" << endl;

    return 0;
}