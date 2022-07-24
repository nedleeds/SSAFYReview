#include <iostream>
#include <string>
using namespace std;

void CountLine(string *s){
    cout << (*s).length() << "=" << *s << endl;
}

int main(){
    string s1, s2, s3;
    char c;

    cin >> s1 >> s2 >> s3;

    CountLine(&s1);
    CountLine(&s2);
    CountLine(&s3);

    return 0;
}