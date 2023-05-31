/*
公司今天招聘10个员工，10名员工进入公司之后，需要指派员工在哪个部门工作
员工信息有：姓名 工资组成； 部门分为策划、美术、研发
随机给10名员工分配部门和工资
通过multimap进行信息的插入 key为部门编号 value 为员工
分部门显示员工信息
*/
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
using namespace std;
class YuanGong{
    public:
        char mName;
        int pay;
        int dept;
        YuanGong(){}
        YuanGong(char name, int pay, int dep){
            this->mName = name;
            this->dept = dep;
            this->pay = pay;
        }
};
class MyCompare{
    public:
        bool operator() (int val1, int val2)const{
            return val1 < val2;
        }
};

void printYuanGong(const vector<YuanGong> & v){
    for (vector<YuanGong>::const_iterator it = v.begin(); it != v.end(); it++){
        cout << it->dept << " " << it->mName << " " << it->pay << endl;
    }
}
void test1(){
    srand((unsigned int)time(NULL));            
    vector<YuanGong> v;
    char name = 'A';
    for(int i = 0; i < 10; i++){
        int pay = rand() % 1000 + 1;
        int deps = rand() % 3 + 1;
        v.push_back(YuanGong(name++, pay,  deps));
    }

    printYuanGong(v);

    multimap<int,YuanGong, MyCompare> m;
    for(vector<YuanGong>::iterator it = v.begin(); it != v.end(); it++){
        m.insert(make_pair(it->dept, *it));
    }

    for (multimap<int,YuanGong, MyCompare>::iterator it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second.mName << " " << it->second.pay << endl;
    }
}
int main(){
    test1();
    return 0;
}