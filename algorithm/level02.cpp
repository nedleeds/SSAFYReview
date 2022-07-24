#include <iostream>
#include <string>
using namespace std;


int main(){

    int vect[7] = {3, 5, 1, 1, 2, 3, 2};
    int arr[4], cnt[4]={0,}; 

    for (int r=0; r<4; r++){
        cin >> arr[r];
    }

    for (int j=0; j<4; j++){    
        for (int i=0; i<7; i++){
            if (vect[i] == arr[j]){
                cnt[j]++;
            }
        }
    }

    for (int i=0; i<4; i++){
        cout << arr[i] << "=" << cnt[i] << "개" << endl;
    }

    return 0;
}