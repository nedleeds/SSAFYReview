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
    string s1 = "POTIO";
    string s2 = "ABCDE";
    string s3 = "YOURE";
    char ans[15];

    int a, b;
    cin >> a >> b;

    int k = 0;
    for (int i=a; i<=b; i++){
        ans[k++] = s1[i];
    }
    for (int i=a; i<=b; i++){
        ans[k++] = s2[i];
    }
    for (int i=a; i<=b; i++){
        ans[k++] = s3[i];
    }

    for (int x=0; x<k; x++){
        cout << ans[x];
    }
    cout << endl;

    return 0;
}