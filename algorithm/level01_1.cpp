#include <iostream>
using namespace std;

int main(){

    int arr[5];

    for (int i=0; i<5; i++){
        cin >> arr[i];
    }

    for (int j=0; j<5; j++){
        if (arr[j] >= 70){
            cout << j+1 << "번사람은" << arr[j] <<"점PASS" << endl;
        }else if(arr[j] >= 50 && arr[j] <70){
            cout << j+1 << "번사람은" << arr[j] <<"점RETEST" << endl;
        }else{
            cout << j+1 << "번사람은" << arr[j] <<"점FAIL" << endl;
        }
    }

    return 0;
}
