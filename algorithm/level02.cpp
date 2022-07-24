#include <iostream>
#include <string>
using namespace std;

int main(){
    char a, b, c;
    char *pa = &a, *pb = &b, *pc = &c;

    cin >> a >> b >> c;

    if (*pa >= *pb && *pa >= *pc){
        cout << *pa << endl;
        return 0;
    }
    if (*pb >= *pa && *pb >= *pc){
        cout << *pb << endl;
        return 0;
    }if (*pc >= *pa && *pc >= *pb){
        cout << *pc << endl;
        return 0;
    }

    return 0;
}