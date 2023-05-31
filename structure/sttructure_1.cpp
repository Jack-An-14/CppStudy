#include <iostream>
#include <string>

using namespace std;

struct Student{
    string name;
    int age;
    int score;
};

int main() {
    Student s1;
    s1.name = "maojie";
    s1.age = 24;
    s1.score = 100;

    cout << s1.name << " " << s1.age << " " << s1.score << endl;
    
    return 0;
}