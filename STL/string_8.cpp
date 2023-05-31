//string子串获取
//substr
#include <iostream>
#include <string>
using namespace std;

void test1(){
    string str = "abcdefg";
    string sub = str.substr(1, 3);
    cout  << sub << endl;
    string su = str.substr(0, str.find('c'));
    cout << su << endl;
}
int main(){
    test1();
    return 0;
}