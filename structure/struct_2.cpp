#include <iostream>
#include <string>

using namespace std;
struct student {
    string name;
    int age;
};

int main() {
    student* s1 = new student();
    s1->age = 10;
    s1->name = "maojie";

    cout << s1->age << " " << s1->name << endl;


    return 0;
}