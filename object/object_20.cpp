//成员函数做友元
#include <iostream>
#include <string>
using namespace std;
class Building;
class Goodgay{
    public:
        Goodgay();
        Building * build;
        void visit();//让visit函数可以访问Building中私有成员函数
        void visit2();//让visit2函数不可以访问Building中私有成员
};
class Building{
    //告诉编译器 goodgay类下的visit成员函数作为本类的好朋友 ，可以访问私有成员
    friend void Goodgay::visit();   //=======================
    public:
        string m_Sittingroom;
        Building();
    private:
        string m_Bedroom;
};

Goodgay::Goodgay(){
    build = new Building;
}
void Goodgay::visit(){
    cout << "visit访问:" << build->m_Sittingroom <<endl;
    cout << "visit访问:" << build->m_Bedroom <<endl;
}

void Goodgay::visit2(){
    cout << "visit2访问:" << build->m_Sittingroom <<endl;
    // cout << "visit访问:" << build->m_Bedroom <<endl;
}
Building::Building(){
    m_Bedroom = "卧室";
    m_Sittingroom = "客厅";
}

void test1() {
    Goodgay gy;
    gy.visit();
    gy.visit2();
}
int main(){
    test1();
    return 0;
}