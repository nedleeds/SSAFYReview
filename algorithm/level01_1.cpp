#include <iostream>
using namespace std;

int a, b;

void input(){
    cin >> a >> b;
}

void output(){
    int i=5;
    while (i <= (a+b)){
        cout << i << " ";
        i++;
    }
    cout << endl;
}

int main(){
    int arr[6], i;

    input();
    output();

    return 0;
}
