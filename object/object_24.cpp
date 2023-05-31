#include <iostream>
using namespace std;
//前置递减和后置递减
class MyInteger{
    friend ostream & operator<<(ostream & out, MyInteger mint);
    public:
        MyInteger(){
            mnum = 0;
        }
        //前置递减
        MyInteger & operator--(){
            this->mnum --;
            return * this;
        }
        //后置递减
        MyInteger operator--(int){
            //先记录
            MyInteger temp = *this;
            //再减
            this->mnum--;
            //返回记录值
            return temp;
        }

    private:
        int mnum;
};
ostream & operator<<(ostream & out, MyInteger mint){
    out << mint.mnum;
    return out;
}
void test1() {
    MyInteger a;
    cout << --a << endl;
    cout << a << endl;

    MyInteger b;
    cout << b-- << endl;
    cout << b << endl;
}

int main(){
    test1();
    return 0;
}