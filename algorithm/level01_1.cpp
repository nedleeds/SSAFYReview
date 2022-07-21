#include <iostream>
using namespace std;

int main(){
    char arr[5];
    int n;

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    for (int j=0; j<n; j++){
        cout << arr[j];
    }
    cout << endl;
    return 0;
}
