#include <iostream>
using namespace std;

int main(){
    int arr[6] = {0,};
    int i1, i2, i3;

    cin >> i1 >> i2 >> i3;
    
    arr[i1] = 1;
    arr[i2] = 1;
    arr[i3] = 1;

    for (int i=0; i<6; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
