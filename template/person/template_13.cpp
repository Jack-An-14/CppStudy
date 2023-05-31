//第一种解决方式：直接包含cpp文件
// #include "person.cpp"
//第二种解决方式，将h和cpp文件内容写在一起,改为hpp文件
#include "person.hpp"
using namespace std;
void test(){
    Person<string, int> p("maojei", 18);
    p.showPerson();
} 
int main(){
    test();
    return 0;
}