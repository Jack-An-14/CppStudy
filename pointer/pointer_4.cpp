//野指针：指针变量指向非法的内存空间
#include <iostream>

using namespace std;

int main() {
    //在程序中，避免出现野指针
    int* p = (int*)0x1100;
    
    cout << *p << endl;
    return 0;
}