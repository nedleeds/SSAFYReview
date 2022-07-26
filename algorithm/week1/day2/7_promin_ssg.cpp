#include <iostream>
using namespace std;

int lvl;
int path[100] = {0};

void f(int level) {
    
    cout << level;
    if (level == lvl) {
        return ;
    }

    for (int i = 0; i < 2; i++) {
        f(level + 1);
    }
}

int main() {
    cin >> lvl ;

    f(0);

    return 0;
}