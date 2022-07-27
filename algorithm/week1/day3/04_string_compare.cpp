#include <iostream>
#include <cstring>
using namespace std;

// 2. ���ڿ� �� (������ 1, �ƴϸ� 0) 
int strcompare(char a[], char b[]) {
    // 1. ���� 
    if (strlen(a) != strlen(b))
        return 0;
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

int main() {

    // 1. ��
    char a[] = "string";
    char b[] = "tsring";
    int result = strcompare(a, b);
    cout << result << '\n';

    // 2. cstring library
    // a == b -> 0
    // a > b(���������� ���߿� ���´ٸ�) -> 1 
    // a < b(���������� ���� ���´ٸ�) -> -1
    result = strcmp(a, b);
    cout << result << '\n';

    // strncmp -> n���� ������ ��
    // strncmp(a, b, ����ũ��)
    result = strncmp(a + 2, b + 2, 4);
    cout << result << '\n';

    // 3. C++ string class 
    // �񱳿��� ������ �� 
    // ����� true = 1, false = 0
    string st1 = "string";
    string st2 = "atring";
    cout << (st1 == st2) << '\n';

    // ���� ũ�� �� 
    // method : class������ ���ǵ� �Լ�
    // substr(���� index, ���� ũ��)
    // return -> string 
    string substring = st1.substr(2, 4);
    cout << substring << '\n';

    if (st1.substr(2, 4) == st2.substr(2, 4))
        cout << "��!";

    return 0;
}