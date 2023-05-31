//多态案例2-制作饮品
#include <iostream>
using namespace std;

class AbstractDrinking{
    public:
        //煮水
        virtual void boil() = 0;
        //冲泡
        virtual void brew() = 0;
        //倒杯子
        virtual void pour() = 0;
        //加入佐料
        virtual void addSomething() = 0;

        void makeDrink(){
            boil();
            brew();
            pour();
            addSomething();
        }
};

class Coffee : public AbstractDrinking{
    public:
        void boil(){
            cout << "煮水" << endl;
        }

        void brew(){
            cout << "泡咖啡" << endl;
        }

        void pour(){
            cout << "倒杯子里" << endl;
        }

        void addSomething(){
            cout << "加入牛奶" << endl;
        }
};

class Tea : public AbstractDrinking{
    public:
        void boil(){
            cout << "煮水" << endl;
        }

        void brew(){
            cout << "泡茶" << endl;
        }

        void pour(){
            cout << "倒杯子里" << endl;
        }

        void addSomething(){
            cout << "加入柠檬" << endl;
        }
};

void test(){
    AbstractDrinking * abs = new Coffee;
    abs->makeDrink();
    delete abs;

    abs = new Tea();
    abs->makeDrink();

    delete abs;
}
int main(){
    test();
    return 0;
}