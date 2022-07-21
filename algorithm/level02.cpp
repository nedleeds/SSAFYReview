#include <iostream>
using namespace std;

char arr[2][3] = {{'F', 'E', 'W'},
                  {'D', 'C', 'A'}};

void findCh(char *a){
    int cnt=0;
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            if (arr[i][j]==*a){
                cout << "발견" << endl;
                return ;
            }
        }
    }
    cout << "미발견" << endl;
}

int main(){
    char a;
    cin >> a;
    findCh(&a);

    return 0;
}