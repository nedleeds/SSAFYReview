#include <iostream>
using namespace std;


int main(){
    char a;
    int n;

    cin >> a >> n;

    for (int j=0; j<n; j++){
        for (int i=0; i<n; i++){
            cout << a;
        }
        cout << endl;
    }
    return 0;
}
