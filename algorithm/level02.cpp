#include <iostream>

using namespace std;


int findUpper(char arr[2][3]){
    int cnt_up = 0;
    
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            if ('A' <= arr[i][j] && arr[i][j] <= 'Z'){
                cnt_up++;    
            }
        }
    }
    
    return cnt_up;
}

int findLower(char arr[2][3]){
    int cnt_lw = 0;
    
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            if ('a' <= arr[i][j] && arr[i][j] <= 'z'){
                cnt_lw++;    
            }
        }
    }
    
    return cnt_lw;
}

int main()
{
    char arr[2][3];
    int n1 = 0, n2 = 0;
    
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }

    n1 = findUpper(arr);
    n2 = findLower(arr);

    cout << "대문자" << n1 << "개" << endl;
    cout << "소문자" << n2 << "개" << endl;

    return 0;
}