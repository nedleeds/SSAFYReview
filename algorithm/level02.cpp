#include <iostream>
using namespace std;

int main(){
    char s[8];
    char big[8], small[8];

    for (int i=0; i<8; i++){
        cin >> s[i];
    }

    int b=0, sm=0;
    for (int j=0; j<8; j++){
        if ('A' <= s[j] && s[j] <= 'Z'){
            big[b] = s[j];
            b++; 
        }else if('a' <= s[j] && s[j] <='z'){
            small[sm] = s[j];
            sm++;
        }
    }

    cout << "big=";
    for (int i=0; i<b; i++){
        cout << big[i];
    }
    cout << endl;
    cout << "small=";
    for (int j=0; j<sm; j++){
        cout << small[j];
    }
    cout << endl;


    return 0;
}