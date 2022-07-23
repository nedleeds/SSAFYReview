#include <iostream>
using namespace std;

void INPUT(int *a){
    cin >> *a;
}

void CountDown(int *a){
    for (int i=*a; i>=1; i--){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    int a;

    INPUT(&a);
    CountDown(&a);
    
    return 0;
}
