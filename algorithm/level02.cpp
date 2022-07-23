#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;

    cin >> s;
    int l = s.length();
    cout << l << endl;

    int cnt=0;
    for (int i=0; i<l; i++){
        if(s[i]==s[l-1]){
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}