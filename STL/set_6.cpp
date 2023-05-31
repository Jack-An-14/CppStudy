//set容器排序
#include <iostream>
#include <set>
using namespace std;

class MyCompare{
    public:
    //仿函数。重载运算符()。第一个是运算符，第二个是函数的参数列表
        bool operator() (int v1, int v2){
            return v1 > v2;
        }
};

void printset(const set<int> & s){
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

bool comp(int v1, int v2){
    return v1>v2;
}

void test1(){
    //在构造容器之前，就应该设置比较的仿函数
    set<int, MyCompare> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    
    for (set<int, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
int main(){
    test1();
    return 0;
}