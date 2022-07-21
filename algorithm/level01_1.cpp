#include <iostream>
using namespace std;

int main(){
    char arr[6]={'D', 'T', 'A', 'B', 'W', 'Q'};
    char a;

    cin >> a;

    for (int i=0; i<6; i++){
        if (arr[i]==a){
            cout << i << "번 INDEX" << endl;
            break;
        }
    }

    return 0;
}
