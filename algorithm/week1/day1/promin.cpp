#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    char town[3][3] = {
        {'C', 'D', 'A'},
        {'B', 'M', 'Z'},
        {'Q', 'P', 'O'}
    };

    char black[4];
    int DAT[26] = {0};

    for (int i = 0; i < 4; i++){
        char c;
        cin >> c;
        black[i] = c;
    }

    for (int r = 0; r < 3; r++){
        for (int c = 0; c < 3; c++){
            DAT[town[r][c]-'A']++;
        }
    }

    int s = 0;
    for (int i = 0; i < 4; i++){
        if (DAT[black[i]-'A']){
            s++;
        }
    }
    cout << s << "명\n";

    return 0;
} 
