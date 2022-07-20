#include <iostream>
using namespace std;

int main(){
    char alpha;
    cin >> alpha;

    cout << char(int(alpha) + 'A'-'a') << endl;

    return 0;
}