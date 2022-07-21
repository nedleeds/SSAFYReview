#include <iostream>
using namespace std;

int main(){
    int arr[6] = {3, 4, 2, 5, 7, 9};
    int a, b, tmp;
    cin >> a >> b;
    
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;

    for (int i=0; i<6; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}