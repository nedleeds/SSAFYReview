#include <iostream>
#include <string>
using namespace std;

void swap(char *a, char *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int arr[6] = {10, 50, 40, 20, 30, 40};
    int arr2[6] = {0}, cnt[6] = {0};
    
    for (int i=0; i<6; i++){
        cin >> arr2[i];
    }

    for (int j=0; j<6; j++){
        for (int i=0; i<6; i++){
            if (arr2[j] < arr[i]){
                cnt[j]++;
            }
        }
    }

    for (int i=0; i<6; i++){
        cout << arr2[i] << "=" << cnt[i] << "개" << endl;
    }

    return 0;
}