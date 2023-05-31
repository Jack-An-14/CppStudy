//vector数据存取
//at()
//operator[]
//front()
//back()
#include <iostream>
#include <vector>
using namespace std;
void test1(){
    vector<int> v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }

    for (int i = 0; i < v1.size(); i++){
        //operator[]形式
        cout << v1[i] << " ";
        //at函数形式
        cout << v1.at(i) << " ";
    }
    cout << endl;

    cout << "第一个元素为：" << v1.front() << endl;
    cout << "最后一个元素为：" << v1.back() << endl;
}

int main(){
    test1();
    return 0;
}