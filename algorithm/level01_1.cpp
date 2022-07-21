#include <iostream>
using namespace std;

void input(char* a, char *b){
    cin >> *a >> *b;
}

void output(char* a, char *b){
    int large=0; 
    int small=0; 

    if ('a' <= *a && *a <='z'){
        small += 1;
    }else if('A' <= *a && *a <= 'Z'){
        large += 1;
    }
    if ('a' <= *b && *b <='z'){
        small += 1;
    }else if('A' <= *b && *b <= 'Z'){
        large += 1;
    }

    if (large==2){
        cout << "대문자들" << endl;
    }else if(large==1 && small==1){
        cout << "대소문자" << endl;
    }else{
        for (char c='a'; c<='z'; c++){
            cout << c;
        }
        cout << endl;
    }

}

int main(){
    char a, b;
    
    input(&a, &b);
    output(&a, &b);

    return 0;
}
