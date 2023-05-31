#include <iostream>
using namespace std;
//常量引用
//使用场景：用来修饰形参，防止误操作

void showValue(const int& a){
    //a = 100; 添加const，可以防止误操作
    cout << "val = " << a << endl;
}
int main(){
    const int& ref = 10;
    //ref = 20; 此处报错是因为ref不是一个可以修改的左值，加入const之后变为只读，不可以修改

    int a = 10;
    cout << a << endl;
    showValue(a);
    return 0;
}