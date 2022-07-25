#include <iostream>
using namespace std;

int apt[5][3] = {
    {15, 18, 17},
    {4, 6, 9},
    {10, 1, 3},
    {7, 8, 9}, 
    {15, 2, 6}
};
int family[3];

int isPattern(int floor) {
    for (int i=0; i<2; i++){
        if (family[i] != apt[floor][i]){
            return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    for (int i=0; i<3; i++){
        cin >> family[i];
    }

    for (int floor=4; floor>=0; floor--){
        int r = isPattern(floor);
        if (r){
            cout << 5-floor <<"층\n";
        }
        
    }

    return 0;
} 
