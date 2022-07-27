#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// 08. 문자열 교체

int main() {

    // cstring
    char a[100] = "SSAFY is BAD";
    char b[] = "GOOD";

    // strstr
    // a에서 BAD의 위치찾기
    char* p = strstr(a, "BAD");
    for (int i = 0; i < strlen(b); i++) {
        *p = b[i];
        p++;
    }
    // 마지막에 널문자 
    *p = '\0';

    cout << a << '\n';

    // string class
    // str.replace(시작 index, 교체할 문자열의 크기, 교체할 문자열)
    string st1 = "SSAFY is BAD";
    string st2 = "GOOD";
    st1.replace(st1.find("BAD", 0), 3, st2);
    cout << st1;

}