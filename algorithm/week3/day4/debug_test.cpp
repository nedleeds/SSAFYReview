#include <iostream>
using namespace std;

int main(){
    string hi;
    cin >> hi;
    cout << "Multiplication Table\n";
    int n = 5;
    
    for (int i=0; i<10; i++){
        cout << n << " * " << i << " = " << n * i << '\n';
    }

    return 0;
}