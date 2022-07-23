#include <iostream>
#include <string>
using namespace std;

void moon(int *age, int *x, int *y, int*z){
    *x = *age - 4;
    *y = *age + 3;
    *z = *age * 2;
}

int main(){
    int age, x, y, z;

    cin >> age;
    moon(&age, &x, &y, &z);

    cout << x << " " << y << " " << z << endl;

    return 0;
}