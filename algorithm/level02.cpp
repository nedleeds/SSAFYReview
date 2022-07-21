#include <iostream>
using namespace std;
void SWAP(int arr[6][2], int *cnt){
    int tmp;

    for (int r=0; r<6; r++){
        tmp = arr[r][0];
        if (arr[r][0] < arr[r][1]){
            arr[r][0] = arr[r][1];
            arr[r][1] = tmp;
            (*cnt)++;
        }
    }

}

int main(){
    int arr[6][2], cnt=0;

    for (int i=0; i<6; i++){
        for (int j=0; j<2; j++){
            cin >> arr[i][j];
        }
    }

    SWAP(arr, &cnt);

    for (int i=0; i<6; i++){
        for (int j=0; j<2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << cnt << "명" << endl;

    return 0;
}