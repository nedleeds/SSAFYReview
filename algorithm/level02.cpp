#include <iostream>
#include <string>
using namespace std;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int l[4]){
    for (int i=0; i<3; i++){
        for (int j=i+1; j<4; j++){
            if (l[i] > l[j]){
                swap(&l[i], &l[j]);
            }
        }
    }
}

int main(){
    string s[4];
    int l[4];

    for (int i=0; i<4; i++){
        cin >> s[i];
        l[i] = s[i].length();
    }

    sort(l);

    for (int j=0; j<4; j++){
        cout << l[j] << " ";
    }
    cout << endl;

    return 0;
}