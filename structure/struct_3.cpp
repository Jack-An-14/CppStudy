//关于const在结构体中应用
#include <iostream>
#include <string>

using namespace std;
struct Student{
    string name;
    int age;
};
//将参数设置为常量可以防止误操作
void printStudent(const Student* s){
    //s->age = 20; 这里会报错：s为不可修改的左值。这里还是常量指针，指针的指向可以修改，但是指针所指的内容不可以修改
    cout << s->age << " " << s->name << endl;
};

int main() {
    Student s1 = {"maojie", 24};
    printStudent(&s1);

    return 0;
}