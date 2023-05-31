//逻辑仿函数
//实现逻辑运算, 与、或、非
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
//逻辑非
void test1(){
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(false);
    v.push_back(true);

    for(vector<bool>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    //利用逻辑非， 将容器v搬运到 容器v2中，并执行取反操作
    vector<bool> v2;
    v2.resize(v.size());

    //transform 函数。使用的时候，需要提前开辟空间
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    for(vector<bool>::iterator it = v2.begin(); it != v2.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    test1();
    return 0;
}