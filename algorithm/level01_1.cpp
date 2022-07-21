#include <iostream>
using namespace std;

void process(int a, int arr[3][3]){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            arr[i][j] = a;
            a++;
        }
    }
}

void output(int arr[3][3]){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int a, arr[3][3]={0,};

    cin >> a;
    process(a, arr);
    output(arr);

    return 0;
}
