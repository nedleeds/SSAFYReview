#include <iostream>
using namespace std;

int main(){
    char arr[2]; 
    
    for (int i=0; i<2; i++){
        cin >> arr[i];
        if ('a' <= arr[i] && arr[i] <= 'z'){
            arr[i] += 'A'-'a';
        }else if('A' <= arr[i] && arr[i] <= 'Z'){
            arr[i] -= 'A'-'a';
        }
    }

    for (int j=0; j<2; j++){
        cout << arr[j] << " ";
    }
    cout << endl;

    return 0;
}