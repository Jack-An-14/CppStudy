//reverse反转算法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void myprint(int val){
    cout << val << " ";
}
void test1(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    //参数是迭代器区间
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), myprint);
}
int main(){
    test1();
    return 0;
}