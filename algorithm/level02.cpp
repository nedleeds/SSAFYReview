#include <iostream>

using namespace std;

int chicken(){
    int a;
    cin >> a;
    return a+10;
}

char coke(){
    char a;
    cin >> a;
    return a;
}

void KFC(){
    int a = chicken();    
    char b = coke();

    cout << a << b << endl;
}

int main()
{
    KFC();
    return 0;
}