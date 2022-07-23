#include <iostream>
#include <string>
using namespace std;

int CompareGo(int c1[5], int c2[5]){
    for (int i=0; i<5; i++){
        if (c1[i]!=c2[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    int arr1[5] = {3, 5, 1, 2, 7};
    int arr2[5];

    for (int i=0; i<5; i++){
        cin >> arr2[i];
    }

    if (CompareGo(arr1, arr2)){
        cout << "두배열은완전같음" << endl;
    }else{
        cout << "두배열은같지않음" << endl;
    }

    return 0;
}