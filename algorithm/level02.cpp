#include <iostream>
using namespace std;

int main(){
    char a, b, arr[6]={'D', 'F', 'G', 'D', 'A', 'Q'};

    cin >> a >> b;

    for (int i=0; i<6; i++){
        if (a <= arr[i] && arr[i] <= b){
            cout << "발견!!!" << endl;
        }
    }

    cout << "미발견!!!" << endl;


    return 0;
}