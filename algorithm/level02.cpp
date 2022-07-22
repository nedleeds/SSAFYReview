#include <iostream>

using namespace std;

int main()
{
    int a;
    int arr[4][4]={0,};
    
    cin >> a;
    
    if (a%2){
        for (int i=0, j=3; i<4, j>=0; i++, j--){
            arr[i][j] = i+1;
        }
    }else{
        for (int i=0, j=0; i < 4; i++,j++){
            arr[i][j] = i+1;
        }
    }
    
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}