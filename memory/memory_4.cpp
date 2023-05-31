//引用的基础语法
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int &b = a;
    cout << a << endl;
    cout << b << endl;

    b = 20;
    cout << a << b << endl;

    return 0;
}