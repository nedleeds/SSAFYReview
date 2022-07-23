#include <iostream>
using namespace std;

int main(){
    
    int arr[7];
    int MIN=9999, MAX=0;

    for (int i=0; i<7; i++){
        cin >> arr[i];
        if (arr[i] > MAX){
            MAX = arr[i];
        }else if (arr[i] < MIN){
            MIN = arr[i];
        }
    }

    cout << "MAX=" << MAX << endl;
    cout << "MIN=" << MIN << endl;
    
    return 0;
}
