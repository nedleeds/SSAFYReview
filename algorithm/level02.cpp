#include <iostream>

using namespace std;

void checkChar(char c){
    if ('a' <= c && c <= 'z'){
        cout << "소";
    }else if('A' <= c && c <= 'Z'){
        cout << "대";
    }
}

int main()
{
    char arr[5];
    int i;
    
    for (int i=0; i<5; i++){
        cin >> arr[i];
    }
    
    for (int j=0; j<5; j++){
        checkChar(arr[j]);
    }

    return 0;
}