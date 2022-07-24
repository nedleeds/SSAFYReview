#include <iostream>
#include <string>
using namespace std;

struct Product{
    string name;
    int size;
    int price;
}a, b;

int main(){
    cin >> a.name;
    cin >> a.size;
    cin >> a.price;

    cin >> b.name;
    cin >> b.size;
    cin >> b.price;

    cout << a.name << "," << b.name << endl;
    cout << "AverageSize" << "=" << int((a.size+b.size)/2) << endl;
    cout << "AveragePrice" << "=" << int((a.price+b.price)/2) << endl;

    return 0;
}