//pair对组创建
#include <iostream>
#include <string>
using namespace std;

void test1(){
    //创建方式一
    pair<string, int> p1 ("毛捷", 10);
    cout << p1.first << " " << p1.second << endl;

    //创建方式二
    pair<string, int> p2 = make_pair("niko", 20);
    cout << p2.first << " " << p2.second << endl;
}
int main(){
    test1();
    return 0;
}