//普通员工的文件
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Employee : public Worker{
    public:
        virtual void showInfo();

        virtual string getDeptName();   

        Employee(int id, string name, int dId); 
};