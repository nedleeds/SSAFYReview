#include <iostream>
#include <string>
using namespace std;

int main(){
    int a;

    cin >> a;
    
    int w = a / 1000;
    int x = a / 100 % 10;
    int y = a / 10 % 10;
    int z = a % 10;

    cout << "숫자" << w << endl;
    cout << "숫자" << x << endl;
    cout << "숫자" << y << endl;
    cout << "숫자" << z << endl;

    return 0;
}