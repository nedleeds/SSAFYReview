#include <iostream>
using namespace std;

int MAP[3][4] = {
    {65000, 35, 42, 70},
    {70, 35, 65000, 1300},
    {65000, 30000, 38, 42}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int DAT[65535]={0};
    for (int r=0; r<3; r++){
        for (int c=0; c<4; c++){
            DAT[MAP[r][c]]++;
        }
    }

    int M=0, id=0;
    for (int i=0; i<65535; i++){
        if (M < DAT[i]){
            M = DAT[i];
            id = i;
        }
    }
    cout << id << "\n";
    
    return 0;
} 
