//查找指定元素，二分查找
//查到，返回true。没查到,返回false
//在无序序列中不可以使用
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test1(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    //如果是无序序列，查找的结果未知
    bool ret = binary_search(v.begin(), v.end(), 9);
    if(ret){
        cout << true << endl;
    }
    else {
        cout << false << endl;
    }
}
int main(){
    test1();
    return 0;
}