#include <iostream>

using namespace std;

struct Person{
    int age;
    int height;
}a, b;

void input(){
    cin >> a.age >> a.height;
    cin >> b.age >> b.height;
}

void output(){
    int avg_age, avg_hght;
    avg_age = (a.age + b.age) / 2;
    avg_hght = (a.height + b.height) / 2;
    cout << avg_age << " " << avg_hght << endl;
}

int main()
{
    input();
    output();

    return 0;
}