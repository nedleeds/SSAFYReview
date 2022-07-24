#include <iostream>
#include <string>
using namespace std;

struct Mart{
    int st, ml, wt;
};

int main(){
    char mart;

    Mart A = {300, 500, 1000};
    Mart B = {450, 450, 900};
    Mart C = {200, 150, 700};

    cin >> mart;

    if (mart == 'A') cout << int((A.st + A.ml + A.wt)/3) << endl;
    else if (mart == 'B') cout << int((B.st + B.ml + B.wt)/3) << endl;
    else if (mart == 'C') cout << int((C.st + C.ml + C.wt)/3) << endl;

    return 0;
}