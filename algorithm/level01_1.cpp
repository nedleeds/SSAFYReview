#include <iostream>
using namespace std;

int main(){
    char arr1[6] = {'#', '_', '#', '_', '#', '#'};

    for (int i=0; i<6; i++){
        if (arr1[i]=='#'){
            cout << "샵";
        }else if (arr1[i]=='_'){
            cout << "무";
        }
    }
    cout << endl;


    return 0;
}
