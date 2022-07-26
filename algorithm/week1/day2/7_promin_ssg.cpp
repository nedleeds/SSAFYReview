#include <iostream>
using namespace std;

string id = "qlqlaqkq";
string passwd = "tkaruqtkf";


int main() {
    string i, p;
    cin >> i;
    cin >> p;

    if (i == id && p == passwd) {
        cout << "LOGIN\n";
    }
    else {
        cout << "INVALID\n";
    }

    return 0;
}