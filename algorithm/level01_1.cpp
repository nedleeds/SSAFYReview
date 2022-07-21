#include <iostream>
using namespace std;

void BBQ(int *a){
    if (0 < *a && *a <5){
        cout << "초기값" << endl;
    }else if(6 < *a && *a <10){
        cout << "중간값" << endl;
    }else{
        cout << "알수없는값" << endl;
    }
}

int main(){
    int a;

    cin >> a;
    if (a==3 || a==5 || a==7){
        for (int i=0; i<10; i++){
            cout << i+1;
        }
        cout << endl;
    }else if(a==0 || a==8){
        for (int j=10; j>0; j--){
            cout << j;
        }
        cout << endl;
    }else{
        BBQ(&a);
    }

    return 0;
}
