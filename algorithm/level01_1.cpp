#include <iostream>
using namespace std;

int main(){
    int a, b, i;
    int arr[6] = {0, };
    
    cin >> a >> b;

    for (i=a; i<=b; i++){
        arr[i] = i;
    }

    for (i=a; i<=b; i++){
        cout << arr[i];
    }
    cout << endl;
    return 0;
}