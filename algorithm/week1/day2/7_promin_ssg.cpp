#include <iostream>
using namespace std;

string s;

void printing(int num) {
    cout << num << " ";
    
    if (num == 1) {
        return;
    }

    printing(num - 1);
    cout << num << " ";
    
}

int main() {
    
    cin >> s;
    int l = s.length();

    printing(l);

    return 0;
}