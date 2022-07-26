#include <iostream>
#include <cstring> // 문자 배열 
// 나중에 주의
using namespace std;

// 문자 배열 vs 문자열
// {A B C D E}
// ABCDE\0
 // 끝에 NULL문자가 들어갈 자리를 보장; 

int main() {
    // strlen --> 문자열의 길이 return
    char str[] =  "ABCDE" ; // 입력받아야하면 NULL문자가 들어갈 자리를 보장해줘야 한다.

    //int len = strlen(str); 
    //cout << len;
    //
    //// 라이브러리 없이도 구현 -> 문자열의 끝에는 항상 NULL
    //len = 0;
    //for (int i = 0; str[i] != '\0'; i++)
    //    len++;
    //cout << len;
    
    // strcmp --> 두 문자열이 같은가? 
    int result = strcmp(str, "ABCDE"); // strcmp(A, B) == 0
    int result2 = strcmp(str, "AAAAA"); // strcmp(A, B) == 1
    // B가 A보다 사전순으로 먼저 올때
    int result3 = strcmp(str, "BBBBB"); // strcmp(A, B) == -1
    // A가 B보다 사전순으로 먼저 올때
    cout << result << '\n';
    cout << result2 << '\n';
    cout << result3 << '\n';

    // 라이브러리 없이 두개의 문자열이 동일한가? 
    char str1[] = "AAB";
    char str2[] = "AAB";

    // 1. 길이 체크
    int flag = 0; 
    if (strlen(str1) != strlen(str2)) {
        cout << "다르다"; 
    }
    else {
        for (int i = 0; i < strlen(str1); i++) {
            if (str1[i] != str2[i]) {
                // 다르다는것을 기록
                flag = 1; 
            }
        }
        if (flag == 0)
            cout << "같다";
        else
            cout << "다르다";
    }
}