#include <iostream>
#include <string>
using namespace std;

char arr[3][3] = {
    {'D', 'A', 'S'},
    {'Q', 'W', 'V'},
    {'R', 'T', 'Y'}
};

void Find(int *r1, int *c1, int *r2, int *c2){
    cout << arr[*r1][*c1] << " " << arr[*r2][*c2] << endl;
}

int main(){
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    Find(&r1, &c1, &r2, &c2);

    return 0;
}