#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    char alphabet[5][3] = {
        {'A', 'B', 'C'},
        {'A', 'G', 'H'},
        {'H', 'I', 'J'},
        {'K', 'A', 'B'},
        {'A', 'B', 'C'}
    };
    int DAT[26] = {0};

    for (int r=0; r<5; r++){
        for (int c=0; c<3; c++){
            DAT[alphabet[r][c] - 'A']++;
        }
    }

    for (int i=0; i<26; i++){
        if (DAT[i]){
            for (int j=0; j<DAT[i]; j++){
                cout << char(i + 'A');
            }
        }
    }
    cout << "\n";

    return 0;
} 
