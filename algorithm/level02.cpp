#include <iostream>

using namespace std;

int main()
{
    int a[5]={2,1,2,4,5};
    int b[3][3]={{2, 5, 3},
                 {4, 5, 7},
                 {8, 7, 2}};

    int num, cnt=0; 
    
    cin >> num;
    
    for (int i=0; i<5; i++){
        if (a[i] == num){
            cnt++;
        }
    }
    
    for (int j=0; j<3; j++){
        for (int k=0; k<3; k++){
            if (b[j][k] == num){
                cnt ++;
            }
        }
    }
    
    cout << cnt << endl;

    return 0;
}