#include <iostream>
using namespace std;

int main(){
    int num, i;
    int arr[6];
    cin >> num;

    for (i=0; i<6; i++){
        arr[i] = num*(i+1);
    }

    for (i=0; i<6; i++){
        cout << arr[i] << " ";
    } 
    cout << endl;

    return 0;
}