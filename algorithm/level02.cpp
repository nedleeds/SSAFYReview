#include <iostream>
#include <string>
using namespace std;

int main(){
    string s[5];
    int M_idx, M=0;

    for (int i=0; i<5; i++){
        cin >> s[i];
        int l = s[i].length();
        if (M < l){
            M_idx = i;
            M = l;
        }
    }

    cout << s[M_idx] << endl;

    return 0;
}