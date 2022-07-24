#include <iostream>
#include <string>
using namespace std;

int main(){
    int arr[9] = {0};
    int idx_s, idx_e;

    for (int j=0; j<3; j++){
        cin >> idx_s >> idx_e;

        for (int i=idx_s; i<=idx_e; i++){
            arr[i]++;
        }
    }

    for (int i=0; i<9; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}