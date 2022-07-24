#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int arr[6];
    int curr, check;

    for (int i=0; i<6; i++){
        cin >> arr[i];
    }

    for (int j=0; j<6; j++){
        for (int k=j+1; k<6; k++){
            if (arr[j] < arr[k]){
                swap(&arr[j], &arr[k]);
            }
        }
    }

    for (int i=0; i<6; i++){
        cout << arr[i];
    }

    cout << endl;

    return 0;
}