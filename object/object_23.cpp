//递增运算符重载
//作用:通过重载递增运算符，实现整形
#include <iostream>
using namespace std;
class MyInteger{
    friend ostream & operator<<(ostream & out, MyInteger t);
    public:
        MyInteger(){
            m_num = 0;
        }
    //重载前置++运算符
    //为什么返回引用？返回引用是为了一直对一个数据进行操作
        MyInteger & operator++(){
            this->m_num ++;
            return *this;
        }
    //重载后置++运算符
    // void operator++(int) int代表占位参数，可以用于区分前置和后置递增
    // 后置递增一定要返回值，因为临时变量在函数结束后，被释放，返回引用会导致错误的内存指向
        MyInteger operator++(int){ 
            //先返回结果 记录当时结果
            MyInteger temp = *this;
            //后递增
            m_num++;
        
            //最后将记录结果做返回
            return temp;
        }
    private:
        int m_num;
};
ostream & operator<<(ostream & out, MyInteger t){
    out << t.m_num;
    return out;
}
void test1(){
    MyInteger myint;
    cout << ++(++myint) << endl;
    cout << myint << endl;
}

void test2(){
    MyInteger m;
    cout << m++ << endl;
    cout << m << endl;
}

int main(){
    // test1();
    test2();
    return 0;
}
//前置递增和后置递增
