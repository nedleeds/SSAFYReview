#include <iostream>
#include <string>
using namespace std;

void FindABC(string s1, string s2, int *cnt_a, int *cnt_b, int *cnt_c){

    for (int i=0; i<s1.length()+1; i++){
        if(s1[i] == 'A'){
            *cnt_a += 1;
        }else if(s1[i]=='B'){
            *cnt_b += 1;
        }else if(s1[i]=='C'){
            *cnt_c += 1;
        }
    }
    for (int i=0; i<s2.length()+1; i++){
        if(s2[i] == 'A'){
            *cnt_a += 1;
        }else if(s2[i]=='B'){
            *cnt_b += 1;
        }else if(s2[i]=='C'){
            *cnt_c += 1;
        }
    }
}

int main(){
    string s1, s2;
    int cnt_a=0, cnt_b=0, cnt_c=0;

    cin >> s1 >> s2;

    FindABC(s1, s2, &cnt_a, &cnt_b, &cnt_c);
    
    cout << "A:" << cnt_a << endl;
    cout << "B:" << cnt_b << endl;
    cout << "C:" << cnt_c << endl;

    return 0;
}