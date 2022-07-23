#include <iostream>
#include <string>
using namespace std;

int Length(string s, char x){
    return s.find(x);
}

int main(){
    string s1 = "MINQUEST";
    char x, y, z;

    cin >> x >> y >> z;
    
    cout << x << "="<< Length(s1, x) << endl;
    cout << y << "="<< Length(s1, y) << endl;
    cout << z << "="<< Length(s1, z) << endl;

    return 0;
}