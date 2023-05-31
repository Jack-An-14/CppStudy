#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MyCompare{
    public:
        //两个参数，二元。 返回bool， 谓词
        bool operator()(int v1, int v2){
            return v1 > v2;
        }
};

//二元谓词
void test1(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(0);
    v.push_back(50);
    //使用函数对象，改变算法策略，变排序为降序排列
    sort(v.begin(), v.end(), MyCompare());

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    test1();
    return 0;
}