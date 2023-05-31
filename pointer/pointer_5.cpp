//const修饰指针
//1、const修饰指针 --常量指针
//2、const修饰常量 --指针常量
//3、const既修饰指针，又修饰常量
#include <iostream>

using namespace std;

int main() {

    int a = 10;
    int b = 20;
    //常量指针。指针的指向可以修改，但是指针指向的值不可以改。
    const int* p = &a;
    p = &b;
    // *p = b;
    //指针常量。指针的指向不可改，但是指向的内容可以改。
    int* const q = &a;
    // q = &b;
    *q = a;
    //既修饰指针又修饰常量。指针指向的地址不可改，指向的内容不可以改。
    const int* const pq = &a;
    // pq = &b;
    // *pq = b;

    return 0;
}