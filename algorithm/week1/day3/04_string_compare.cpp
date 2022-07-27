#include <iostream>
#include <cstring>
using namespace std;

// 2. 문자열 비교 (같으면 1, 아니면 0) 
int strcompare(char a[], char b[]) {
    // 1. 길이 
    if (strlen(a) != strlen(b))
        return 0;
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

int main() {

    // 1. 고문
    char a[] = "string";
    char b[] = "tsring";
    int result = strcompare(a, b);
    cout << result << '\n';

    // 2. cstring library
    // a == b -> 0
    // a > b(사전순으로 나중에 나온다면) -> 1 
    // a < b(사전순으로 먼저 나온다면) -> -1
    result = strcmp(a, b);
    cout << result << '\n';

    // strncmp -> n개의 구간을 비교
    // strncmp(a, b, 구간크기)
    result = strncmp(a + 2, b + 2, 4);
    cout << result << '\n';

    // 3. C++ string class 
    // 비교연산 때리면 됨 
    // 결과가 true = 1, false = 0
    string st1 = "string";
    string st2 = "atring";
    cout << (st1 == st2) << '\n';

    // 구간 크기 비교 
    // method : class내에서 정의된 함수
    // substr(시작 index, 구간 크기)
    // return -> string 
    string substring = st1.substr(2, 4);
    cout << substring << '\n';

    if (st1.substr(2, 4) == st2.substr(2, 4))
        cout << "와!";

    return 0;
}