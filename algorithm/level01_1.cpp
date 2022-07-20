#include <iostream>
using namespace std;

int main(){
    int num,s, i;
    int arr[5];
    
    s = 0;
    for (i=0; i<5; i++){
        cin >> arr[i];
        s += arr[i];
    }

    cout << "합은" << s << "입니다" << endl;

    return 0;
}