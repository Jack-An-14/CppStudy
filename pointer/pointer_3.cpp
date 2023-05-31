//空指针和野指针
//空指针：指针变量指向内存中编号为0的空间
//用途：初始化指针变量
//注意：空指针不可以访问
#include <iostream>

using namespace std;

int main() {
    //空指针进行初始化
    int* a = NULL;

    //指针不可访问
    //0～255之间的内存编号是系统占用，不可以访问
    cout << a << endl;

    return 0;
}