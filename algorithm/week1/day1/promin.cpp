#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int DAT[26]={0}; //Direct Address Table.
    int n;
    string S;
    cin >> S;

    for (int i=0; i<S.length(); i++){
        DAT[S[i]-'A']++;
    }

    int M = 0;
    for (int j=0; j<26; j++){
        if (M < DAT[j]){
            M = DAT[j];
        }
    }

    cout << char(DAT[M] + 'A') << "\n";
    
    return 0;
} 
