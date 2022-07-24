#include <iostream>
using namespace std;

int main(){
    int shrimp[5][5];
    int triangle;
    cin >> triangle;

    for (int r=0; r<5; r++){
        for (int c=0; c<5; c++){
            cin >> shrimp[r][c];
        }
    }

    if (triangle == 1){
        for (int r=0; r<5; r++){
            for (int c=0; c<=r; c++){
                cout << shrimp[r][c] << " ";
            }
            cout << endl;
        }
    }else if(triangle==2){
        for (int r=0; r<5; r++){
            for (int c=0; c<5-r; c++){
                cout << shrimp[r][c] << " ";
            }
            cout << endl;
        }
    } 

    return 0;
}