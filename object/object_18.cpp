//友元
//1、全局函数做友元
#include <iostream>
using namespace std;

//建筑物类
class Building{
    //goodGay全局函数是Building好朋友，可以访问building的私有成员 
    friend void goodGay(Building& build);
    
    public:
        string m_SittingRoom; //客厅

        Building(){
            m_SittingRoom = "客厅";
            m_BedRoom = "卧室";
        }

    private:
        string m_BedRoom;//卧室
};

//全局函数
void goodGay(Building& build){
    cout << build.m_SittingRoom << endl;
    cout << build.m_BedRoom << endl;
}

void test1(){
    Building b;
    goodGay(b);
}
int main(){
    test1();
    return 0;
}