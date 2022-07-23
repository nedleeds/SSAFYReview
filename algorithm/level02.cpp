#include <iostream>
using namespace std;

int main(){
    
    int a, b;
    int *p_a = &a, *p_b = &b, *tmp;

    cin >> a >> b;

    tmp = p_a;
    p_a = p_b;
    p_b = tmp;

    cout << *p_a << " " << *p_b << endl;

    
    return 0;
}
