#include <iostream>
#include <string>
using namespace std;

struct FileDown{
    int dn[2];
}fd;

int main(){

    cin >> fd.dn[0] >> fd.dn[1];

    int cnt, a, b;
    
    a = 100-fd.dn[0];
    b = 100-fd.dn[1];

    if (a>b){
        cout << a;
    }else{
        cout << b;
    }
    cout << endl;

    return 0;
}