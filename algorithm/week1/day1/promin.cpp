#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int DAT[27]={0}; //Direct Address Table.
    int n;
    string ss;
    cin >> ss;

    for (int i=0; i<ss.length(); i++){
        DAT[ss[i]-'A']++;
    }

    int s = 0;
    for (int j=0; j<27; j++){
        if (DAT[j]>0){
            s++;
        }
    }
    cout << s << "개\n";
    
    return 0;
} 
