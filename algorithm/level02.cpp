#include <iostream>
using namespace std;

int main(){
    int r, c; 
    int arr[5][5] = {
        {4, 5, 4, 5, 4},
        {8, 9, 8, 9, 8},
        {1, 2, 1, 2, 1},
        {4, 5, 4, 5, 4},
        {6, 7, 6, 7, 6}
    };

    for (int i=0; i<5; i++){
        cin >> r >> c;
        arr[r][c]++;
        arr[r][c] = (arr[r][c] % 10);
    }

    for (int r=0; r<5; r++){
        for (int c=0; c<5; c++){
            cout << arr[r][c];
        }
        cout << endl;
    }


    return 0;
}