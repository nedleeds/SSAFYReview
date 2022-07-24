#include <iostream>
#include <string>
using namespace std;

void swap(char *s, char *t){
    char tmp = *s;
    *s = *t;
    *t = tmp;
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
    string s1 = "DATAW";
    string s2 = "BBQK";
    int n;

    cin >> n;

    if (n%2){
        sort(&s1);
    }else{
        sort(&s2);
    }
    

    cout << s1 << endl;
    cout << s2 << endl;

    return 0;
}