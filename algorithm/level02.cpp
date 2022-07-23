#include <iostream>
using namespace std;

int main(){
    
    int arr[7] = {3, 4, 1, 3, 2, 7, 3};
    int n, flag=0;

    cin >> n;

    for (int i=0; i<7; i++){
        if(arr[i]==n){
            flag = 1;
        }
    }

    if (flag){
        cout << "발견" << endl;
    }else{
        cout << "미발견" << endl;
    }

    
    return 0;
}
