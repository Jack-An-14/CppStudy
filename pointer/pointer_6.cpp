//指针和数组,利用指针来访问数组，数组名就是首地址
#include <iostream>

using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* p = arr;

    for (int i = 0; i < 10; i++) {
        cout << *p << endl;
        p++;
    }
    return 0;
}