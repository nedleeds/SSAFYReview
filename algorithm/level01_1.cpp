#include <iostream>
using namespace std;

int arr[3][4];

void input(){
    int a;
    cin >> a;
    for (int r=0; r<3; r++){
        for (int c=0; c<4; c++){
            arr[r][c] = a;
            a++;
        }
    }
}

void process(){
    for (int r=0; r<3; r++){
        for (int c=0; c<4; c++){
            arr[r][c] += 1;
        }
    }
}

void output(){
    for (int r=0; r<3; r++){
        for (int c=0; c<4; c++){
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    input();
    process();
    output();
    
    return 0;
}
