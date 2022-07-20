#include <iostream>
using namespace std;

char arr[2];

void INPUT(){
    int i;
    cin >> arr[0] >> arr[1];
}

void OUTPUT(){
    int i;

    for (i=0; i<2; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    
    INPUT();
    OUTPUT();
    
    return 0;
}