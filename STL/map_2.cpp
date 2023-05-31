//map大小和交换
#include <iostream>
#include <map>
using namespace std;

void printMap(const map<int, int> & m){
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}

void test1(){
    map<int, int> m1;
    m1.insert(pair<int, int> (1, 2));
    m1.insert(pair<int, int> (2, 4));
    m1.insert(pair<int, int> (3, 8));
    m1.insert(pair<int, int> (0, 1));

    if(m1.empty()){
        cout << "为空" << endl;
    }
    else {
        cout << "不为空" << endl;
        cout << m1.size() << endl;
    }

    map<int, int> m2;
    m2.insert(pair<int, int> (4, 16));
    m2.insert(pair<int, int> (5, 32));
    m2.insert(pair<int, int> (6, 64));
    m2.insert(pair<int, int> (7, 128));
    printMap(m1);
    printMap(m2);
    cout << endl;
    m1.swap(m2);

    printMap(m1);
    printMap(m2);

    

}
int main(){
    test1();

    return 0;
}