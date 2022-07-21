#include <iostream>
using namespace std;

int main(){
    char arr[3][5] = {{'A', 'B', 'C', 'D', 'E'},
                      {'E', 'A', 'B', 'A', 'B'},
                      {'A', 'C', 'D', 'E', 'R'}};
    char a; 
    int cnt = 0;

    cin >> a;
    cnt = 0;
    for (int i=0; i<3; i++){
        for (int j=0; j<5; j++){
            if (arr[i][j] == a){
                cnt++;
            }
        }
    }

    if (cnt>=3){
        cout << "대발견\n";
    } else if(1<= cnt && cnt <3){
        cout << "발견\n";
    } else if (cnt == 0){
        cout << "미발견\n";
    }

    return 0;
}