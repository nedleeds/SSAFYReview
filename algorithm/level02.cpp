#include <iostream>
#include <string>
using namespace std;

int main(){
    char alphabets[8] = "ABCZETQ";
    char blacklist[6];

    for (int i=0; i<5; i++){
        cin >> blacklist[i];
    }

    int j;
    for (int i=0; i<5; i++){
        cout << blacklist[i] << "=";
        for (j=0; j<8; j++){
            if (blacklist[i] == alphabets[j]){
                cout << "마을사람" << endl;
                break;
            }
        }
        if (j==8){
            cout << "외부사람" << endl;
        }
    }

    return 0;
}