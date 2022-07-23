#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1, s2, s3;

    cin >> s1 >> s2 >> s3;

    int l1 = s1.length();
    int l2 = s2.length();
    int l3 = s3.length();
    
    if (l1 > l2 && l1 > l3){
        cout << s1 << endl;
    }else if (l2 > l3 && l2 > l1){
        cout << s2 << endl;
    }else if (l3 > l1 && l3 > l2){
        cout << s3 << endl;
    }

    return 0;
}