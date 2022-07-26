#include <iostream>
using namespace std;

struct Point {
    int row = 5;
    int col = 5;
}p;

void process(string s) {
    if (s == "up") {
        p.row += -1;
        p.col += 0;
    }
    else if (s == "down") {
        p.row += 1;
        p.col += 0;
    }
    else if (s == "left") {
        p.row += 0;
        p.col += -1;
    }
    else if (s == "right") {
        p.row += 0;
        p.col += +1;
    }
    else if (s == "click") {
        cout << p.row << "," << p.col << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    int t;
    string s;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s;
        process(s);
    }

    return 0;
}