#include <iostream>
using namespace std;

int main(){
    char num[4] = {'B', 'T', 'K', 'A'};
    int a;

    cin >> a;

    for (int i=0; i<a; i++){
        for (int j=0; j<4; j++){
            cout << num[j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}