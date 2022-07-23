#include <iostream>
using namespace std;

int arr[7][5] = {{1, 0, 0, 0, 0},
                 {1, 0, 1, 0, 0},
                 {1, 1, 0, 1, 0},
                 {1, 0, 1, 0, 0},
                 {0, 1, 0, 0, 1},
                 {0, 0, 0, 1, 0},
                 {1, 1, 0, 0, 0}};

int INPUT(){
    int a;
    cin >> a;
    return a;
}

int PROCESS(int x){
    int cnt = 0;
    for (int r=0; r<7; r++){
        if (arr[r][x] == 1){
            cnt++;
        }
    }
    return cnt;
}

void OUTPUT(int x){
    cout << x << endl;
}

int main(){
    
    OUTPUT(PROCESS(INPUT()));
    
    return 0;
}
