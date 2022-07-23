#include <iostream>
using namespace std;

void calc(int *a, int *b, int *c){
    int s = *a + *b + *c;
    cout << s << endl;
}

int main(){
    
    int a, b, c;

    cin >> a >> b >> c;

    calc(&a, &b, &c);

    return 0;
}
