#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int arr[2][3]){
    int n[6];

    int idx = 0;
    for (int r=0; r<2; r++){
        for (int c=0; c<3; c++){
            n[idx++] = arr[r][c];
        }
    }

    for (int i=0; i<5; i++){
        for (int j=i+1; j<6; j++){
            if (n[i] > n[j]){
                swap(&(n[i]), &(n[j]));
            }
        }
    }

    idx = 0;
    for (int r=0; r<2; r++){
        for (int c=0; c<3; c++){
            arr[r][c] = n[idx++];
        }
    }
}

int main(){
    int arr[2][3];

    for (int r=0; r<2; r++){
        for (int c=0; c<3; c++){
            cin >> arr[r][c];
        }
    }
    sort(arr);

    for (int r=0; r<2; r++){
        for (int c=0; c<3; c++){
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }

    return 0;
}