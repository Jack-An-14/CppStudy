//菱形继承
#include <iostream>
using namespace std;
class Animal{
    public:
        
        int m_Age;
};
//虚继承可以解决菱形继承的问题
//继承之前 加上关键字 virtual 变为虚继承
//Animal 为 虚基类
class Sheep : virtual public Animal{};
class Tuo : virtual public Animal{};
class SheepTuo : public Sheep, public Tuo{};

void test1(){
    SheepTuo st;
    st.Sheep::m_Age = 18;
    st.Tuo::m_Age = 28;
    cout <<  st.Sheep::m_Age<< endl;
    cout << st.Tuo::m_Age << endl;
    cout << st.m_Age << endl;
    

    //这份数据，我们知道只要有一份就可以了，菱形数据导致数据有两份，导致资源浪费
}
int main(){
    test1();
    return 0;
}

//vbptr 虚基类指针 virtual base pointer
//vbptr 指向vbtable，指向虚基类表格， 记录偏移量，指向同一份数据