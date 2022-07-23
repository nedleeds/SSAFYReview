#include <iostream>
#include <string>
using namespace std;

int main(){
    string arr = "ABCDEFG";
    int arr2[7] = {4, 2, 5, 1, 6, 7, 3};
    int a_i, b_i, s = 0;
    char a, b;

    cin >> a >> b;
    a_i = a - 'A';
    b_i = b - 'A';

    if (a_i > b_i){
        for (int i=b_i+1; i<a_i; i++){
            s += arr2[i];
        }
    }else{
        for (int j=a_i+1; j<b_i; j++){
            s += arr2[j];
        }
    }

    cout << s << endl;

    return 0;
}