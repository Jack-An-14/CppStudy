//类做友元
#include <iostream>
using namespace std;
class Building{
    //GoodGay是本类的好朋友，可以访问Building的私有成员
    friend class GoodGay;   //=======================
    public:
        Building();
        string m_SittingRoom;
    private:
        string m_BedRoom;
};
class GoodGay{
    

    public:
        Building * build;
        GoodGay();
        void visit();//参观函数 访问Building中的属性
};

//类外写成员函数
Building::Building(){
    m_BedRoom = "卧室";
    m_SittingRoom = "客厅";
}

GoodGay::GoodGay(){
    //创建一个建筑物对象
    build = new Building;
}

void GoodGay::visit(){
    cout << "好基友类正在访问:" << build->m_SittingRoom << endl;
    cout << "好基友类正在访问:" << build->m_BedRoom << endl;
}

void test1(){
    GoodGay gy;
    gy.visit();
}

int main(){
    
    test1();
    return 0;
}