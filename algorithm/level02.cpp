#include <iostream>
#include <string>
using namespace std;

void CountLine(string *s){
    cout << (*s).length() << "=" << *s << endl;
}

int main(){
    string s[2], s2;

    for (int i=0; i<2; i++){
        cin >> s[i];
        s2.append(s[i]);
    }

    cout << s2 << endl;

    return 0;
}