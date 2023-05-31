//指针所占的内存空间
#include <iostream>

using namespace std;

int main() {
    int a = 10;
    int* p = &a;

    cout << sizeof(int*) << endl;
    cout << sizeof(char*) << endl;

    return 0;
}