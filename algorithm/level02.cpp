#include <iostream>

using namespace std;

int main()
{
    int arr[3][3] = {{10, 3, 20},
                     {60, 30, 40},
                     {20, 30, 40}};
    
    int a, b, count=0;
    
    cin >> a >> b;
    
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (a <= arr[i][j] && arr[i][j] <= b){
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}