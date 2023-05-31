#include <iostream>
using namespace std;

int main(){
    int a = 10;
    //int &b;  这里报错是因为，创建引用的时候必须初始化
    int &b = a;

    int c = 20;
    //引用一旦初始化之后，不可以改变
    b = c;//这里是赋值操作

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}