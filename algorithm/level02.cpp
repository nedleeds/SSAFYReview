#include <iostream>
using namespace std;

char arr[3][5] = {
    {'a', 'b', 'a', 'c', 'z'},
    {'c', 't', 'a', 'c', 'd'},
    {'c', 'c', 'c', 'c', 'a'}
};

int Count(char *x){
    int cnt=0;
    for (int r=0; r<3; r++){
        for (int c=0; c<5; c++){
            if (arr[r][c] == *x){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    char c;
    int cnt;

    cin >> c;
    cnt = Count(&c);

    if ( cnt >= 7 ){
        cout << "세상에" << endl;
    } else if ( cnt >= 5 ){
        cout << "와우" << endl;
    } else if ( cnt >= 3 ){
        cout << "이야" << endl;
    } else {
        cout << "이런" << endl;
    }

    return 0;
}