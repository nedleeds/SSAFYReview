#include <iostream>
using namespace std;

int run(int *num){
    if (*num%3==0){
        return 7;
    }else if (*num%3==1){
        return 35;
    }else{
        return 50;
    }
}

int main(){
    
    int n;

    cin >> n;
    cout << run(&n) << endl;

    return 0;
}
