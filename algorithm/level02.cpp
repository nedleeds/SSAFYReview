#include <iostream>
#include <string>
using namespace std;

void swap(char *a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(string *s){
    int l = (*s).length();

    for (int i=0; i<l-1; i++){
        for (int j=i+1; j<l; j++){
            if ((*s)[i] > (*s)[j]){
                swap(&(*s)[i], &(*s)[j]);
            }
        }
    }
}

int main(){
    string s1, s2;

    cin >> s1 >> s2;

    sort(&s1);
    sort(&s2);
    
    cout << s1 << s2 << endl;

    return 0;
}