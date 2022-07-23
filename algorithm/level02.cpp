#include <iostream>
using namespace std;

char arr[8] = {'A', '1', '1', '1', '5', 'A', 'w', 'z'};

int Count(char *c){
    int cnt=0;
    for (int r=0; r<8; r++){
        if (arr[r] == *c){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    char c;
    int cnt;

    cin >> c;
    cnt = Count(&c);

    if ( cnt >= 3 ){
        cout << "THREE" << endl;
    } else if ( cnt == 2 ){
        cout << "TWO" << endl;
    } else if ( cnt == 1 ){
        cout << "ONE" << endl;
    } else if ( cnt == 0 ){
        cout << "NOTHING" << endl;
    }

    return 0;
}