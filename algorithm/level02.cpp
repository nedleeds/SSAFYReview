#include <iostream>
#include <string>
using namespace std;

int Length(string s, char x){
    int cnt = 0;
    for (int i=0; i<s.length(); i++){
        if (s[i]==x){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    string s;
    char x, y, z;

    cin >> s;
    if (s=="0"){
        cout << 0 << endl;
        return 0;
    }
    cin >> x >> y >> z;

    cout << x << "="<< Length(s, x) << endl;
    cout << y << "="<< Length(s, y) << endl;
    cout << z << "="<< Length(s, z) << endl;

    return 0;
}