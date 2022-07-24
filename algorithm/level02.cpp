#include <iostream>
#include <string>
using namespace std;

int main(){
    int juso[8]={
        402, 401, 302, 301,
        202, 201, 102, 101
    };
    char name[8][5]={
        "KIM", "TEA", "SOM", "OPPO",
        "TOM", "GDK", "JAME", "MIN"
    };

    int num;
    cin >> num;

    for (int i=0; i<8; i++){
        if (juso[i]==num){
            for (int j=0; j<5; j++){
                if (name[i][j]!='\0'){
                    cout << name[i][j];
                }else{
                    cout << endl;
                    return 0;
                }
            }
        }
        
    }   

    return 0;
}