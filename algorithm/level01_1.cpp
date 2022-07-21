#include <iostream>
using namespace std;

void starBox(){
    for (int i=1; i<20; i=i+2){
        cout << i << " ";
    }
}

void macDoll(){
    for (char c='H'; c>='A'; c--){
        cout << c << " ";
    }
}

void copyBean(){
    for (int j=-5; j<6; j++){
        cout << j << " ";
    }
}

int main(){
    int price;
    cin >> price;

    if (3500 <= price && price <= 5000){
        starBox();
    }else if(2500 <= price && price < 3500){
        macDoll();
    }else{
        copyBean();
    }
    cout << endl;
    return 0;
}
