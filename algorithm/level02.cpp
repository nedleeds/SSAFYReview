#include <iostream>
#include <string>
using namespace std;

int main(){
    int a, b;
    char c, d;
    int *p1 = &a, *p2 = &b;
    char *p3 = &c, *p4 = &d;
    
    cin >> a >> b >> c >> d;

    for (int i=0; i<*p1; i++){
        cout << *p3;
    }
    cout << endl;
    for (int j=0; j<*p2; j++){
        cout << *p4;
    }
    cout << endl;

    return 0;
}