#include <iostream>
#include <string>
using namespace std;

struct PROFILE{
    string name;
    int age;
    int weight;
}pr1, pr2;

int main(){
    cin >> pr1.name >> pr1.age >> pr1.weight;
    cin >> pr2.name >> pr2.age >> pr2.weight;

    cout << pr1.name << " & " << pr2.name << endl;
    cout << "평균" << int((pr1.age + pr2.age) / 2) << "세" << endl;
    cout << "평균" << int((pr1.weight + pr2.weight) / 2) << "KG" << endl;

    return 0;
}