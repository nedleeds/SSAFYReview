#include <iostream>
#include <string>
using namespace std;

int main(){
    int students[6];

    for (int i=0; i<6; i++){
        cin >> students[i];
    }
    
    for (int j=0; j<5; j++){
        if ((students[j]-students[j+1]) > -3 && (students[j]-students[j+1]) < 3){
            ;
        }else{
            cout << "재배치필요" << endl;
            return 0;
        }
    }
    cout << "완벽한배치" << endl;
    return 0;
}