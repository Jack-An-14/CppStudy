#include <iostream>
#include <map>
#include <string>

using namespace std;
void test1(){
    map<int, string> m1;

    m1.insert(pair<int, string>(1, "jack"));
    m1.insert(pair<int, string>(2, "dack"));
    m1.insert(pair<int, string>(3, "cack"));

    //查找函数find
    
    map<int, string>::iterator it = m1.find(1);
    cout << it->first << " " << it->second << endl;
    it = m1.find(100);
    if(it == m1.end()){
        cout << "没找到" << endl;
    }
    else {
        cout << "找到了" << endl;
    }
    
    //统计key的个数
    cout << m1.count(1) << endl;
    
}
int main(){
    test1();
    return 0;
}