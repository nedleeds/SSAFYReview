#include <iostream>
#include <string>
using namespace std;

// 1. insert 
// 2. erase 
// 3. stoi // string to integer

int main() {
    // 1. insert 
    string str = "string";
    // insert(index, 넣고싶은 문자열)
    str.insert(2, "##");
    cout << str << '\n';

    // 2. erase
    // erase(어디서부터?, 어디까지? - 구간의 크기)
    str.erase(2, 2);
    cout << str << '\n';

    // 3. stoi -> python int() -> 문자열을 정수
    cout << stoi("123") + 1;
    // 123 -> 1. 길이 
    // 2. 하나씩 빼와서 ('1'-'0') * (길이-1) * 10
    /// 100+ 20 +3 = 123
}