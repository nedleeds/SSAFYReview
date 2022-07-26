#include <iostream>
using namespace std;

string branch = "ABC";
char path[10];

void func(int level){
    if (level == 2) {
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
    
    func(0);

    return 0;
}