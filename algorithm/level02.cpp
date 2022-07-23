#include <iostream>
#include <string>
using namespace std;

struct NODE{
    int x;
    int y;
}ta, tb;

int main(){
    cin >> ta.x >> tb.x;
    
    ta.y = ta.x + 5;
    tb.y = tb.x - 5;

    cout << "ta.x=" << ta.x << endl; 
    cout << "ta.y=" << ta.y << endl; 
    cout << "tb.x=" << tb.x << endl; 
    cout << "tb.y=" << tb.y << endl; 

    return 0;
}