#include <iostream>
#include <string>
using namespace std;

class MyAdd{
    public:
        int operator()(int v1, int v2){
            return v1 + v2;
        }
};
class MyPrint{
    public:
        MyPrint(){
            this->count = 0;
        }
        void operator()(string test){
            cout << test << endl;
            count++;
        }
        int count;//内部自己状态
};

void test1(){
    //函数对象在使用时，可以想普通函数那样调用，可以有参数，可以有返回值
    MyAdd myAdd;
    int res = myAdd(10, 10);
    cout << res << endl;
}

void test2(){
    //函数对象超出普通函数的概念，函数对象可以有自己的状态
    MyPrint myPrint;
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    cout << myPrint.count << endl;
}

void doPrint(MyPrint & mp, string test){
    mp(test);
}

void test3(){
    MyPrint myPrint;
    // ​	函数对象可以作为参数传递
    doPrint(myPrint, "hello c++");
}
int main(){
    // test1();
    // test2();
    test3();
    return 0;
}