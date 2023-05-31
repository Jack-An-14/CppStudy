#include <iostream>
#include <vector>
#include <numeric>
//常用算数生成算法
using namespace std;

void test1(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    //起始值是起始累加的值
    int total = accumulate(v.begin(), v.end(), 1);
    cout << total << endl;
}
int main(){
    test1();
    return 0;
}