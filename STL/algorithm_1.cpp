//常用遍历算法for_each
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print01(int val){
    cout << val << " ";
}

class MyFunc{
    public:
        void operator()(int val){
            cout << val << " ";
        }
};
void test1(){
    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }

    //普通函数版本
    for_each(v.begin(), v.end(), print01);
    cout << endl;

    //仿函数版本
    for_each(v.begin(), v.end(), MyFunc());
    cout << endl;

}

int main(){
    test1();
    return 0;
}