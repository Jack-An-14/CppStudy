#include <iostream>
using namespace std;

class Calculator{
    public:
        int getResult(string oper){
            if(oper == "+"){
                return m_Num1 + m_Num2;
            }
            else if (oper == "-"){
                return m_Num1 - m_Num2;
            }
            else if(oper == "*"){
                return m_Num1 * m_Num2;
            }

            return 0;
        }

        int m_Num1;
        int m_Num2;
};
//如果想扩展新的功能，需要修改源码
//在真实开发中，提倡开闭原则
//开闭原则：对扩展进行开放，对修改进行关闭
//多态的好处
//1、组织结构清晰
//2、可读性强 
//3、对于前期和后期的维护性高

class AbstractCalculator{
    public:
        virtual int getResult(){
            return 0;
        }

        int m_Num1;
        int m_Num2;
};

//加法计算器的类
class AddCalculator : public AbstractCalculator{
    public:
        int getResult(){
            return m_Num1 + m_Num2;
        }
};

class SubCalculator : public AbstractCalculator{
    public:
        int getResult(){
            return m_Num1 - m_Num2;
        }
};

class MulCalculator : public AbstractCalculator{
    public:
        int getResult(){
            return m_Num1 * m_Num2;
        }
};

void test1(){
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;

    cout << c.getResult("+") << endl;
}

void test2(){
    //多态使用条件
    //父类指针或者引用指向子类对象
    AbstractCalculator * abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << abc->getResult() <<endl;

    //用完之后，需要销毁
    delete abc;

    abc = new SubCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << abc->getResult() <<endl;

    delete abc;
}
int main(){

    // test1();

    test2();
    return 0;
}