#include <iostream>
#include <string>
using namespace std;

void swap(char *a, char *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    char a, b;
    char *p_a = &a; 
    char *p_b = &b;

    cin >> a >> b;
    swap(&a, &b);

    cout << a << " " << b << endl;

    return 0;
}