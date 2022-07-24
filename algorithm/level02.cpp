#include <iostream>
using namespace std;

int main(){
    int a;
    cin >> a;

    int d = 0;
    while (d < 3){
        int c = 0;
        while (c<5){
            cout << a;
            c++;
        }
        cout << endl;
        d++;
    }
    

    return 0;
}