#include <iostream>

using namespace std;

class Student{
public:
    string name;
    string number;
    void print(){
        cout << name << " " << number << endl;
    }
};
int main(){
    Student s1;
    s1.name = "maojie";
    s1.number = "20191112422";

    s1.print();
    
    return 0;
}