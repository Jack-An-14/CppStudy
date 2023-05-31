//vector构造函数
//创建vector容器
#include <iostream>
#include <vector>
using namespace std;
void test1(){
    //默认的无参构造函数
    vector<int> v1;

    //区间构造
    vector<int> v2(v1.begin(), v1.end());

    //n个elem构造
    vector<int> v3(10, 100);

    //拷贝构造
    vector<int> v4(v1);
}

int main(){

    return 0;
}