#include <iostream>
using namespace std;

int main(){
    int a;

    cin >> a;
    for (int j=0; j<3; j++){
        for (int i=0; i<5; i++){
            cout << a;
        }
        cout << endl;
    }

    for (int j=0; j<3; j++){
        for (int i=0; i<3; i++){
            cout << a;
        }
        cout << endl;
    }

    return 0;
}
