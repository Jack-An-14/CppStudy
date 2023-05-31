//struct 和 class区别
#include <iostream>
using namespace std;
class C1{
    int m_a;//默认权限 为私有权限
};
struct C2{
    int m_b;
};

int main(){
    C1 c1;
    // c1.m_a (Inaccessible);
    C2 c2;
    c2.m_b = 10;
    return 0;
}