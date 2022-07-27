#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// 5. 문자열의 substring의 위치 

int main() {

    // 1. 고문

    // 2. cstring
    // a: 원본 b : target 
    // 원본에서 target이 어디서 나타나는가? 
    // --> cstring에서는 index를 찾을 방법이 어려움
    char a[] = "ABABC";
    char b[] = "AB";
    // strstsr(원본, target)
    // return : pointer ->
    // 원본에서 target을 처음 찾은 위치의 pointer 
    char* p = strstr(a, b);
    cout << p << "\n";

    // 몇개가 있는가? 
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
    // str.find(target) --> 얘를 처음 찾는 위치의 index
    // 찾으면 : index
    // 못찾으면 : string::npos / -1
    if (st1.find(st2) == -1) {
        cout << "못찾았다" << '\n';
    }
    else
        cout << "찾았다" << '\n';

    // 몇개가 있는가?
    // find(target, 시작 index)
    int index = 0;
    cnt = 0;
    // st1에서 st2(target) 못찾을때까지
    while (st1.find(st2, index) != -1) {
        // 한번 들어왔다 -> 찾았따 
        cnt++;
        index = st1.find(st2, index) + st2.length();
    }
    cout << cnt;
}