//容器vector
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void myprint(int val){
    cout << val << endl;
}

void test1(){
    //创建vector容器
    vector<int> v;

    //向容器中插入数据,尾插
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    //通过迭代器访问容器中的数据
    vector<int>::iterator itBegin = v.begin();  //起始迭代器    指向容器中的第一个元素
    vector<int>::iterator itEnd = v.end();  //结束迭代器    指向容器中的最后一个元素的下一个位置

    //第一种遍历方式
    while(itBegin != itEnd){
        cout << *itBegin << endl;
        itBegin++;
    }

    //第二种遍历方式
    for(vector<int>::iterator itB = v.begin(); itB != v.end(); itB++){
        cout << *itB << endl;
    }

    //第三种遍历方式，利用STL的遍历算法
    for_each(v.begin(), v.end(), myprint);

}
int main(){
    test1();

    return 0;

}