#include <iostream>
using namespace std;

int a, b;

int main(){
    int arr[6], i;

    for (int i=0; i<6; i++){
        cin >> arr[i];
    }

    for (int j=5; j>=0; j--){
        cout << arr[j] << " ";
        if (arr[j]==7){
            break;
        }
    }
    cout << endl;

    return 0;
}
