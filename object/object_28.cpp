//继承
#include <iostream>
using namespace std;
//继承实现页面
//公共页面
class BasePage{
    public:
        void header(){
            cout << "首页、公开课、登陆、注册" << endl;
        }

        void footer(){
            cout << "帮助中心、交流合作、站内地图" << endl;
        }
        void left(){
            cout << "Java、Python、C++" << endl;
        }
};

//Java页面
class Java : public BasePage{
    public:
        void content(){
            cout << "java视频" << endl;
        }
};

//python
class python : public BasePage{
    void content(){
        cout << "python视频" << endl;
    }
};
void test1(){
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
}
int main(){
    test1();
    return 0;
}