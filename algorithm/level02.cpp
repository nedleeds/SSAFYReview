#include <iostream>
#include <string>
using namespace std;

void swap(char *a, char *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    string s;
    int curr, check;

    cin >> s;

    int l = s.length();
    for (int i=0; i<l+1; i++){
        for (int j=i; j<l; j++){
            if (s[i]>s[j]){
                swap(&s[i], &s[j]);
            }
        }
    }

    cout << s << endl;

    return 0;
}