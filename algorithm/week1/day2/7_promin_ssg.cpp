#include <iostream>
using namespace std;

string branch = "BGTK";
char path[10];
int lvl;

void func(int level) {
    if (level == lvl) {
        cout << path << "\n";
        return ;
    }

    for (int i = 0; i < branch.length(); i++) {
        path[level] = branch[i];
        func(level + 1);
        path[level] = '\0';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    cin >> lvl;
    func(0);

    return 0;
}