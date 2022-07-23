#include <iostream>
using namespace std;

char aToZ(){
    char c;
    cin >> c;
    if (c-'A' > 'Z'-c){
        return 'Z';
    }else{
        return 'A';
    }
}

int main(){
    
    cout << aToZ() << endl;

    return 0;
}
