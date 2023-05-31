//new的基本语法和实例
#include <iostream>
using namespace std;

int* func(){
    //在堆区创建整型数据
    int* p = new int(10);
    return p;
};

void test01(){
    int* p = func();
    cout << *p << endl;
    delete p;
    cout << *p << endl;
    cout << *p << endl;
};
int main(){

    test01();
    int* arr = new int[10];
    delete[] arr;
    return 0;
}