//map容器排序
#include <iostream>
#include <map>
#include <string>
using namespace std;

class MyCompare{
    public:
        bool operator()(const int & v1, const int & v2 ) const{
            return v1 > v2;
        }
};

void test1(){
    map<int, string, MyCompare> m1;
    m1.insert(pair<int, string>(1, "jack"));
    m1.insert(pair<int, string>(2, "dack"));
    m1.insert(pair<int, string>(3, "cack"));
    
    for( map<int, string, MyCompare>::iterator it = m1.begin(); it != m1.end(); it++){
        cout << it->first << " " << it->second << " ";
    }
    cout << endl;
    
}

int main(){
    test1();
    return 0;
}