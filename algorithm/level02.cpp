#include <iostream>

using namespace std;


void BBQ(int x){
    for (int j=1; j<=x; j++){
        cout << j;
    }
}

void KFC(char x){
    for (int j=0; j<7; j++){
        cout << x;
    }    
}

int main()
{
    int n, m;
    char x;
    
    cin >> n;
    
    if (n%2==1){
        cin >> m;
        BBQ(m);
    }else{
        cin >> x;
        KFC(x);
    }
    
    return 0;
}