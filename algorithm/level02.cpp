#include <iostream>
using namespace std;

struct BBQ{
    int x;
    int data[3];
};


int main(){
    int s=0;
    BBQ g;

    cin >> g.x >> g.data[0] >> g.data[1] >> g.data[2];

    for (int i=0; i<3; i++){
        s += g.data[i];
    }
    
    cout << s << " " << g.x;
    
    return 0;
}
