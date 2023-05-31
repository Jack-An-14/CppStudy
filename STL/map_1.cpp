//map构造和赋值
#include <iostream>
#include <map>
using namespace std;

void printMap(const map<int, string> & m){
    for (map<int, string>::const_iterator it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}

void test1(){
    //默认构造
    map<int, string> m1;
    m1.insert(make_pair(1, "毛捷"));
    m1.insert(make_pair(2, "毛mm捷"));
    m1.insert(make_pair(3, "毛mmmmm捷"));
    
    printMap(m1);

    //拷贝构造
    map<int, string> m2(m1);
    printMap(m2);

    //赋值 operator=
    map<int, string> m3 = m1;
    printMap(m3);

}
int main(){
    test1();
    return 0;
}