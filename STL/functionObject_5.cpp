//关系仿函数
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class MyCompare{
    public:
        bool operator()(int v1, int v2){
            return v1 > v2;
        }
};

//大于
void test1(){
    vector<int> v;
    v.push_back(10);
    v.push_back(-10);
    v.push_back(10);
    v.push_back(0);
    v.push_back(50);
    //自己写的仿函数对象
    // sort(v.begin(), v.end(), MyCompare());
    sort(v.begin(), v.end(), greater<int>());
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    
}
int main(){
    test1();
    return 0;
}