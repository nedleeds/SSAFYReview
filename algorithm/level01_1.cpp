#include <iostream>
using namespace std;

int main(){
    int arr[6];

    for (int i=0; i<6; i++){
        cin >> arr[i];
    }

    for (int j=0; j<6; j++){
        if (arr[j] < 5){
            cout << j << "번은 " << arr[j] << "점 불합격" << endl;
        }else {
            cout << j << "번은 " << arr[j] << "점 합격" << endl;
        }
    }

    return 0;
}
