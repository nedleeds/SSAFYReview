#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// 08. ���ڿ� ��ü

int main() {

    // cstring
    char a[100] = "SSAFY is BAD";
    char b[] = "GOOD";

    // strstr
    // a���� BAD�� ��ġã��
    char* p = strstr(a, "BAD");
    for (int i = 0; i < strlen(b); i++) {
        *p = b[i];
        p++;
    }
    // �������� �ι��� 
    *p = '\0';

    cout << a << '\n';

    // string class
    // str.replace(���� index, ��ü�� ���ڿ��� ũ��, ��ü�� ���ڿ�)
    string st1 = "SSAFY is BAD";
    string st2 = "GOOD";
    st1.replace(st1.find("BAD", 0), 3, st2);
    cout << st1;

}