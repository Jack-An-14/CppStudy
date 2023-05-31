//map插入和删除
#include <iostream>
#include <map>
#include <string>
using namespace std;

void test1(){
    map<int, string> m1;
    //插入函数,返回pair<iterator, bool>数据
    m1.insert(pair<int, string>(1, "jack"));
    m1.insert(pair<int, string>(2, "dack"));
    //清空函数
    // m1.clear();

    //erase删除指定迭代器的元素，并返回下一个元素的迭代器
    m1.erase(m1.begin());

    //erase删除区间[begin, end)的所有元素，返回下一个元素的迭代器
    m1.erase(m1.begin(), m1.end());

    m1.insert(pair<int, string>(1, "jack"));
    m1.insert(pair<int, string>(2, "dack"));
    //删除容器中键值为key的元素
    m1.erase(1);

    for (map<int, string>::iterator it = m1.begin(); it != m1.end(); it++){
        cout << it->first << " " << it->second << " ";
    }
    

}
int main(){

    test1();
    return 0;
}