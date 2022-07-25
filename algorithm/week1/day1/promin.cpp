#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int DAT[10]={0};
    for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            int tmp;
            cin >> tmp;
            DAT[tmp]++;
        }
    }

    for (int j=1; j<=9; j++){
        if (DAT[j]==0){
            cout << j << " ";
        }
    }
    cout << "\n";
    
    return 0;
} 
