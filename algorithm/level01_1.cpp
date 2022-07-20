#include <iostream>
using namespace std;

int main(){
    int num;

    cin >> num;

    for (int j=0; j<num; ++j){
        for (int i=0; i<5; ++i){
            cout << i+1 << " ";
        }
        cout << endl;
    }
    
    return 0;
}