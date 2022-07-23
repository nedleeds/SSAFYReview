#include <iostream>
#include <string>
using namespace std;

int main(){
    
    string str1 = "StructPointer";
    char c;
    cin >> c;

    if (str1.find(c)!=string::npos){
        cout << "발견" << endl;
    }else{
        cout << "미발견" << endl;
    }
    
    return 0;
}
