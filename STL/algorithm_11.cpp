//merge算法
//两个容器元素合并，并存储到另一容器中。两个容器必须有序
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void myprint(int val){
    cout << val << " ";
}
void test1(){
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 10; i++){
        v1.push_back(i);
        v2.push_back(i+1);
    }


    //目标容器
    vector<int> vTarget;
    //提前给目标容器分配内存
    vTarget.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), myprint);

}
int main(){
    test1();
    return 0;
}