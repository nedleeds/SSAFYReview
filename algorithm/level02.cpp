#include <iostream>

using namespace std;

int GOP(){
    int a, b;
    cin >> a >> b;
    return a * b;
}

int SUM(){
    int a, b;
    cin >> a >> b;
    return a + b;
}

int main()
{
    int g = GOP();
    int s = SUM();
    
    if (s>g){
        cout << "GOP<SUM" << endl;
    }else if(g>s){
        cout << "GOP>SUM" << endl;
    }else{
        cout << "GOP==SUM" << endl;
    }

    return 0;
}
