#include <iostream>

using namespace std;


int one(){
    int x;
    cin >> x;
    return x;
}

char two(){
    char c;
    cin >> c;
    return c;
}

int main()
{
    int a;
    char b;
    
    a = one();
    b = two();
    
    cout << a << b << endl;
    
    return 0;
}