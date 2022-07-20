#include <iostream>
using namespace std;

int main(){
    char num[6] = {'$','@','D','A','9','#'};

    for (int j=0; j<6; ++j){
        cout << num[j] << ":" << int(num[j]) << endl;
    }
    
    return 0;
}