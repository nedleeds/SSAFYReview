#include <iostream>
#include <string>
using namespace std;

void ABC(int a, int b, int *SUM, int *GOP){
    *SUM = a + b;
    *GOP = a * b;
}

int main(){
    int a, b, s, g;
    cin >> a >> b;

    ABC(a, b, &s, &g);

    cout << s << " " << g << endl;

    return 0;
}