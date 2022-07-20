#include <iostream>
using namespace std;

int main(){
    char alphas[3];

    for (int i=0; i<3; ++i){
        cin >> alphas[i];
    }

    for (int j=0; j<3; ++j){
        cout << int(alphas[j]) << endl;
    }
    
    return 0;
}