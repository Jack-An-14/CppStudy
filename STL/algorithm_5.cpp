//常用查找算法adjacent_find
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test1(){
    vector<int> v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);

    vector<int>::iterator it = adjacent_find(v.begin(), v.end());

    if(v.end() == it){
        cout << "未找到" << endl;
    }
    else {
        cout << *it << endl;
    }

}
int main(){
    test1();
    return 0;
}