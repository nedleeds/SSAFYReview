#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// 5. ���ڿ��� substring�� ��ġ 

int main() {

    // 1. ��

    // 2. cstring
    // a: ���� b : target 
    // �������� target�� ��� ��Ÿ���°�? 
    // --> cstring������ index�� ã�� ����� �����
    char a[] = "ABABC";
    char b[] = "AB";
    // strstsr(����, target)
    // return : pointer ->
    // �������� target�� ó�� ã�� ��ġ�� pointer 
    char* p = strstr(a, b);
    cout << p << "\n";

    // ��� �ִ°�? 
    char* pos = a;
    int cnt = 0;
    while (strstr(pos, b) != NULL) {
        cnt++;
        pos += strlen(b);
    }
    cout << cnt << '\n';

    // 3. string class
    string st1 = "ABABC";
    string st2 = "AB";
    // str.find(target) --> �긦 ó�� ã�� ��ġ�� index
    // ã���� : index
    // ��ã���� : string::npos / -1
    if (st1.find(st2) == -1) {
        cout << "��ã�Ҵ�" << '\n';
    }
    else
        cout << "ã�Ҵ�" << '\n';

    // ��� �ִ°�?
    // find(target, ���� index)
    int index = 0;
    cnt = 0;
    // st1���� st2(target) ��ã��������
    while (st1.find(st2, index) != -1) {
        // �ѹ� ���Դ� -> ã�ҵ� 
        cnt++;
        index = st1.find(st2, index) + st2.length();
    }
    cout << cnt;
}