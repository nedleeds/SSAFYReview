#include <iostream>
using namespace std;

int train[] = {3, 7, 6, 4, 2, 9, 1, 7};
int team[3] = {0};

int isTeam(int j)
{
    for (int i=0; i<2; i++){
        if (train[j+i]!=team[i]){
            return 0;
        }
    }
    return j;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    for (int i=0; i<3; i++){
        cin >> team[i];
    }

    for (int j=0; j<5; j++){
        int r = isTeam(j);
        if (r){
            cout << r << "번~" << j+2 <<"번 칸\n";
        }
        
    }

    return 0;
} 
