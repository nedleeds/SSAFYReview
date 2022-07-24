#include <iostream>
#include <string>
using namespace std;

int count(string *s, char x){
    int cnt = 0;
    for (int i=0; i<(*s).length(); i++){
        if ((*s)[i]==x){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    string s1 = "BBQWORLD";
    string s2 = "KFCAPPLE";
    string s3 = "LOT";
    char c;

    cin >> c;

    cout << count(&s1, c) + count(&s2, c) + count(&s3, c) << endl;

    return 0;
}