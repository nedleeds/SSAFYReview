#include <iostream>
using namespace std;

string s[3];

int main() {
    
    int M = 0, M_idx;

    for (int i = 0; i < 3; i++) {
        cin >> s[i];
        if (s[i].length() > M) {
            M = s[i].length();
            M_idx = i;
        }
    }

    string tmp;
    tmp = s[0];
    s[0] = s[M_idx];
    s[M_idx] = tmp;

    for (int i = 0; i < 3; i++) {
        cout << s[i] << "\n";
    }

    return 0;
}