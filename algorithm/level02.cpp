#include <iostream>

using namespace std;

void printData(int x);
int even(int value);
int odd(int value);

int main()
{
    int a, b;
    
    cin >> a >> b;
    
    if ((a/b)%2 ==0 ){
        even(a/b);
    }else{
        odd(a/b);
    }
    printData(a+b);

    return 0;
}

void printData(int x){
    cout << x << endl;
}
int even(int value){
    printData(value*2);
}

int odd(int value){
    printData(value-10);
}
