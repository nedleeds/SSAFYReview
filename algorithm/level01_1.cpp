#include <iostream>
using namespace std;

int main(){
    int arr[5], arr2[5];
    
    for (int i=0; i<5;i++){
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    for (int i=0; i<5;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i=0; i<5;i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}