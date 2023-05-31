//replace_if将区间内的元素按条件替换成指定的元素
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Compare{
    public:
        bool operator()(int val){
            return val == 10;
        }
};

void test1(){
    vector<int> v;
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(50);

    replace_if(v.begin(), v.end(), Compare(), 30);

    for (int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}

int main(){
    test1();
    return 0;
}