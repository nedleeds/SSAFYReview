#include <iostream>
#include <string>
using namespace std;

int main(){
    char s1[10] = "DATAPOWER";
    char s2[9];
    int i1, i2;

    cin >> i1 >> i2;
    
    int x=0;
    for (int i=i1; i<=i2; i++){
        s2[x++] = s1[i];
    }

    for (int i=0; i<i2-i1+1; i++){
        cout << s2[i];
    }
    cout << endl;

    return 0;
}