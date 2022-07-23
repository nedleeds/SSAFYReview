#include <iostream>
using namespace std;

int main(){
    
    char a, b, c;
    char *p_a = &a, *p_b = &b, *p_c = &c;

    cin >> a >> b >> c;
    
    cout << (char)(*p_a+1) << " " << ++(*p_b) << " " << ++(*p_c) << endl;
    
    return 0;
}
