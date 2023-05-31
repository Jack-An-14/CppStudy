//常用拷贝和替换算法
//copy,容器内指定范围的元素拷贝到另一容器中
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void myprint(int val){
    cout << val << " ";
}
void test1(){
    vector<int> v1;
    for (int i = 0; i < 10; i++){
        v1.push_back(i);
    }

    vector<int> v2;
    //需要提前开辟空间
    v2.resize(v1.size());
    copy(v1.begin(), v1.end(), v2.begin());

    for_each(v2.begin(), v2.end(), myprint);
}
int main(){
    test1();
    return 0;
}