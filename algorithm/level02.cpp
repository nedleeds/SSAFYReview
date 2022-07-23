#include <iostream>
using namespace std;

void run(int *num, int arr[3][3]){
    int i=1;
    if (*num < 10){
        for (int r=0; r<3; r++){
            for (int c=0; c<3; c++){
                arr[r][c] = i++;
            }
        }
    }else{
        for (int r=0; r<3; r++){
            for (int c=2; c>=0; c--){
                arr[r][c] = i++;
            }
        }
    }
}

int main(){
    
    int n;
    int arr[3][3];

    cin >> n;
    run(&n, arr);
    
    for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            cout << arr[r][c];
        }
        cout << endl;
    }

    return 0;
}
