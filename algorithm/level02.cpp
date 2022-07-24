#include <iostream>
#include <string>
using namespace std;

void reverse(string *s){
    char tmp;
    int l = (*s).length();
    for (int i=0; i<(l/2); i++){
        tmp = (*s)[i];
        (*s)[i] = (*s)[l-i-1];
        (*s)[l-i-1] = tmp;
    }
}

int main(){
    string s1, s2;

    cin >> s1 >> s2;
    reverse(&s2);
    if (s1 == s2){
        cout << "거울문장" << endl;
    }else {
        cout << "거울문장아님" << endl;
    }

    return 0;
}