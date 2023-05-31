#include <iostream>

using namespace std;
//函数的申明
void swap(int a, int b);

int main(){
    swap(10, 20);
    return 0;
}

void swap(int a, int b) {
    int temp = a; 
    a = b;
    b = temp;
}