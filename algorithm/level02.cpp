#include <iostream>
#include <string>
using namespace std;

int main(){
    string s[2];

    for (int i=0; i<2; i++){
        cin >> s[i];
    }

    int cnt = 0;
    for (int i=0; i<8; i++){
        if (s[0][i] != s[1][i]){
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}