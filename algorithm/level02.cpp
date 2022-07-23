#include <iostream>
#include <string>
using namespace std;

int Find(string *n1, string *n2, string *n3){
    if (*n1 == *n2  && *n2 == *n3){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    string name1, name2, name3;
    
    cin >> name1 >> name2 >> name3;

    if (Find(&name1, &name2, &name3)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}