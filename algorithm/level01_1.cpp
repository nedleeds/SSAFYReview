#include <iostream>
using namespace std;

int main(){
    char arr[3];
    int cnt=0;

    for (int i=0; i<3; i++){
        cin >> arr[i];
    }

    for (int i=0; i<3; i++){
        if ('A' <= arr[i] && arr[i]<= 'Z'){
            cnt++;
        }
    }

    if (cnt == 3){
        cout << "풍족하다" << endl;
    }else if(1<= cnt && cnt<3){
        cout << "적절하다" << endl;
    }else if(cnt == 0){
        cout << "부족하다" << endl;
    }

    return 0;
}
