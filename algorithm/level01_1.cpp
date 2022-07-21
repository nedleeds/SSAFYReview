#include <iostream>
using namespace std;

int main(){
    char arr[5], arr2[5]; 
    char a, og;
    cin >> a;
    og = a;
    
    for(int i=0; i<5; i++){
        arr[i] = a;
        a++;
    }
    for(int j=0; j<5; j++){
        arr2[j] = og;
        og--;
    }
    for(int i=0; i<5; i++){
        cout << arr[i];
    }
    cout << endl;
    for(int j=0; j<5; j++){
        cout << arr2[j];
    }
    cout << endl;
    return 0;
}