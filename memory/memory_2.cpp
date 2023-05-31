#include <iostream>
using namespace std;

//栈区数据注意事项   --不要返回局部变量的地址
//栈区的数据由编译器管理开辟和释放
int* func(){
    int a = 10; //局部变量 存放在栈区 栈区的数据在函数执行后自动释放
    return &a; //返回局部变量的地址
};
int main() {
    //接收func函数的返回值
    int* p = func();
    //函数的形式参数也会存放在栈区，两次地址是一样的，但是数据不一样。说明保留了原来的数据，第二次调用的时候就会产生随机数字
    cout << *p << endl;//第一次可以答应正确的数字，是因为编译器做了保留
    cout << *p << endl;//第二次这个数据就不保留

    cout << p << endl;
    cout << p << endl;
    return 0;
}