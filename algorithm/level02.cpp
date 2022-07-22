#include <iostream>

using namespace std;

int main()
{
    char arr[5];
    int indices[5] = {0,};
    int cnt = 0;
    
    
    for (int i=0; i<5; i++){
        cin >> arr[i];
        if (arr[i] == 'A'){
            cnt++;
            indices[i] = 1;
        }
    }
    
    cout << "문자A는 " << cnt << "개발견" <<endl;
    
    for (int i=0; i<5; i++){
        if (indices[i]==1){
            cout << i << "번" << endl;
        }
    }

    return 0;
}