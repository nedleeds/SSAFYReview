#include <iostream>
using namespace std;

int main(){
    char arr[6] = {'A', 'F', 'G', 'A', 'B', 'C'};
    char a, b;
    int cnt_a = 0, cnt_b = 0;

    cin >> a >> b;
    
    for (int i=0; i<6; i++){
        if (arr[i] == a){
            cnt_a++;
        }
        if(arr[i]==b){
            cnt_b++;
        }
    }

    if (cnt_a>=1 && cnt_b>=1){
        cout << "와2개\n";
    } else if(cnt_a*cnt_b == 0 && cnt_a+cnt_b >= 1){
        cout << "오1개\n";
    } else if (cnt_a+cnt_b == 0){
        cout << "우0개\n";
    }

    return 0;
}