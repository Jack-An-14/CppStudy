//函数调用运算符的重载
#include <iostream>
#include <string>
using namespace std;
class MyPrint{
    public:
        //重载函数调用运算符
        void operator()(string test){
            cout << test << endl;
        }
};

void test1(){
    MyPrint p;
    p("hello world");//非常类似函数调用，别名仿函数
}

//仿函数非常灵活，没有固定的写法
class MyAdd{
    public:
        int operator()(int a, int b){
            return a+b;
        }
};

void test2(){
    MyAdd add;
    cout << add(10, 20) << endl;

    //匿名函数对象
    cout << MyAdd()(10, 10) << endl;
}
int main() {

    // test1();
    test2();
    return 0;
}