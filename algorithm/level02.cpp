#include <iostream>
using namespace std;

int sum(int *a, int *b){
    int s = *a + *b;
    return s;
}

int sub(int *a, int *b){
    int s = *a - *b;
    return s;
}

void print(int *a, int *b){
    cout << "합:" << *a << endl;
    cout << "차:" << *b << endl;
}

int main(){
    
    int a, b, s1, s2;
    cin >> a >> b;
    
    s1 = sum(&a, &b);
    s2 = sub(&a, &b);
    print(&s1, &s2);
    
    return 0;
}
