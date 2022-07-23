#include <iostream>
using namespace std;

struct Fruit{
    int size;
    int price;
}banana, apple;

int main(){
    cin >> banana.size;
    cin >> apple.size;

    banana.price = banana.size*250;
    apple.price = apple.size*500;

    cout << banana.price + apple.price << "원" << endl;
    
    return 0;
}
