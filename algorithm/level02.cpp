#include <iostream>
#include <string>
using namespace std;

int main(){
    int A[5], B[5], C[5];
    
    for (int i=0; i<5; i++){
        cin >> A[i];
    }
    for (int i=0; i<5; i++){
        cin >> B[i];
    }
    for (int i=0; i<5; i++){
        cin >> C[i];
    }
    for (int i=0; i<5; i++){
        cout << A[i] * B[i] + C[i]  << " ";
    }
    cout << endl;
    
    return 0;
}