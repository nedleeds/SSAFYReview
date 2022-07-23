#include <iostream>
using namespace std;

int main(){
    
    int a;
    char gd;

    int *p = &a;
    char *c = &gd;

    cin >> a >> gd;
    
    cout << *p << " ";
    cout << *c << endl;
    
    return 0;
}
