# 一、函数的分文件编写

​	1、先创建.h后缀名的头文件

​	2、创建.cpp后缀名的源文件

​	3、在头文件中写函数的申明

​	4、在源文件中写函数的定义

# 二、指针

​	1、指针的定义和使用。指针保存的是变量的存储地址，是16进制数字

![image-20230329210840401](/Users/an/Library/Application Support/typora-user-images/image-20230329210840401.png)



​	对指针解引用，在变量前加*，即可获得指针地址保存的内容

​	2、指针所占的内存空间是多少呢？

​		32位操作系统下，占4个字节；64位操作系统下，占8个字节

​	3、空指针和野指针

​		空指针

​		![image-20230330093551776](/Users/an/Library/Application Support/typora-user-images/image-20230330093551776.png)

​		野指针：指针变量指向非法的内存空间。

总结：空指针和野指针的内存空间都禁止访问。

​	4、const修饰指针

​		1）const修饰指针 --常量指针

![image-20230330101957629](/Users/an/Library/Application Support/typora-user-images/image-20230330101957629.png)

​		2）const修饰常量 --指针常量

![image-20230330102038361](/Users/an/Library/Application Support/typora-user-images/image-20230330102038361.png)



​		3）const既修饰指针，又修饰常量

![image-20230330102107482](/Users/an/Library/Application Support/typora-user-images/image-20230330102107482.png)

报错的原因都是左值无法修改。	

总结：看const修饰谁，修饰指针，常量指针；修饰常量， 指针常量。

​	5、指针和数组，利用指针来访问数组，数组名就是数组首地址，利用指针自增操作即可。

![image-20230330103218122](/Users/an/Library/Application Support/typora-user-images/image-20230330103218122.png)

​	6、形参和实参。引用传递，即把指针传入函数，函数对指针的内容进行修改，就可以实际操作地址的内容。



# 三、关于随机数部分内容

​	1、真随机

​	![image-20230401222439457](/Users/an/Library/Application Support/typora-user-images/image-20230401222439457.png)

​	2、伪随机

![image-20230401222453228](/Users/an/Library/Application Support/typora-user-images/image-20230401222453228.png)

​	3、如何设置随机数的范围，同上。



# 四、内存分区模型

​	4个区域，代码区和全局区是程序运行前九存在的

​	1、代码区：存放函数体的二进制代码，有操作系统进行管理

​						存放CPU执行的机器指令

​						代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可

​						代码区是只读的，使其只读的原因是防止程序意外的修改了它的指令

​	2、全局区：存放全局变量和静态变量以及常量

​						全局区包含常量区，常量区包括字符串常量和其他常量

​						该区域的数据在程序结束后由操作系统释放

总结：C++在程序运行前分为全局区和代码区，代码区的特点是共享和只读，全局区存放全局变量、静态变量、常量，常量区存放const修饰的全局常量和字符串常量

​	3、栈区：由编译器自动分配释放，存放函数的参数值，局部变量等

​					

​	4、堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收，C++主要利用new在堆区开辟内存。

new和delete

![image-20230403165138097](/Users/an/Library/Application Support/typora-user-images/image-20230403165138097.png)

# 五、引用	给变量起别名

​	如果函数的返回值为引用，则可以作为左值存在

![image-20230403174957398](/Users/an/Library/Application Support/typora-user-images/image-20230403174957398.png)

![image-20230403174948622](/Users/an/Library/Application Support/typora-user-images/image-20230403174948622.png)

引用的本质：指针常量，指针的指向不可以改变，但是指针指向的内容可以改变

# 六、函数的默认参数

直接函数形参中设置默认值即可

注意事项：1、如果某位置已经有了默认参数，从该位置从左到右都必须有默认值

​				  2、如果函数申明有默认参数，函数实现就不能带有默认参数，否则会出现二义性

# 七、函数重载

​	函数重载条件：1、同一个作用域下

​								2、函数名称相同

​								3、函数参数类型不同，或者个数不同，或者顺序不同

​	注意事项：函数的返回值不可以作为函数重载的条件

​						引用作为函数参数的时候，const 和 不const 属于两种参数类型

​						函数重载遇到默认参数的时候，会产生二义性

![image-20230407214056227](/Users/an/Library/Application Support/typora-user-images/image-20230407214056227.png)

![image-20230407214030993](/Users/an/Library/Application Support/typora-user-images/image-20230407214030993.png)

# 八、c++类和对象

C++oop三大特性：封装、继承、多态

## 1、封装

​	三种权限

​	public	类内可以访问，类外可以访问

​	proteced 类内可以访问，类外不可以访问，子类可以访问父类的保护内容

​	private 类内可以访问，类外不可以访问，子类不可以访问父类的私有内容



![image-20230407225406707](/Users/an/Library/Application Support/typora-user-images/image-20230407225406707.png)

​	struct & class区别

struct的默认权限为公共 public

class的默认权限为私有 private



## 2、对象的初始化和清理

​	2.1构造函数和析构函数，构造函数和析构函数都是由编译器自动调用。如果不提供构造和析构，编译器会提供两个函数，但是默认函数都是空实现。

​	构造函数语法	类名(){}

​	1、构造函数，没有返回值也不写void

​	2、函数名称与类名相同

​	3、函数构造可以有参数，也可以重载

​	4、程序在调用对象时候会自动调用构造，无需手动调用，而且只会调用一次



​	析构函数	~类名(){}

​	1、析构函数，没有返回值也不写void

​	2、函数名称与类名相同，在名称前加～

​	3、析构函数不可以有参数，不可以重载

​	4、程序在对象销毁钱会自动调用析构，无须手动调用，而且只会调用一次



# 深拷贝和浅拷贝

浅拷贝：简单的赋值操作

深拷贝：在堆区重新申请空间，进行拷贝操作

![image-20230413105127920](/Users/an/Library/Application Support/typora-user-images/image-20230413105127920.png)

# 静态成员变量和静态成员函数

## 	1、静态成员变量

​		所有对象共享同一份数据

​		在编译阶段分配内存

​		类内申明，类外初始化

​	![image-20230414105928309](/Users/an/Library/Application Support/typora-user-images/image-20230414105928309.png)

​	

```C++
//静态成员：在成员变量和成员函数之前加上关键字static
//静态成员变量和静态成员函数
#include <iostream>
using namespace std;
class Person{
    public:
        static int mA;
        //静态成员变量也有访问权限
    private:
        static int sMA;    
};
int Person::mA = 100;
int Person::sMA = 20;
void test1(){
    Person p;
    cout << p.mA <<endl;

    Person p2;
    p2.mA = 200;
    //共享同一份数据
    cout << p.mA << endl;
}

void test2(){
    //静态成员变量，不属于某个对象，所有对象都共享同一份数据
    //因此静态成员变量由两种访问方式

    //1、通过对象进行访问
    Person p;
    cout << p.mA << endl;
    //2、通过类名进行访问
    cout << Person::mA << endl;
    
    //这里的私有静态成员变量是不能访问的
    //cout << Person::sMA << endl;
}
int main(){

    test1();
  	test2();
    return 0;
}
```

## 2、静态成员函数

​	静态成员函数

​	所有对象共享同一个函数

​	静态成员函数只能访问静态成员变量

```C++
//静态成员函数
#include <iostream>
using namespace std;
class Person{
public:
    static void func(){
        cout << "静态成员函数" << endl;
        m_A = 100;//静态成员函数可以访问静态成员变量
        m_B = 10;//静态成员函数不可以访问非静态成员变量，无法区分是哪个对象的m_B
    } 

    static int m_A;//静态成员变量
    int m_B;

    //静态成员函数也是有访问权限的
private:
    static void func2(){
        cout << "私有的静态成员函数" <<endl;
    }
};

int Person::m_A = 0;
void test1(){
    //1、通过对象访问
    Person p;
    p.func();

    //2、通过类名访问
    Person::func();
}
int main(){
    test1();
    Person::func2 (Inaccessible);//私有静态成员函数，类外无法访问
    return 0;
}
```

## 3、成员函数和成员变量分开存储

```C++
//成员变量和成员函数分开存储
#include <iostream>
using namespace std;

class Person{
    int m_A;//非静态成员变量 属于类对象上

public:
    static int m_B;//静态成员变量并不属于类对象上

    void func(){};//非静态成员函数 只一份就可以，不属于类的对象上
    
    static void func2(){};//静态成员函数 只一份 不属于类对象上
};

int Person::m_B = 10;
void test1(){
    Person p;
    //空对象占用的内存空间为？ 答案为1		重点 面试常考
    //C++编译器会给每个空对象也分配一个字节的空间，为了区分空对象占内存的位置
    //每个空对象也应该有一个独一无二的内存地址
    cout << "size of person " << sizeof(p) <<endl;
}

void test2(){
    Person p;
    cout << "size of person " << sizeof(p) <<endl;
}
int main() {
    test2();    
    return 0;
}
```

​        

## this指针

this指针指向被调用的成员函数所属的对象

​	this指针是隐含在每一个非静态成员函数内的一种指针

​	this指针不需要定义，直接使用即可

用途：

1、当形参和成员变量同名时，用this来区分

2、在类的非静态成员函数中返回对象本身 ，使用return *this

```C++
//this指针
#include <iostream>
using namespace std;

class Person{
public:
    Person(int age){
        //this指针指向被调用的成员函数所属的对象
        this->age = age;
    }

    int age;

    //返回Person，会调用拷贝构造函数，会创建新的对象
    Person& PersonAddAge(Person & p){
        this->age += p.age;

        return *this;
    }
};

void test1(){
    Person p1(18);
    cout << p1.age << endl;
}

void test2() {
    Person p1(10);

    Person p2(11);
    //链式编程思想
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

    cout << p2.age << endl;

}
int main(){
    test2();
    return 0;
}
```

## 空指针访问成员函数

C++空指针也可以调用成员函数，但是也要注意有咩有用到this指针

如果用到this指针，需要加以判断代码的健壮性

```C++
//空指针调用成员函数
#include <iostream>
using namespace std;

class Person{
    public:
        void showClassName(){
            cout << "this is Person class" << endl;
        }

        void showPersonAge(){
            //报错原因是传入的指针为空
            if(this == NULL){	//代码健壮性
                return;
            }
            cout << "age = " << m_Age << endl;
        }

        int m_Age;
};

void test1(){
    Person * p = NULL;
    p->showClassName();
    p->showPersonAge(); //报错
}
int main() {
    test1();
    return 0;
}
```

## const修饰成员函数

常函数

​	成员函数后加const，则这个函数为常函数

​	常函数内不可以修改成员属性

​	成员属性申明时加关键字mutable之后，在常函数中依然可以修改

常对象

​	声明对象前加const的对象为常对象

​	常对象只能调用常函数

```c++
//const修饰成员函数
#include <iostream>
using namespace std;

class Person{
    public:
        Person(){}
    //this指针的本质 是指针常量 指针的指向是不可以修改的
    //const Person* const this;
    //在成员函数后面加const，本质修饰的是this指针，让this指针指向的值也不能修改
        void showPerson() const
        {
            m_B = 100;
            // this->m_A = 100;
            // this = NULL; this指针不可以修改指针的指向
        }
        
        void func(){
            cout << "func" << endl;
        }

        int m_A;
        mutable int m_B;    //特殊变量，即使在常函数中，也可以修改这个值，变量前+mutable; 常对象下也可以修改
};

void test1(){
    Person p;
    p.showPerson();
}

void test2(){
    const Person p; //在对象前+const，变为常对象
    p.m_A = 100;    //常对象不允许修改普通成员变量
    p.m_B = 100;

    //常对象只能调用常函数
    p.showPerson();
    //常对象不可以调用普通成员函数，因为普通成员函数可以修改成员变量
    p.func();
}

int main(){

    return 0;
}
```

## 友元

三种实现

​	1、全局函数做友元

​	2、类做友元

​	3、成员函数做友元

### 全局函数做友元

```c++
//友元
//1、全局函数做友元
#include <iostream>
using namespace std;

//建筑物类
class Building{
    //goodGay全局函数是Building好朋友，可以访问building的私有成员 
    friend void goodGay(Building& build);//======================
    
    public:
        string m_SittingRoom; //客厅

        Building(){
            m_SittingRoom = "客厅";
            m_BedRoom = "卧室";
        }

    private:
        string m_BedRoom;//卧室
};

//全局函数
void goodGay(Building& build){
    cout << build.m_SittingRoom << endl;
    cout << build.m_BedRoom << endl;
}

void test1(){
    Building b;
    goodGay(b);
}
int main(){
    test1();
    return 0;
}
```

### 类做友元（友元类）

```c++
//类做友元
#include <iostream>
using namespace std;
class Building{
    //GoodGay是本类的好朋友，可以访问Building的私有成员
    friend class GoodGay;   //=======================
    public:
        Building();
        string m_SittingRoom;
    private:
        string m_BedRoom;
};
class GoodGay{
    

    public:
        Building * build;
        GoodGay();
        void visit();//参观函数 访问Building中的属性
};

//类外写成员函数
Building::Building(){
    m_BedRoom = "卧室";
    m_SittingRoom = "客厅";
}

GoodGay::GoodGay(){
    //创建一个建筑物对象
    build = new Building;
}

void GoodGay::visit(){
    cout << "好基友类正在访问:" << build->m_SittingRoom << endl;
    cout << "好基友类正在访问:" << build->m_BedRoom << endl;
}

void test1(){
    GoodGay gy;
    gy.visit();
}

int main(){
    
    test1();
    return 0;
}
```

### 成员函数做友元

```c++
//成员函数做友元
#include <iostream>
#include <string>
using namespace std;
class Building;
class Goodgay{
    public:
        Goodgay();
        Building * build;
        void visit();//让visit函数可以访问Building中私有成员函数
        void visit2();//让visit2函数不可以访问Building中私有成员
};
class Building{
    //告诉编译器 goodgay类下的visit成员函数作为本类的好朋友 ，可以访问私有成员
    friend void Goodgay::visit();   //=======================
    public:
        string m_Sittingroom;
        Building();
    private:
        string m_Bedroom;
};

Goodgay::Goodgay(){
    build = new Building;
}
void Goodgay::visit(){
    cout << "visit访问:" << build->m_Sittingroom <<endl;
    cout << "visit访问:" << build->m_Bedroom <<endl;
}

void Goodgay::visit2(){
    cout << "visit2访问:" << build->m_Sittingroom <<endl;
    // cout << "visit访问:" << build->m_Bedroom <<endl;
}
Building::Building(){
    m_Bedroom = "卧室";
    m_Sittingroom = "客厅";
}

void test1() {
    Goodgay gy;
    gy.visit();
    gy.visit2();
}
int main(){
    test1();
    return 0;
}
```

## 运算符重载

概念：对已有运算符重新进行定义，赋予新功能

### 成员函数重载+号，全局函数重载+号

总结1:对于内置数据类型的表达式的运算符不可以改变

总结2:不要滥用运算符重载

```c++
//运算符重载
//1、加号重载
#include <iostream>
using namespace std;
class Person{
    public:
        int m_A;
        int m_B;
        
        //成员函数重载形式
        //本质：Person p3 = p1.operator+(p2);
        Person operator+(Person & p){
            Person temp;
            temp.m_A = this->m_A + p.m_A;
            temp.m_B = this->m_B + p.m_B;

            return temp;
        }
};

//全局函数重载形式
//本质：Person p3 = operator+(p1, p2)
// Person operator+(Person & p1, Person & p2){
//     Person temp;
//     temp.m_A = p1.m_A + p2.m_A;
//     temp.m_B = p1.m_B + p2.m_B;
//     return temp;
// }

void test1(){
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;
    Person p2;
    p2.m_A = 10;
    p2.m_B = 10;

    Person p3 = p1 + p2;
    cout << p3.m_A << " " << p3.m_B << endl;
}
//运算符重载，也可以发生函数重载
Person operator+(Person p1, int a){
    Person temp;
    temp.m_A = p1.m_A + a;
    temp.m_B = p1.m_B + a;
    return temp;
}
void test2(){
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;

    Person p2 = p1 + 20;
    cout << p2.m_A << " " << p2.m_B << endl;
}

int main(){
    test1();
    test2();
    return 0;
}
```

### 左移运算符重载 <<

```c++
//左移运算符
#include <iostream>
using namespace std;
class Person{
    friend ostream& operator<< (ostream & out , Person & p);
    public:
        Person(){
            m_A = m_B = 10;
        }
    private:
        int m_A;
        int m_B;
};
//通常不使用成员函数去重载左移运算符==========================
ostream& operator<< (ostream & out , Person & p){
    out << p.m_A << " " << p.m_B;
    return out;
} //本质:operator<< (cout, p)  简化 cout << p
void test1(){
    Person p1;

    cout << p1 << "add somethis" << endl;
}
int main() {
    test1();
    return 0;
}
```

总结：通过重载左移和友元函数，可以实现自定义数据结构的输出

### 递增运算符重载

分为前置递增和后置递增

结论：前置递增返回引用，后置递增返回值

```c++
//递增运算符重载
//作用:通过重载递增运算符，实现整形
#include <iostream>
using namespace std;
class MyInteger{
    friend ostream & operator<<(ostream & out, MyInteger t);
    public:
        MyInteger(){
            m_num = 0;
        }
    //重载前置++运算符
    //为什么返回引用？返回引用是为了一直对一个数据进行操作
        MyInteger & operator++(){
            this->m_num ++;
            return *this;
        }
    //重载后置++运算符
    // void operator++(int) int代表占位参数，可以用于区分前置和后置递增
    // 后置递增一定要返回值，因为临时变量在函数结束后，被释放，返回引用会导致错误的内存指向
        MyInteger operator++(int){ 
            //先返回结果 记录当时结果
            MyInteger temp = *this;
            //后递增
            m_num++;
        
            //最后将记录结果做返回
            return temp;
        }
    private:
        int m_num;
};
ostream & operator<<(ostream & out, MyInteger t){
    out << t.m_num;
    return out;
}
void test1(){
    MyInteger myint;
    cout << ++(++myint) << endl;
    cout << myint << endl;
}

void test2(){
    MyInteger m;
    cout << m++ << endl;
    cout << m << endl;
}

int main(){
    // test1();
    test2();
    return 0;
}
//前置递增和后置递增

```

### 赋值运算符重载

```c++
//赋值运算符重载
#include <iostream>
using namespace std;

class Person{
    public:
        int * m_age;

        Person(int age){
            m_age = new int(age);
        }
        ~Person(){
            if(m_age != NULL){
                delete m_age;
                m_age = NULL;
            }
        }
        Person& operator=(Person & p){
            //应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
            //释放内存
            if(m_age != NULL){
                delete m_age;
                m_age = NULL;
            }

            //深拷贝
            m_age = new int(*p.m_age);

            return *this;
        }
};

void test1() {
    Person p1(19);

    cout << *p1.m_age << endl;

    Person p2(20);
    cout << *p2.m_age << endl;

    p2 = p1;    //赋值操作
    //堆区内存重复释放，利用深拷贝解决浅拷贝问题

    Person p3(30);
    p3 = p2 = p1;
    cout << *p3.m_age << endl;
}
int main(){
    test1();
    return 0;
}
```

### 关系运算符重载

```c++
//关系运算符重载
#include <iostream>
using namespace std;
class Person{
    public:
        string m_Name;
        int m_Age;

        Person(string name, int age){
            m_Name = name;
            m_Age = age;
        }

        bool operator==(Person & p) {
            return this->m_Age == p.m_Age && this->m_Name == p.m_Name;
        }

        bool operator!=(Person & p){
            return this->m_Age != p.m_Age || this->m_Name != p.m_Name;
        }
};

void test1(){

    Person p1("Tom", 18);
    Person p2("Tom", 18);

    if(p1 == p2){
        cout << "equal" << endl;
    }else {
        cout << "inequal" << endl;
    }

    if(p1 != p2){
        cout << "inequal" << endl;
    }else {
        cout << "equal" << endl;
    }
}
int main() {
    test1();
    return 0;
}
```

### 函数调用运算符的重载

​	函数调用运算符（）重载

​	由于重载后使用的方式非常像函数的调用，别名仿函数

​	仿函数没有固定写法，非常灵活

```c++
//函数调用运算符的重载
#include <iostream>
#include <string>
using namespace std;
class MyPrint{
    public:
        //重载函数调用运算符
        void operator()(string test){
            cout << test << endl;
        }
};

void test1(){
    MyPrint p;
    p("hello world");//非常类似函数调用，别名仿函数
}

//仿函数非常灵活，没有固定的写法
class MyAdd{
    public:
        int operator()(int a, int b){
            return a+b;
        }
};

void test2(){
    MyAdd add;
    cout << add(10, 20) << endl;

    //匿名函数对象
    cout << MyAdd()(10, 10) << endl;
}
int main() {

    // test1();
    test2();
    return 0;
}
```

## 继承

继承的好处：减少重复代码

```c++
//Java页面
//		子类		继承方式	父类
class Java : public BasePage{
    public:
        void content(){
            cout << "java视频" << endl;
        }
};

//子类也就派生类，父类也叫基类
//子类中的成员包含两部分
//一是从父类继承过来的，一类是自己增加的成员
//从积累继承过来的表现其共性，新增的成员体现了个性
 
```

### 继承方式

继承语法： class 子类：继承方式 父类

继承方式：公共、私有、保护

![](/Users/an/Downloads/IMG_8B21ACD5B438-1的副本.jpeg)

```c++
//继承方式
#include <iostream>
using namespace std;
class A{
    public:
        int a;
    protected:
        int b;
    private:
        int c;
};

//protected 子类可以访问父类的保护内容
//公共继承
class Son1 : public A{
    public:
        void func(){
            cout << a << b << c << endl;
        }
};

//保护继承
class Son2 : protected A{
    public:
        void func(){
            cout << a << b << c << endl;
        }
};

//私有继承
class Son3 : private A{
    public:
        void func(){
            cout << a << b << c << endl;
        }
};
void test1(){
    Son1 s1;
    s1.a = 10;
    s1.b = 10;//在Son1中为保护权限，类外无法访问

    Son2 s2;
    s2.a = 10;//在Son2中为保权限，类外无法访问

    Son3 s3;
    s3.a = 10;//在Son3中为私有权限，类外无法访问
}
int main() {

    return 0;
}
```

### 继承中的对象模型

```c++
//继承中的对象模型
//问题：从父类继承过来的成员，哪些属于子类对象中
#include <iostream>
using namespace std;
class Base{
    public:
        int m_A;  
    protected:
        int m_B;
    private:
        int m_C;
};

class Son : public Base{
    public:
        int m_D;
};

void test1(){
    //Son为16，说明所有的属性都继承了下来
    //父类中所有的非静态成员都会被继承下来。私有成员被编译器隐藏
    cout << sizeof(Son) << endl;
}
int main() {
    test1();
    return 0;
}
```

### 继承中构造和析构顺序

总结：先父类构造，再子类构造；先子类析构，再父类析构

```c++
//继承中构造和析构的顺序
//子类继承父类后，当创建子类对象，也会调用父类的构造函数
//问题：构造和析构顺序
#include <iostream>
using namespace std;
class Base{
    public:
        Base(){
            cout << "Base构造函数" << endl;
        }

        ~Base(){
            cout << "Base的析构函数" << endl;
        }
};

class Child : public Base{
    public:
        Child(){
            cout << "Child构造函数" << endl;
        }

        ~Child(){
            cout << "Child的析构函数" << endl;
        }
};

void test1(){
    Child c;
}
int main(){
    test1();
    return 0;
}

/*运行结果，类似栈的形式。先构造父类，在构造子类；先析构子类，在析构父类
Base构造函数
Child构造函数
Child的析构函数
Base的析构函数
*/
```

### 同名成员处理方式

结论：

​	子类对象可以直接访问子类的同名成员

​	加作用域，可以访问父类的成员

​	当子类与父类拥有同名的成员函数，子类会隐藏父类中所有的同名成员函数。加作用域可以访问父类中的同名成员函数

```c++
//继承同名成员处理方式
//问题：当子类与父类出现同名成员，如何通过子类对象，访问到子类或父类总的同名成员？
//访问子类同名成员，直接访问
//访问父类的同名成员，加作用域

#include <iostream>
using namespace std;
class Base{
    public:
        Base(){
            m_A = 100;
        }
        int m_A;

        void print(){
            cout << "BASE print" << endl;
        }

        void print(int a) {
            cout << "BASE print int" << endl;
        }
};

class Son : public Base{
    public:
        Son(){
            m_A = 200;
        }
        int m_A;

        void print(){
            cout << "Son print" << endl;
        }
};

void test1(){
    Son s;
    cout << s.m_A << endl;
    //加作用域
    cout << s.Base::m_A << endl;
}

void test2(){
    Son s;
    s.print();
    //同样的访问语法
    s.Base::print();
    //如果子类中出现与父类同名的成员函数，子类的同名成员会隐藏掉父类中所有的同名成员函数
    //加作用域即可
    s.Base::print(10);
}
int main() {
    test1();
    test2();
    return 0;
}
```

### 继承同名静态成员处理

```c++
//继承同名静态成员处理方式
//问题：继承中同名的静态成员在子类对象如何进行访问
//静态成员和非静态成员出现同名，处理方式一样
#include <iostream>
using namespace std;
class Base{
    public:
        static int m_A;
        static void func(){
            cout << "Base static" << endl;
        }
};
int Base::m_A = 100;

class Son : public Base{
    public:
        static int m_A;
        static void func(){
            cout << "Son static" << endl;
        }
};
int Son::m_A = 200;

void test1(){
    //
    Son s1;
    //输出200，访问的是Son中的m_A
    cout << s1.m_A << endl;
    //输出100，访问的是Base中的m_A
    cout << s1.Base::m_A << endl;

    //通过类名
    cout << Son::m_A << endl;
    cout << Base::m_A << endl;
    //第一个::代表通过类名方式访问， 第二个::代表访问父类作用域下
    cout << Son::Base::m_A << endl;
}

void test2(){
    //通过对象访问
    Son s;
    s.func();
    s.Base::func();

    //通过类名来访问
    Son::func();
    Base::func();
    Son::Base::func();
}
int main(){
    // test1();
    test2();
    return 0;
}
```

### 多继承语法

C++允许一个类继承多个类

C++开发中不建议使用多继承

```c++
//多继承语法
#include <iostream>
using namespace std;
class Base{
    public:
        Base(){
            m_A = 100;
        }
        int m_A;
};

class Base2{
    public:
        Base2(){
            m_A = 200;
        }
        int m_A;
};
//多继承语法
class Son : public Base, public Base2{
    public:
        Son(){
            m_C = 100;
            m_D = 100;
        }

        int m_C;
        int m_D;
};


void test1(){
    Son s;
    cout << sizeof(s) << endl;
    //base 和 base2中都有m_A，直接访问会导致二义性，编译器不明白是哪一个m_A。加作用域
    cout << s.m_A << endl;
    cout << s.Base::m_A << endl;
    cout << s.Base2::m_A << endl;
    cout << s.m_C << endl;
    cout << s.m_D << endl;
}

int main(){
    test1();
    return 0;
}
```

### 菱形继承

概念：两个派生类继承同一个基类，又有某个类同时继承两个派生类，形状为菱形，称为菱形继承

```c++
//菱形继承
#include <iostream>
using namespace std;
class Animal{
    public:
        
        int m_Age;
};
//虚继承可以解决菱形继承的问题
//继承之前 加上关键字 virtual 变为虚继承
//Animal 为 虚基类
class Sheep : virtual public Animal{};
class Tuo : virtual public Animal{};
class SheepTuo : public Sheep, public Tuo{};

void test1(){
    SheepTuo st;
    st.Sheep::m_Age = 18;
    st.Tuo::m_Age = 28;
    cout <<  st.Sheep::m_Age<< endl;
    cout << st.Tuo::m_Age << endl;
    cout << st.m_Age << endl;
    

    //这份数据，我们知道只要有一份就可以了，菱形数据导致数据有两份，导致资源浪费
}
int main(){
    test1();
    return 0;
}

//vbptr 虚基类指针 virtual base pointer
//vbptr 指向vbtable，指向虚基类表格， 记录偏移量，指向同一份数据
```

## 多态

多态分为两类

​	1、静态多态：函数重载和运算符重载，复用函数名

​	2、动态多态：派生类和虚函数实现动态多态

静态多态和动态多态区别：

​	静态多态的函数地址早绑定-编译阶段确定函数地址

​	动态多态的函数地址晚绑定-运行阶段确定函数地址

```c++
//多态
#include <iostream>
using namespace std;

class Animal{
    public:
    //在speak前加关键字virtual
        virtual void speak(){
            cout << "animal speak" << endl;
        }
};

class Cat : public Animal{
    public:
        void speak(){
            cout << "cat speak" << endl;
        }
};

class Dog : public Animal{
    public:
    //重写  函数返回值类型 函数名 参数列表 完全相同
        void speak(){
            cout << "Dog speak" << endl;
        }
};

//地址早绑定，在编译阶段就确定了函数的地址
//如果想执行猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
//动态多态满足条件
//1、有继承关系
//2、子类要重写父类的虚函数

//动态多态使用
//父类的指针或者引用 指向子类对象
void doSpeak(Animal & animal){
    animal.speak();
}

void test1(){
    Cat cat;

    //C++中允许父子之间的类型转换
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
}
int main(){
    test1();
    return 0;
}
```

## 多态原理

​	在Animal类中写虚函数，Animal类内部结构发生变化，内部产生一个vfptr 虚函数指针指向vftable虚函数表。当子类没有重写speak方法的时候，子类继承Animal中的虚函数。当子类重写虚函数的时候，子类重写的函数会覆盖Animal类的虚函数。

## 多态案例1-计算器

```c++
#include <iostream>
using namespace std;

class Calculator{
    public:
        int getResult(string oper){
            if(oper == "+"){
                return m_Num1 + m_Num2;
            }
            else if (oper == "-"){
                return m_Num1 - m_Num2;
            }
            else if(oper == "*"){
                return m_Num1 * m_Num2;
            }

            return 0;
        }

        int m_Num1;
        int m_Num2;
};
//如果想扩展新的功能，需要修改源码
//在真实开发中，提倡开闭原则
//开闭原则：对扩展进行开放，对修改进行关闭
//多态的好处
//1、组织结构清晰
//2、可读性强 
//3、对于前期和后期的维护性高

class AbstractCalculator{
    public:
        virtual int getResult(){
            return 0;
        }

        int m_Num1;
        int m_Num2;
};

//加法计算器的类
class AddCalculator : public AbstractCalculator{
    public:
        int getResult(){
            return m_Num1 + m_Num2;
        }
};

class SubCalculator : public AbstractCalculator{
    public:
        int getResult(){
            return m_Num1 - m_Num2;
        }
};

class MulCalculator : public AbstractCalculator{
    public:
        int getResult(){
            return m_Num1 * m_Num2;
        }
};

void test1(){
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;

    cout << c.getResult("+") << endl;
}

void test2(){
    //多态使用条件
    //父类指针或者引用指向子类对象
    AbstractCalculator * abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << abc->getResult() <<endl;

    //用完之后，需要销毁
    delete abc;

    abc = new SubCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << abc->getResult() <<endl;

    delete abc;
}
int main(){

    // test1();

    test2();
    return 0;
}
```

## 纯虚函数和抽象类

抽象类特点：

​	无法实例化对象

​	子类必须重写抽象类中的纯虚函数，否则也属于抽象类

```c++
//纯虚函数和抽象类
//纯虚函数语法      virtual 返回值类型  函数名  （参数） = 0
//当类中有了纯虚函数，这个类也称为抽象类
#include <iostream>
using namespace std;

class Base{
    public:
    //纯虚函数
    //只要有一个纯虚函数，这个类称为抽象类。
        virtual void func() = 0;
};

class Son : public Base{
    public:
        void func(){
            cout << "Son的重写函数" << endl;
        }

};

void test1(){
    
    // Base b; 无法实例化抽象类
    //Son s; 子类必须重写父类的虚函数，否则就是抽象类，无法实例化
    Base * base = new Son;
    base->func();
    delete base;
}
int main(){
    test1();
    return 0;
}
```

## 虚析构和纯虚析构

总结：

​	1、虚析构或纯虚析构就是用来解决通过父类指针释放子类对象

​	2、如果子类中没有堆区数据，可以不写虚析构或纯虚析构

​	3、拥有纯虚析构函数的类也属于抽象类

虚析构和纯虚析构的共性

​	可以解决父类指针释放子对象

​	都需要有具体的函数实现

虚析构和纯虚析构区别

​	如果是纯虚析构，该类属于抽象类，无法实例化对象

虚析构语法：

​	virtual ~类名(){}

纯虚析构语法：

​	virtual ~类名() = 0	类内声明

​	类名::～类名(){}	类外实现

```c++
//虚析构和纯虚析构
//问题：多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码

//解决方式：将父类中的析构函数改为虚析构或者纯虚析构
#include <iostream>
#include <string>
using namespace std;
class Animal{
    public:
        //纯虚函数
        virtual void speak() = 0;
        Animal(){
            cout << "Animal构造函数调用" << endl;
        }


        //利用虚析构，可以解决父类指针释放子类对象，释放不干净的问题
        // virtual ~Animal(){
        //     cout << "Animal的析构函数调用" << endl;
        // }


        //纯虚析构，需要声明也需要实现
        virtual ~Animal() = 0;
        //有了纯虚析构后，这个类也属于抽象类，无法实例化对象
};

//纯虚析构函数实现
Animal::~Animal(){
    cout << "Animal的纯虚析构函数调用" << endl;
}

class Cat : public Animal{
    public:

        Cat(string name){
            mName = new string(name);
            cout << "Cat构造函数调用" << endl;
        }
        void speak(){
            cout << *mName <<" cat speak" << endl;
        }

        string * mName;

        ~Cat(){
            if(mName != NULL){
                delete mName;
            }
            mName = NULL;
            cout << "Cat析构函数调用" << endl;
        }
};

void test1(){
    Animal * a = new Cat("Tom");
    a->speak();
    //父类指针在析构的时候，不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
    delete a;
}
int main(){
    test1();
    return 0;
}
```

# 九、文件操作

c++通过文件将数据持久化

c++中对文件操作需要包含头文件<fstream>

文件类型

​	1、文本文件	文本以文本的ASCII码形式存贮在计算机中

​	2、二进制文件	文本以二进制形式存储在计算机中，用户无法直接读懂

操作文件的三大类

​	1、ofstream 写操作

​	2、ifstream	读操作

​	3、fstream	读写操作

## 文本文件

​	写文件，步骤

​		1、包含头文件

```c++
 #include <fstream>
```

​		2、创建流对象 

```c++
ofstream ofs
```

​		3、打开文件	

```c++
ofs.open("文件路径", 打开方式)
```

​		4、写数据

```c++
ofs << "数据";
```

​		5、关闭文件

```c++
ofs.close();
```

![IMG_0464DE6AD061-1](/Users/an/Downloads/IMG_0464DE6AD061-1.jpeg)

​	读文件，步骤

​		1、包含头文件

​		2、创建流对象

​		3、打开文件并判断文件是否成功打开

​		4、读数据

​		5、关闭文件流

总结：

​	读文件可以利用ifstream，或者fstream类

​	利用is_open()函数可以判断文件是否可以打开成功

​	close关闭文件

```c++
//读文件
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test1(){
    
    //创建流对象
    ifstream ifs;
    //打开文件并且判断文件是否打开成功
    ifs.open("test.txt", ios::in);

    if(!ifs.is_open()){
        cout << "文件打开失败" << endl;

        return ;
    }
    //读数据

    //第一种
    char buf[1024] = {0};
    while (ifs >> buf){
        cout << buf <<endl;
    }
    
    //第二种
    char buf2[1024] = {0};
    while (ifs.getline(buf2, sizeof(buf2))){
        cout << buf2 << endl;
    }
    

    

    //第三种
    string buf3;
    while (getline(ifs, buf3)){
        cout << buf3 << endl;
    }

    //第四种
    //EOF文件尾
    char c;
    while ((c = ifs.get()) != EOF){
        cout << c;
    }
    //关闭文件
    ifs.close();
}

int main(){
    test1();
    return 0;
}
```

## 二进制文件

写文件：准备数据，调用write函数

```c++
ofs.write((const chat*) &p, sizeof(p));
```

```c++
//二进制文件读写操作
#include <iostream>
#include <fstream>
using namespace std;
//二进制写文件

class Person{
    public:
        char mName[64];//姓名
        int mAge;//年龄
};

void test(){
    ofstream ofs;
    ofs.open("person.txt", ios::out | ios::binary);

    Person p = {"张三", 18};
    ofs.write((const char *) &p, sizeof(Person));

    ofs.close();
}
int main(){
    test();
    return 0;
}
```

读文件

调用read函数，以二进制的方式读数据

```c++
//二进制读文件
#include <iostream>
#include <fstream>
using namespace std;

class Person{
    public:
        char mName[64];//姓名
        int mAge;//年龄
};

void test(){
    ifstream ifs;
    ifs.open("person.txt", ios::in | ios::binary);

    if(!ifs.is_open()){
        cout << "读文件失败" << endl;
    }

    Person p;
    ifs.read((char *) & p, sizeof(Person));
    cout << p.mName << endl;
    cout << p.mAge << endl;
    ifs.close();
}
int main(){
    test();
    return 0;
}
```

# 十、模版编程

## 概念:范型

​	特点：模版不可以直接使用，他只是一个框架

​				模版的通用并不是万能的

模版：函数模版和类模版

## 函数模版

语法

```c++
template<typename T>
//函数声明或定义
```

```c++
//函数模版
#include <iostream>
using namespace std;


template <typename T>   //申明一个模版，告诉编译器T不报错
void mswap(T & a, T & b){
    T temp = a;
    a = b;
    b = temp;
}

void test(){
    int a = 1;
    int b = 0;
    //两种使用模版方式
    //1、自动推导数据类型
    mswap(a, b);
    //2、显示指定类型
    mswap<int>(a, b); 

    cout << a << " " << b << endl;
}


int main(){
    test();
    return 0;
}
```

## 函数模版注意事项

注意：使用模版的时候必须指定数据类型

```C++
#include <iostream>
using namespace std;

//函数模版注意事项
//1、自动类型推导，必须推导出一致的数据类型T
//2、模版必须确定T地数据类型，才可以使用

template<class T> //typename可以替换成class
void mswap(T & a, T & b){
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void func(){
    cout << "func" << endl;
}
void test(){
    int a = 10;
    int b = 20;

    char c = 'c';
    
    // mswap(a, c); 错误 推导出不一定的数据类型

    // func(); 没有指定函数模版类型
    //只能显示指定T
    func<int>();
}

int main(){
    test();
    return 0;
}
```

## 普通函数与函数模版区别

总结：调用的时候直接通过显示指定类型调用

```c++

//普通函数与函数模版区别
//1、普通函数调用可以发生隐式类型转换
//2、函数模版 用自动类型推导，不可以发生隐式类型转换
//3、函数模版 用现实指定类型，可以发生隐式类型转换
#include <iostream>
using namespace std;

int myadd01(int a, int b){
    return a + b;
}

//函数模版
template<class T>
T myadd02(T a, T b){
    return a + b;
}
void test(){
    int a = 10;
    int b = 20;
    char c = 'c';
    cout << myadd01(a, c) << endl;  //把字符型隐式的转换为整型

    //自动推导
    cout << myadd02(a, b) << endl;

    // cout << myadd02(a, c) << endl;  没法推导成一致参数类型

    //显示指定类型,可以发生隐式类型转换
    cout << myadd02<int>(a, c) << endl;
}

int main(){

    test();
}
```

## 普通函数与函数模版的调用规则

调用规则如下：

​	1、如果函数模版和普通函数都可以实现，优先调用普通函数

​	2、可以通过空模板参数列表来强制调用函数模版

​	3、函数模版也可以发生重载

​	4、如果函数模版可以产生更好的匹配优先调用函数模版

总结：如果提供了函数模版，就不要提供普通函数了，否则容易出现二义性

```c++
#include <iostream>
using namespace std;

void mprint(int a, int b){
    cout << "普通函数" << endl;
}

template<class T>
void mprint(T a, T b){
    cout << "函数模版调用" << endl;
}


template<class T>
void mprint(T a, T b, T c){
    cout << "重载函数模版调用" << endl;
}

void test(){
    int a = 0;
    mprint(a, a); //普通函数和模版函数都可以时，优先调用普通函数
    mprint<>(a, a);//通过空模版参数列表强制调用模版函数
    mprint(a, a, a);//函数模版可以发生函数重载

    //如果函数模版产生更好的匹配，优先调用函数模版
    char c1 = 'a';
    char c2 = 'b';
    mprint(c1, c2);//调用函数模版，因为如果调用普通函数需要隐式类型转换，模版函数只需要推导一致的参数类型即可，模版函数更匹配

}
int main(){
    test();
    return 0;
}
```

## 模版函数的局限性

总结：

​	1、利用具体化的模版，可以解决自定义类型的通用化

​	2、学习模版并不是为了写模版，而是在STL能够运用系统提供的模版

```c++
//函数模版的局限性
//给特定类型提供具体化的模版
#include <iostream>
#include <string>
using namespace std;
class Person{
    public:
        string mname;
        int mage;
        Person(string name, int age){
            mname = name;
            mage = age;
        }
};
template<class T>
bool mCompare(T & a, T & b){
    if (a == b){
        return true;
    }
    else {
        return false;
    }
}

//具体化操作
//利用具体化Person地版本实现代码，具体化优先调用
template<> bool mCompare(Person & a, Person & b){
    if(a.mname == b.mname && a.mage == b.mage){
        return true;
    }
    else {
        return false;
    }
}

void test(){

    int a = 10; 
    int b = 20;

    bool ret = mCompare(a, b);
    if(ret){
        cout << "=" << endl;
    }else {
        cout << "!=" << endl;
    }
}

void test2(){
    Person p1("Tom", 10);
    Person p2("Tom", 10);

    bool ret = mCompare(p1, p2);
    if(ret){
        cout << "="<< endl;
    }
    else {
        cout << "!=" << endl;
    }
}
int main(){
    // test();
    test2();
    return 0;
}
```

## 类模版

总结：类模版和函数模版语法相似，在声明模版template后面加类，此类称为模版类

```c++
//类模版
#include <iostream>
#include <string>
using namespace std;
template<class NameType, class AgeType>
class Person{
    public:
        Person(NameType name, AgeType age){
            this->mName = name;
            this->mAge = age;
        }
        NameType mName;
        AgeType mAge;

        void showPerson(){
            cout << mName << " " << mAge << endl;
        }
};

void test(){
    //尖括号里是模版参数列表
    Person<string, int> p1("sunwukong", 999);
    p1.showPerson();
}
int main(){
    test();
    return 0;
}
```

## 类模版和函数模版的区别

主要区别：

​	1、类模版没有自动类型推导的使用方式，只能使用显示指定类型的方式

​	2、类模版在模版参数列表中可以有默认参数，函数模版不行

```c++
//类模版和函数模版的区别
#include <iostream>
#include <string>
using namespace std;

template<class NameType, class AgeType = int >  //这里设置了类模版的参数类型默认值
class Person{
    public:
        Person(NameType name, AgeType age){
            this->mName = name;
            this->mAge = age;
        }
        NameType mName;
        AgeType mAge;

        void showPerson(){
            cout << mName << " " << mAge << endl;
        }
};
//1、类模版没有自动类型推导使用方式
void test1(){
    // Person p("sunwukong", 999);  无法使用，因为类模版不能使用自动类型推导
    Person <string, int> p ("sunwukk", 99);

    p.showPerson();
}
//2、类模版在模版参数列表中可以有默认参数,函数模版不能使用默认参数
void test2(){
    Person<string> p("zhubajie", 10);
}
int main(){
    test1();
    return 0;
}
```

## 类模版中成员函数创建时机

注意：

​	普通类中的成员函数一开始就可以创建

​	类模版中的成员函数在调用时才创建

```c++
//类模版中成员函数的创建时机
#include <iostream>
using namespace std;

class Person1{
    public:
        void showPerson1(){
            cout << "Person1" << endl;
        }
};


class Person2{
    public:
        void showPerson2(){
            cout << "Person2" << endl;
        }
};

template<class T>
class Mclass{
    public:
        T obj;
        //类模版中的成员函数,不是一开始就创建出来的，因为不能确定obj的类型
        void func1(){
            //只有调用的时候，才会创建T类型的obj
            obj.showPerson1();
        }

        void func2(){
            obj.showPerson2();
        }
};

void test(){
    Mclass<Person1> m;
    m.func1();
    m.func2();
}
int main(){
    test();
    return 0;
}
```

## 类模版对象做函数参数

​	类模版实例化出对象，向函数传参有3种

1、指定类型，使用最多

2、参数模版化

3、整个类模版化

```c++
//类模版对象做函数参数
#include <iostream>
#include <string>

using namespace std;
template <class T1, class T2>
class Person{
    public:
        T1 mName;
        T2 mAge;
        Person(T1 name, T2 age){
            mName = name;
            mAge = age;
        }

        void showPerson(){
            cout << mName << " " << mAge << endl;
        }
};

//类模版对象做函数参数.最常用
//1、指定传入类型.类模版对象的类型作为函数形参，并声明为引用的方式
void printPerson1(Person<string, int> & p){
    p.showPerson();
}
void test1(){
    Person<string, int> p("sunwukong", 100);
    printPerson1(p);
}
//2、参数模版化
template<class T1, class T2>
void printPerson2(Person<T1, T2> & p){
    p.showPerson();
    //查看推导出类型的方法代码
    cout << typeid(T1).name() << endl;
    cout << typeid(T2).name() << endl;
}
void test2(){
    Person<string, int> p("zhubajie", 90);
    printPerson2(p);

}
//3、整个类模版化
template<class T>
void printPerson3(T & p){
    p.showPerson();
}
void test3(){
    Person<string, int> p("tangseng", 30);
    printPerson3(p);
}
int main(){
    // test1();

    // test2();
    test3();
    return 0;
}
```

## 类模版与继承

注意：当子类继承的父类是一个类模版时，子类在声明的时候，需要指定父类中的T的类型，如果不指定，编译器无法给子类分配内存。如果想灵活指定出父类中T地类型，子类也需要变为类模版

总结：如果父类是类模版，子类需要指定出父亲中T的数据类型

```c++
//类模版与继承
#include <iostream>
using namespace std;
template <class T>
class Base{
    public:
        T m;
};

// class Son : public Base  //错误，必须要知道父类中T的数据类型，子类才能继承
//声明T的类型
class Son : public Base<int>{

};

void test1(){
    Son s1;
}
//如果想要灵活指定T的类型,类型对应传递
template<class T1, class T2>
class Son2 : public Base<T2>{
    public:
        T1 obj;
        Son2(){
            cout << typeid(T1).name() << endl;
            cout << typeid(T2).name() << endl;
        }
};

void test2(){
    Son2<int, char> s2;
}
int main(){
    // test1();
    test2();
    return 0;
}
```

## 类模版成员函数的类外实现

```c++
#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>
class Personl{
    public:
        T1 mName;
        T2 mAge;
        //类内写函数声明，类外写实现
        Personl(T1 name, T2 age);

        void showPersonl();
        //     cout << mName << " " << mAge << endl;
        // }    
};
template<class T1, class T2>
Personl<T1, T2>::Personl(T1 name, T2 age){
    this->mName = name;
    this->mAge = age;
}
//成员函数的类外实现，要变成类模版的实现
template<class T1, class T2>
void Personl<T1, T2>::showPersonl(){
    cout << mName << " " << mAge << endl;
}

void test(){
    Personl<string, int> p("maojie", 18);
    p.showPersonl();
}
int main(){
    test();
    return 0;
}
```

## 类模版的份文件编写

问题：类模版中成员函数创建时机是在调用阶段，导致份文件编写是链接不到

解决：

​	1、直接包含.cpp文件

​	2、将声明和实现卸载同一个文件中，并更改后缀为.hpp，hpp为约定名称不是强制.这种比较好使

```c++
//.hpp文件
#include <iostream>
#include <string>
using namespace std;
//类模版的分文件编写
template <class T1, class T2>
class Person{
    public:
        T1 mName;
        T2 mAge;
        Person(T1 name, T2 age);

        void showPerson();
};
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age){
    this->mName = name;
    this->mAge = age;
}

template <class T1, class T2>
void Person<T1, T2>::showPerson(){
    cout << mName << " "  << mAge << endl;
}
```

```c++
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
```

## 类模版与友元

全局函数类内实现-直接在类内声明友元即可

全局函数类外实现-需要提前让编译器知道全局函数存在

总结：类内实现简单，编译器可以直接识别

```c++
//类模版与友元
//掌握类模版配合友元函数的类内和类外实现
#include <iostream>
#include <string>
using namespace std;
//提前让编译器知道类的存在
template<class T1, class T2>
class Person;

template<class T1, class T2>
void printPerson2(Person<T1, T2> p){
    cout << p.mName << " "  << p.mAge << endl;
};

template <class T1, class T2>
class Person{
    //全局函数，打印Person信息 类内实现
    friend void printPerson(Person<T1, T2> p){
        cout << p.mName << " "  << p.mAge << endl;
    }
    
    //加空模版参数列表
    //如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
    friend void printPerson2<>(Person<T1, T2> p);

    public: 
        Person(T1 name, T2 age){
            this->mName = name;
            this->mAge = age;
        }

        void showPerson(){
            cout << mName << " "  << mAge << endl;
        }
    private:
        T1 mName;
        T2 mAge;
};

//1、全局函数在类内实现
void test1(){
    Person<string, int> p("tom", 21);
    printPerson(p);
}

//2、全局函数类外实现


void test2(){
    Person<string, int> p("tom", 21);
    printPerson2(p);
}
int main(){
    test2();
    return 0;
}
```

# 十一、STL（standard template library）

提高代码的复用性	

​	标准模版库

​	STL从广义上划分为容器、算法、迭代器	

​	容器和算法之间通过迭代器进行连接

六大组件：容器、算法、迭代器、仿函数、适配器、空间配置器

1、容器：各种数据结构，如vector、list、deque、map、set等

2、算法：各种常用算法，sort、find、copy、foreach

3、迭代器：扮演了容器和算法之间的胶合剂

4、仿函数：行为类似函数，可作为算法的某种策略

5、适配器：一种用来修饰容器或者仿函数或者迭代器接口的东西

6、空间配置器：负责空间的配置与管理



## 容器分为序列式和关联式

​	序列式：强调值的排序，序列式容器中的每个元素均有固定的位置

​	关联式：二叉树结构，各元素之间没有严格的物理上的顺序关系



## 算法——algortihm，分为质变算法和非质变算法

​	质变算法：是指运算过程中会更改区间中的元素内容。如拷贝、替换、删除等

​	非质变算法：是指运算过程中不会更改区间内的元素内容，如查找和遍历

## 迭代器，类似于指针。算法通过迭代器访问容器中的元素。每个容器都有自己专属的迭代器。

​	常用容器迭代器为双向迭代器和随机访问迭代器

​	双向迭代器：支持读写操作，并能向前和向后操作。读写，支持++，--

​	随机访问迭代器：读写操作，可以跳跃式的访问任意数据，功能最强的迭代器。读写，支持++、--、[]、-n等



## Vector

基本概念：

一段连续的内存空间

功能：和数组非常相似，被称为单端数组

不同：数组时静态空间，vector的空间是动态的

动态扩展：并不是在原空间之后续接新空间，而是找更大的内存空间，然后将数据拷贝到新空间中，并释放原空间

可以理解为数组

```c++
//容器vector，存放内置数据类型
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void myprint(int val){
    cout << val << endl;
}

void test1(){
    //创建vector容器
    vector<int> v;

    //向容器中插入数据,尾插
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    //通过迭代器访问容器中的数据
    vector<int>::iterator itBegin = v.begin();  //起始迭代器    指向容器中的第一个元素
    vector<int>::iterator itEnd = v.end();  //结束迭代器    指向容器中的最后一个元素的下一个位置

    //第一种遍历方式
    while(itBegin != itEnd){
        cout << *itBegin << endl;
        itBegin++;
    }

    //第二种遍历方式
    for(vector<int>::iterator itB = v.begin(); itB != v.end(); itB++){
        cout << *itB << endl;
    }

    //第三种遍历方式，利用STL的遍历算法
    for_each(v.begin(), v.end(), myprint);

}
int main(){
    test1();

    return 0;

}
```

```c++
//存放自定义数据类型
//vector容器中存放自定义数据类型
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person{
    public:
        Person(string name, int age){
            this->mName = name;
            this->mAge = age;
        }
        string mName;
        int mAge;
};

void test1(){
    vector<Person> v;
    Person p1("aa", 10);
    Person p2("bb", 20);
    Person p3("cc", 30);

    //向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    for (vector<Person>::iterator itBegin = v.begin(); itBegin != v.end(); itBegin++){
        cout << itBegin->mName << " " << itBegin->mAge << endl;
    }
}

void test2(){
    vector<Person *> v;
    Person p1("aa", 10);
    Person p2("bb", 20);
    Person p3("cc", 30);

    //向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    for(vector<Person *>::iterator itBegin = v.begin(); itBegin != v.end(); itBegin++){
        cout << (*itBegin)->mName << " " <<(*itBegin)->mAge << endl;
        
    }

}

int main(){
    test2();
    return 0;
}
```

### 容器嵌套容器

```c++
//vector容器嵌套容器
//相当于二维数组
#include <iostream>
#include <vector>
using namespace std;


void test1(){
    vector< vector<int> > vpp;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    //向小容器插入数据
    for (int i = 0; i < 4; i++){
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }

    //向大容器插入小容器
    vpp.push_back(v1);
    vpp.push_back(v2);
    vpp.push_back(v3);
    vpp.push_back(v4);

    //通过大容器，把所有数据遍历一边
  	//注意要区分大容器的的迭代器和小容器迭代器的指向
    for(vector< vector<int> >::iterator it = vpp.begin(); it != vpp.end(); it++){
        for (vector<int>::iterator itm = it->begin(); itm != it->end(); itm++){
            cout << *itm << " ";
        }
        cout << endl;
    }
}

int main(){
    test1();
    return 0;
}
```

### vector构造

```c++
//vector构造函数
//创建vector容器
#include <iostream>
#include <vector>
using namespace std;
void test1(){
    //默认的无参构造函数
    vector<int> v1;

    //区间构造
    vector<int> v2(v1.begin(), v1.end());

    //n个elem构造
    vector<int> v3(10, 100);

    //拷贝构造
    vector<int> v4(v1);
}

int main(){

    return 0;
}
```



### vector赋值

三种赋值方式

1、operator=赋值

2、assign（1，2）范围赋值

3、assign（n，elem）n个elem赋值

```c++
//vector赋值操作
#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<int> & v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void test1(){
    vector<int> v1;
    for (int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printVector(v1);

    //operator=
    vector<int> v2 = v1;
    printVector(v2);

    //assign函数
    vector<int> v3;
    //前闭后开，end指向最后一个元素的下一个位置
    v3.assign(v1.begin(), v1.end());
    printVector(v3);
    //n个elem赋值
    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);

}
int main(){

    test1();
    return 0;
}
```

### vector容量和大小

```c++
//vector容量和大小
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> & v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void test1(){
    vector<int> v1;
    for (int i = 0; i < 10; i++){
        v1.push_back(i);
    }

    if(v1.empty()){
        cout << "为空" << endl;
    }
    else {
        cout << "不为空" << endl;
        //vector的容量 >= vector的大小
        cout << v1.capacity() << endl;
        cout << v1.size() << endl;
    }

    //重新指定大小
    v1.resize(20, 0);//重新指定的大小比原先大，默认用0填充剩余位置
    printVector(v1);

    v1.resize(4);//重新指定的大小比原先小，剩余的位置会被删除释放
    printVector(v1);
}
int main(){
    test1();
    return 0;
}
```

### vector插入和删除

```c++
//vector插入和删除
#include <iostream>
#include <vector>
using namespace std;
/*
push_back(elem)尾插，在vector尾部插入elem
pop_back() 删除最后一个元素
insert(const iterator pos, ele)  迭代器指向位置插入elem
insert(const iterator pos, int count, ele) 迭代器指向位置插入count个elem元素
erase(const iterator pos)  删除指向位置的元素
erase(const iterator brgin, const iterator end) 删除begin到end位置的元素
clear() 删除容器中所有元素
*/

void printVector(vector<int> & v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void test1(){
    vector<int> v1;
    //尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector(v1);

    //尾删
    v1.pop_back();
    v1.pop_back();
    printVector(v1);

    //插入
    //第一个参数是位置的迭代器，第二个参数是数据
    v1.insert(v1.begin(), 100);
    printVector(v1);
    
    v1.insert(v1.begin(), 10, 100);
    printVector(v1);

    v1.insert(v1.begin(), 10000);
    printVector(v1);
    //删除参数为位置迭代器
    v1.erase(v1.begin());
    printVector(v1);

    //区间删除，两个参数都是位置迭代器
    // v1.erase(v1.begin(), v1.end());
    v1.clear();
    printVector(v1);

    

}

int main(){

    test1();
    return 0;
}
```

### vector中的数据存取

对vector中的数据存取操作

​    at函数、[]存取，front函数和back函数

```c++
//vector数据存取
//at()
//operator[]
//front()
//back()
#include <iostream>
#include <vector>
using namespace std;
void test1(){
    vector<int> v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }

    for (int i = 0; i < v1.size(); i++){
        //operator[]形式
        cout << v1[i] << " ";
        //at函数形式
        cout << v1.at(i) << " ";
    }
    cout << endl;

    cout << "第一个元素为：" << v1.front() << endl;
    cout << "最后一个元素为：" << v1.back() << endl;
}

int main(){
    test1();
    return 0;
}
```

### vector互换容器

```c++
//vector互换容器，实现两个容器内的元素进行互换
//swap函数
#include <vector>
#include <iostream>
using namespace std;
void printVector(vector<int> & v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
//1、基本使用
void test1(){
    vector<int> v1;
    for (int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    for (int i = 10; i > 0; i--){
        v2.push_back(i);
    }
    printVector(v2);

    v1.swap(v2);
    //v1和v2互换容器内的元素
    printVector(v1);
    printVector(v2);
    
}
//2、实际用途
//使用swap收缩内存空间
void test2(){
    vector<int> v;
    for (int i = 0; i < 10000000; i++){
        v.push_back(i);
    }
    cout << v.capacity() << endl;
    cout << v.size() << endl;
    //重新指定大小，容量不会发生变化，大小会改变
    v.resize(3);
    cout << v.capacity() << endl;
    cout << v.size() << endl;

    vector<int>(v).swap(v);
  //这里容器交互。首先vector<int>(v)会创建一个匿名对象，调用拷贝构造函数，拷贝v的size。然后调用swap函数，容器交换，容量缩小。编译器识别到匿名对象后，多余的内存空间会被回收。
    cout << v.capacity() << endl;
    cout << v.size() << endl;

}
int main(){
    // test1();
    test2();
    return 0;
}
```

###    vector预留空间

```c++
//vector预留空间
//减少vector在动态扩展
//reserve(int len) 容器预留len个元素长度，预留位置不初始化，元素不可访问。只是分配内存，并没有给数据
#include <iostream>
#include <vector>
using namespace std;
void test1(){
    vector<int> v;
    //已知数据量，可以预留空间，减少动态扩展的次数
    v.reserve(1000000);
    int num = 0;
    int* p = NULL;
    for (int i = 0; i < 1000000; i++){
        v.push_back(i);

        if(p != &v[0]){
            p = &v[0];
            //动态扩展的次数
            num++;
        }
    }

    cout << num << endl;
}

int main(){
    test1();
    return 0;
}
```



## string容器

### 基本概念

​	本质：string是C++风格的字符串，而string本质上是一个类

string和char*区别

​	char*是一个指针

​	string是一个类，类内部封装了char*，管理这个字符串，是一个char*的容器

### string的构造函数

```c++
//string的构造函数
#include <iostream>
#include <string>
using namespace std;

void test1(){
    string s1;
    const char * str = "hello world";
    string s2(str);
    cout << s2 << endl;

    string s3(s2);
    cout << s3 << endl;

    string s4(6, 'a');
    cout << s4 << endl;

}
int main(){

    test1();

    return 0;
}
```

### string的赋值操作

```c++
//string的赋值操作
//1、operator =
//2、assgin（）函数
#include <iostream>
#include <string>
using namespace std;

void test1(){
    string str1;
    str1 = "hello world";
    cout << str1 << endl;

    string str2 = str1;
    cout << str2 << endl;

    string str3;
    str3 = 'a';
    cout << str3 << endl;

    //assign方式赋值
    string str4;
    str4.assign("hello C++");
    cout << str4 << endl;

    //前n个字符，赋值过来
    string str5;
    str5.assign("hello c++", 5);
    cout << str5 << endl;

    string str6;
    str6.assign(7, 'a');
    cout << str6 << endl;
}

int main(){

    test1();

    return 0;
}
```

### string的字符串拼接

```c++
//string字符串拼接
//1、 +=
//2、 append
#include <iostream>
#include <string>
using namespace std;

void test1(){

    //1、 +=
    string str1 = "wo ";
    str1 += "ai wan you xi";
    cout << str1 << endl;

    str1 += 'C';
    cout << str1 << endl;

    string str2 = "nima";
    str1 += str2;
    cout << str1 << endl;

    //2、append函数
    string str3 = "love ";
    str3.append("me");
    cout << str3 << endl;
    //拼接前n个字符
    str3.append(" game abcde", 4);
    cout << str3 << endl;

    //拼接str2
    str3.append(str2);
    cout << str3 << endl;

    //从5位置截3个字符的字串拼接
    str3.append("spoakfjoaspdofj", 5, 3);
    cout << str3 << endl;
}
int main(){
    test1();
    return 0;
}
```

### string的查找和替换

总结：

​	find查找从左往右，rfind从右往左

​	find找到子串返回查找的第一个字符的位置，找不到返回-1

​	replace在替换时，指定从哪个位置起，多少个字符，替换成什么样的字符串

```c++
//string 查找和替换
//查找：查找指定字符串是否存在
//替换：在指定的位置替换字符
#include <iostream>
#include <string>

using namespace std;

void test1(){
    string str1 = "abcdefgde";
    //返回字串的开始位置，查不到返回-1
    int pos = str1.find("de");
    if(pos == -1){
        cout << "没有查到字串" << endl;
    }
    else {
        cout << pos << endl;
    }
    //rfind 和 find 的区别
    //rfind从右往左查找
    //find从左往右查找
    pos = str1.rfind("de");
    cout << pos << endl;
    
}

void test2(){
    string str1 = "abcdefg";
    //第一个参数：起始位置， 第二个参数：替换的字符数， 第三个参数：替换的字符串
    //从1位置起3个字符替换成1111
    str1.replace(1, 3, "1111");
    cout << str1 << endl;
}

int main(){
    // test1()
    test2();
    return 0;
}
```

### string字符串比较

```c++
//string字符串比较
//比较方式：按字符的ASCII码对比。= 返回 0， > 返回 1， < 返回 -1
#include <iostream>
using namespace std;


void test1(){
    string str1 = "aello";
    string str2 = "hello";
    int flag = 0;
    if((flag = str1.compare(str2)) == 0){
        cout << "equal" << endl;
    }
    else {
        cout << flag << endl;
    }
}
int main(){
    test1();
    return 0;
}
```

### string字符存取

```c++
//string字符存取
//[]方式取字符
//at函数访问字符
#include <iostream>
using namespace std;

void test1(){
    string str = "hello";
    cout << sizeof(str) << endl;
    for (int i = 0; i < str.size(); i++){
        cout << str[i] << endl;
    }

    for (int i = 0; i < str.size(); i++){
        cout << str.at(i) << endl;
    }

    //修改单个字符
    str[0] = 'x';
    cout << str << endl;
    str.at(1) = 'z';
    cout << str << endl; 
}
int main(){
    test1();
    return 0;
}
```

### string字符串插入和删除

​	总结：从0位置开始计算。起始位置和字符数

```c++
//string 插入和删除
#include <iostream>
#include <string>

using namespace std;
void test1(){
    string str = "hello";
    //插入,在1处插入字符串
    str.insert(1, "javc");
    cout << str << endl;

    //erase删除，从1位置起删除4个字符
    str.erase(1, 4);
    cout << str << endl;
    
}

int main(){
    test1();
    return 0;
}
```

### string子串

```c++
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
```

## deque容器

### 基本概念：

​    双端数组，可以对头端进行插入删除操作

与vector的区别

1、vector对于头部的插入删除效率低，数据量越大，效率越低

2、deque相对而言，对头部的插入删除速度比vector速度快

3、vector访问元素时的速度会比deque快，这和两者内部实现有关



deque内部工作原理

deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据，中控器维护每个缓冲区的地址，使使用deque时像一片连续的内存空间。

deque容器的迭代器也是支持随机访问的

```c++
//deque容器构造
#include <iostream>
#include <deque>
using namespace std;

// 防止内容修改，参数设置const
void printDeque(const deque<int> & d){
    //迭代器设置为const的
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it ++){
        cout << *it << " ";
    }
    cout << endl;
}
void test1(){
    //默认构造
    deque<int> d1;
    for (int i = 0; i < 10; i++){
        d1.push_back(i);
    }
    printDeque(d1);
    
    //构造函数将[beg，end]  区间元素拷贝给本身
    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);
    
    //构造函数将n个elem拷贝给本身
    deque<int> d3(10, 100);
    printDeque(d3);

    //拷贝构造函数
    deque<int> d4(d1);
    printDeque(d4);

}
int main(){
    test1();
    return 0;
}
```

### deque赋值操作

```c++
#include <iostream>
#include <deque>
using namespace std;
//deque容器赋值操作
void printDeque(const deque<int> & d){
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test1(){
    deque<int> d1;
    for (int i = 0; i < 10; i++){
        d1.push_back(i);
    }
    
    //operator=赋值
    deque<int> d2 = d1;
    printDeque(d2);

    //assign 赋值
    deque<int> d3;
    d3.assign(d1.begin(), d1.end());
    printDeque(d3);

    deque<int> d4;
    d4.assign(10, 100);
    printDeque(d4);

}
int main(){
    test1();
    return 0;
}
```

### deque大小操作

```c++
//deque大小操作
#include <iostream>
#include <deque>
using namespace std;
//和vector类似，没有容量限制
//deque没有容量概念
void printDeque(const deque<int> & d){
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test1(){
    deque<int> d1;
    for (int i = 0; i < 10; i++){
        d1.push_back(i);
    }
    printDeque(d1);

    if(d1.empty()){
        cout << "空" << endl;
    }
    else {
        cout << "不为空" << endl;
        cout << d1.size() << endl;
    }

    d1.resize(15);
    printDeque(d1);

    d1.resize(20,7);
    printDeque(d1);
}
int main(){
    test1();
    return 0;
}
```

### deque插入和删除

```c++
//deque插入和删除
#include <iostream>
#include <deque>
using namespace std;
void printDeque(const deque<int> & d){
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void test1(){
    deque<int> d1;

    //尾插
    d1.push_back(10);
    d1.push_back(20);

    //头插
    d1.push_front(1);
    d1.push_front(100);

    printDeque(d1);

    //尾删
    d1.pop_back();
    printDeque(d1);

    //头删
    d1.pop_front();
    printDeque(d1);
}

void test2(){
    deque<int> d1;

    //尾插
    d1.push_back(10);
    d1.push_back(20);

    //头插
    d1.push_front(1);
    d1.push_front(100);

    //insert的三个重载版本
    d1.insert(d1.begin(), 1000);
    printDeque(d1);

    d1.insert(d1.begin(), 2, 1);
    printDeque(d1);

    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d1.insert(d1.begin(), d2.begin(), d2.end());
    printDeque(d1);

    deque<int>::iterator it = d1.begin();
    it += 3;
    //删除第4个元素
    d1.erase(it);
    printDeque(d1);
    
    //区间删除
    d1.erase(d1.begin(), d1.end());
    printDeque(d1);
    //全部删除操作
    d2.clear();
}
int main(){
    // test1();
    test2();
    return 0;
}
```

### deque数据存取

```c++
//deque数据存取
#include <iostream>
#include <deque>
using namespace std;

void printDeque(const deque<int> & d){
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test1(){
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(1);
    //opertaor[] 中括号存取
    cout << d1[0] << endl;
    d1[0] = 5;
    cout << d1.at(0) << endl;
    //at函数访问
    cout << d1.at(2) << endl;
    cout << d1.front() << endl;
    cout << d1.back() << endl;

    d1.front() = 209;
    cout << d1.front() << endl;

}

int main(){
    test1();
    return 0;
}
```

### deque排序

使用sort算法。对于支持随机访问的迭代器，都可以使用sort函数排序

```c++
//deque排序
#include <iostream>
#include <deque>
//算法包含的头文件
#include <algorithm>
using namespace std;

void printDeque(const deque<int> & d){
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test1(){
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(1);
    d1.push_back(2);
    printDeque(d1);
    //填入区间迭代器
    deque<int>::iterator it = d1.end();
    it--;
    sort(d1.begin(), it);
    printDeque(d1);
    
}

int main(){
    test1();
    return 0;
}
```

## list链表

   优点：对任意的位置进行快速添加或者删除元素

   缺点：对于容器的遍历速度，没有数组快。

​             占用的空间比数组大。

​    STL中的链表是一个双向循环链表

​    由于链表的存储方式并不是连续的空间，因此list中的迭代器只支持前移和后移，属于双向迭代器。

​    list的重要性质：插入和删除操作都不会影响原来的迭代器，但是vector会影响原来的迭代器。因为vector会动态扩容，将原本容器的元素全部复制到更大的连续空间里，导致地址变换，原来的迭代器指向错误的地址。

### list的构造函数

```c++
//list构造
#include <iostream>
#include <list>
using namespace std;
void printlist(const list<int> & l){
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test1(){
    //默认构造
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printlist(l1);

    //区间方式构造
    list<int> l2 (l1.begin(), l1.end());
    printlist(l2);

    //拷贝构造
    list<int> l3(l1);
    printlist(l3);

    //n个elem,一个参数为个数，第二个参数为elem
    list<int> l4(10, 100);
    printlist(l4);
}
int main(){
    test1();
    return 0;
}
```

### list的大小操作

​    size函数——返回容器中的元素个数

​    empty函数——判断元素是否为空

​    resize函数——重新规定容器的元素数。有两个重载。可以指定剩余位置用elem代替。

```c++
//list大小操作
#include <iostream>
#include <list>
using namespace std;

void test1(){
    list<int> l1;
    cout << l1.size() << endl;

    l1.push_back(10);
    l1.push_back(10);
    l1.push_back(10);
    l1.push_back(10);

    if(l1.empty()){
        cout << "空" << endl;
    }
    else {
        cout << "不为空" << endl;
        l1.resize(10, 9);
    }

    for(list<int>::iterator it = l1.begin(); it != l1.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
int main(){
    test1();
    return 0;
}
```

### list容器插入和删除操作

```c++
//list容器插入和删除
#include <iostream>
#include <list>
using namespace std;

void printlist(const list<int> & l){
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test1(){
    list<int> l1;
    //尾插push_back
    l1.push_back(10);
    l1.push_back(20);
    printlist(l1);

    //尾删pop_back
    l1.pop_back();
    printlist(l1);

    //头插push_front
    l1.push_front(30);
    l1.push_front(110);
    printlist(l1);

    //头删pop_front
    l1.pop_front();
    printlist(l1);

    list<int>::iterator it = l1.begin();
    //迭代器向后偏移2个位置
    it++;
    it++;
    //insert函数
    //指定位置插入
    l1.insert(it, 900); //这个insert重载会返回插入数据的位置迭代器
    printlist(l1);
    
    //指定位置连续插入n个elem
    l1.insert(it, 9, 10);
    printlist(l1);
    //在指定位置，插入区间的元素
    // l1.insert(it, l1.begin(), l1.end());
    // printlist(l1);
    //删除区间元素
    // l1.erase(l1.begin(), l1.end());
    // printlist(l1);
    //删除容器中所哟elem值
    l1.remove(10);
    printlist(l1);

}
int main(){
    test1();
    return 0;
}
```

### list容器的数据存取

list容器只能在链表头和链表尾进行存取

```c++
//list数据存取操作
#include <iostream>
#include <list>
using namespace std;

//list容器只能在链表头和链表尾进行存取

void test1(){
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    cout << l1.front() << endl;
    cout << l1.back() << endl;
    //返回的是数据的引用，所以可以对数据进行修改
    l1.front() = 1000;
    cout << l1.front() << endl;
}

int main(){

    test1();
    return 0;
}
```

### list容器的排序和反转

sort的重点是有两个函数重载，默认情况下为升序排列。通过传入自己构建的比较函数，可以实现降序排列。

```c++
//list容器的反转和排序
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void printlist(const list<int> & l){
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

bool Comp(int v1, int v2){
    //降序排列， 让第一个数>第二个数

    return v1 > v2;
}

void test1(){
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    
    //成员函数反转
    l1.reverse();
    printlist(l1);

    //不支持随机访问的迭代器是不能使用标准排序算法的
    //list的迭代器不支持随机访问
    //不支持随机访问的容器，内部会提供一些对应的算法
    // sort(l1.begin(), l1.end());
    
    l1.sort(); //存在默认的排序规则为升序，从小到大
    printlist(l1);
    //函数重载，构建比较函数
    l1.sort(Comp);
    printlist(l1);
    

}

int main(){
    test1();
    return 0;
}
```

## set容器和multiset容器

### 基本概念

​    所有元素都会在插入的时候自动被排序

本质：set/multiset属于关联式容器，底层结构使用**二叉树**实现

区别：

——set不允许容器中包含重复的元素

——multiset允许容器中有重复的元素

### set构造和赋值操作

```c++
//set容器构造函数和赋值操作
#include <iostream>
#include <set>
using namespace std;

void printset(const set<int> & s){
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void test1(){
    //默认构造
    set<int> s1;
    //通过insert函数插入元素
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(6);
    s1.insert(0);

    //遍历容器
    printset(s1);
    //operator=赋值
    set<int> s2 = s1;
    printset(s2);

    //拷贝构造
    set<int> s3(s1);
    printset(s1);
}
int main(){
    test1();
    return 0;
}
```

### set大小和交换

```c++
#include <set>
#include <iostream>
using namespace std;

void printset(const set<int> & s){
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test1(){
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(0);
    //判空函数
    if(s.empty()){
        cout << "空" << endl;
    }
    else {
        cout << "不为空" << endl;
        //size函数
        cout << "size = " << s.size() << endl;
    }

    set<int> s2;
    s2.insert(1);
    s2.insert(3);
    s2.insert(9);

    printset(s);
    printset(s2);
    //交换
    s.swap(s2);
    printset(s);
    printset(s2);
}
int main(){
    test1();
    return 0;
}
```

### set插入和删除

——插入insert

——删除erase，有3个重载版本

```c++
//set插入和删除
#include <iostream>
#include <set>
using namespace std;

void printset(const set<int> & s){
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test1(){
    set<int> s1;
    s1.insert(1);
    s1.insert(-1);
    s1.insert(2);
    s1.insert(9);
    printset(s1);
    //清空函数 clear()
    // s1.clear();
    // printset(s1);
    //erase删除指定迭代器的元素
    set<int>::iterator it = s1.erase(s1.begin());
    cout << *it << endl;    
    //erase删除指定元素
    s1.erase(9);
    printset(s1);
    //删除指定区间
    s1.erase(s1.begin(), s1.end());
    printset(s1);
}
int main(){
    test1();
    return 0;
}
```

### set容器的查找和统计

——count函数统计元素的个数

——find函数查找元素是否存在，存在则返回元素的迭代器。否则，返回容器的end迭代器即最后一个元素的下一个位置

```c++
//set容器的查找和统计
#include <iostream>
#include <set>
#include <string>
using namespace std;

void test1(){
    multiset<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(13);
    s1.insert(14);
    s1.insert(1);
    
    //统计元素个数
    cout << s1.count(1) << endl;
    //find函数返回查找元素的迭代器
    set<int>::iterator it = s1.find(200);
    cout << *it << endl;
    bool rs = (it == s1.end());
    cout << rs << endl;
}

int main(){
    test1();
    return 0;
}
```

### set和multiset的区别

——set不可以插入重复的数据

——multiset可以插入重复的数据

```c++
//set和multiset的区别
#include <iostream>
#include <set>
using namespace std;

void test1(){
    set<int> s1;
    s1.insert(10);
    //set无法插入重复数据
    //set的insert函数返回的是pair<iterator, bool>类型的数据
    pair<set<int>::iterator, bool> ret = s1.insert(10);

    if(ret.second){
        cout << "插入成功" << endl;
    }
    else {
        cout << "插入失败" << endl;
    }

    multiset<int> mset;
    mset.insert(10);
    //multiset的插入函数返回的是迭代器
    multiset<int>::iterator it = mset.insert(10);

    for (multiset<int>::iterator it = mset.begin(); it != mset.end(); it++){
        cout << *it << endl;
    }
}
int main(){
    test1();
    return 0;
}
```

### pair对组创建

——对于成对出现的数据，利用对组可以返回两个数据

创建方式

——pair<type, type> p (value1, value2);

——pair<type, type> p = make_pair(value1, value2)

```c++
//pair对组创建
#include <iostream>
#include <string>
using namespace std;

void test1(){
    //创建方式一
    pair<string, int> p1 ("毛捷", 10);
    cout << p1.first << " " << p1.second << endl;

    //创建方式二
    pair<string, int> p2 = make_pair("niko", 20);
    cout << p2.first << " " << p2.second << endl;
}
int main(){
    test1();
    return 0;
}
```

### set容器排序

利用仿函数，改变排序规则

1、set存放内置数据类型

```c++
//set容器排序
#include <iostream>
#include <set>
using namespace std;

class MyCompare{
    public:
    //仿函数。重载运算符()。第一个是运算符，第二个是函数的参数列表
        bool operator() (int v1, int v2){
            return v1 > v2;
        }
};

void printset(const set<int> & s){
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


void test1(){
    //在构造容器之前，就应该设置比较的仿函数
    set<int, MyCompare> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    
    for (set<int, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
int main(){
    test1();
    return 0;
}
```

2、set存放自定义数据类型，set排序

set存放自定义数据类型的时候，要制定排序方式

```c++
//set存放自定义数据类型，完成排序操作
#include <iostream>
#include <set>
#include <string>
using namespace std;
class Person{
    public:
        string mName;
        int mAge;
        Person(string name, int age){
            mName = name;
            mAge = age;
        }

};

class MyCompare{
    public:
    //降序排列
    bool operator()(const Person & p1, const Person & p2){
        return p1.mAge > p2.mAge;
    }
};

void test1(){
    //自定义数据类型，都会指定排序规则
    set<Person, MyCompare> s1;
    s1.insert(Person("liubei", 24));
    s1.insert(Person("gunayu", 234));
    s1.insert(Person("li", 34));
    s1.insert(Person("lii", 21));

    for(set<Person, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++){
        cout << it->mName << " " << it->mAge << endl;
    }
}
int main(){
    test1();
    return 0;
}
```

## map和multimap容器

### 基本概念

1、map中所有的元素都是pair

2、pair中第一个元素为key，第二个元素为value

3、所有元素都会根据元素的键值自动排序

### 本质

map/multimap属于**关联式容器**，底层结构是二叉树实现的

区别：map不允许容器插入重复key；multimap允许容器插入重复key

### map构造和赋值

```
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
```

### map大小和交换

——size   返回容器中元素的数目

——empty  判断容器是否为空

——swap  交换两个容器的内容

```c++
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
```

### map插入和删除

```c++
//map插入和删除
#include <iostream>
#include <map>
#include <string>
using namespace std;

void test1(){
    map<int, string> m1;
    //插入函数,返回pair<iterator, bool>数据
    m1.insert(pair<int, string>(1, "jack"));
    m1.insert(pair<int, string>(2, "dack"));
    //清空函数
    // m1.clear();

    //erase删除指定迭代器的元素，并返回下一个元素的迭代器
    m1.erase(m1.begin());

    //erase删除区间[begin, end)的所有元素，返回下一个元素的迭代器
    m1.erase(m1.begin(), m1.end());

    m1.insert(pair<int, string>(1, "jack"));
    m1.insert(pair<int, string>(2, "dack"));
    //删除容器中键值为key的元素
    m1.erase(1);

    for (map<int, string>::iterator it = m1.begin(); it != m1.end(); it++){
        cout << it->first << " " << it->second << " ";
    }
    

}
int main(){

    test1();
    return 0;
}
```

### map查找和统计

——find(key)    查找key是否存在。若存在，返回该键的元素的迭代器；若不存在，返回end

——count(key)   统计key的元素个数（在multimap中比较实用，map不允许插入重复的key值）

```c++
#include <iostream>
#include <map>
#include <string>

using namespace std;
void test1(){
    map<int, string> m1;

    m1.insert(pair<int, string>(1, "jack"));
    m1.insert(pair<int, string>(2, "dack"));
    m1.insert(pair<int, string>(3, "cack"));

    //查找函数find
    
    map<int, string>::iterator it = m1.find(1);
    cout << it->first << " " << it->second << endl;
    it = m1.find(100);
    if(it == m1.end()){
        cout << "没找到" << endl;
    }
    else {
        cout << "找到了" << endl;
    }
    
    //统计key的个数
    cout << m1.count(1) << endl;
    
}
int main(){
    test1();
    return 0;
}
```

### map容器排序

利用仿函数，改变容器的排序规则。容器默认是自小到大升序排序

## 函数对象

### 概念

​	重载函数调用操作赋的类，其对象称为函数对象

​	函数对象使用重载的()，行为类似函数调用，也叫仿函数

本质：函数对象（仿函数）是一个类，不是一个函数

### 使用

特点：

​	函数对象在使用时，可以想普通函数那样调用，可以有参数，可以有返回值

​	函数对象超出普通函数的概念，函数对象可以有自己的状态

​	函数对象可以作为参数传递

总结：仿函数的写法十分灵活，没有一个固定的写法

```c++
#include <iostream>
#include <string>
using namespace std;

class MyAdd{
    public:
        int operator()(int v1, int v2){
            return v1 + v2;
        }
};
class MyPrint{
    public:
        MyPrint(){
            this->count = 0;
        }
        void operator()(string test){
            cout << test << endl;
            count++;
        }
        int count;//内部自己状态
};

void test1(){
    // 函数对象在使用时，可以想普通函数那样调用，可以有参数，可以有返回值
    MyAdd myAdd;
    int res = myAdd(10, 10);
    cout << res << endl;
}

void test2(){
    //函数对象超出普通函数的概念，函数对象可以有自己的状态
    MyPrint myPrint;
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    cout << myPrint.count << endl;
}

void doPrint(MyPrint & mp, string test){
    mp(test);
}

void test3(){
    MyPrint myPrint;
    //函数对象可以作为参数传递
    doPrint(myPrint, "hello c++");
}
int main(){
    // test1();
    // test2();
    test3();
    return 0;
}
```

## 谓词

### 概念

​	1、返回bool类型的仿函数称为谓词

​	2、如果operator()接受一个参数，那么叫做一元谓词

​	3、如果operator()接受两个参数，那么叫做二元谓词

### 一元谓词

```c++
//一元谓词
#include <iostream>
#include <vector>
using namespace std;

//仿函数，返回值是bool数据类型
class Greaterfive{
    public:
        //返回值为bool，参数列表中只有一个参数。 称为一元谓词。
        bool operator()(int val){
            return val > 5;
        }
};

void test1(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    //查找容器中，有没有大于5的数字
    //Greaterfive()匿名函数对象
    //find_if()参数为两迭代器和一个自定义的仿函数
    vector<int>::iterator it = find_if(v.begin(), v.end(),Greaterfive());
    if(it == v.end()){
        cout << "未找到" << endl;
    }
    else{
        cout << "找到了" << *it << endl;
    }
}


int main(){
    test1();
    return 0;
}
```

​	总结：参数只有一个的谓词，称为一元谓词

### 二元谓词

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MyCompare{
    public:
        //两个参数，二元。 返回bool， 谓词
        bool operator()(int v1, int v2){
            return v1 > v2;
        }
};

//二元谓词
void test1(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(0);
    v.push_back(50);
    //使用函数对象，改变算法策略，变排序为降序排列
    sort(v.begin(), v.end(), MyCompare());

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    test1();
    return 0;
}
```

## 内联函数

### 概念：

​	STL内建的一些函数对象

### 算术仿函数

​	实现四则运算，其中negate是一元运算，其他都是二元运算

​	仿函数原型

![image-20230510095912634](/Users/an/Library/Application Support/typora-user-images/image-20230510095912634.png)

```c++
//内联函数
//算术仿函数
#include <iostream>
//引入头文件functional
#include <functional>

//negate一元仿函数，取反


using namespace std;
void test1(){
    negate<int> n;
    cout << n(50) << endl;
}

//plus二元仿函数，加法
void test2(){
    plus<int> p;
    cout << p(10, 20) << endl;

//modulus取模
    modulus<int> m;
    cout << m(10, 3) << endl;

}

int main(){
    test1();
    test2();
    return 0;
}
```

### 关系仿函数

​	实现关系对比

![image-20230510100701228](/Users/an/Library/Application Support/typora-user-images/image-20230510100701228.png)

```c++
//关系仿函数
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class MyCompare{
    public:
        bool operator()(int v1, int v2){
            return v1 > v2;
        }
};

//大于
void test1(){
    vector<int> v;
    v.push_back(10);
    v.push_back(-10);
    v.push_back(10);
    v.push_back(0);
    v.push_back(50);
    //自己写的仿函数对象
    // sort(v.begin(), v.end(), MyCompare());
  	//指定类型
    sort(v.begin(), v.end(), greater<int>());
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    
}
int main(){
    test1();
    return 0;
}
```

### 逻辑仿函数

![image-20230510102814811](/Users/an/Library/Application Support/typora-user-images/image-20230510102814811.png)

```c++
//逻辑仿函数
//实现逻辑运算, 与、或、非
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
//逻辑非
void test1(){
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(false);
    v.push_back(true);

    for(vector<bool>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    //利用逻辑非， 将容器v搬运到 容器v2中，并执行取反操作
    vector<bool> v2;
    v2.resize(v.size());

    //transform 函数。使用的时候，需要提前开辟空间
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    for(vector<bool>::iterator it = v2.begin(); it != v2.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    test1();
    return 0;
}
```

## STL常用算法

### 概述：

​	算法主要是由头文件<algorithm><functional><numeric>组成

​	<algorithm>是所有STL头文件中最大的一个，设计比较、交换、查找、遍历操作、复制、修改

​	<numeric>体积很小，只包括几个序列上面进行简单数学运算的函数模版

​	<functional>定义了一些模版类，用以申明函数对象

### 常用的遍历算法

​	for_each	//遍历容器

​	transform	//搬运容器到另一个容器中

for_each，在实际开发中是最常用的遍历算法，熟练掌握

```c++
//常用遍历算法for_each
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print01(int val){
    cout << val << " ";
}

class MyFunc{
    public:
        void operator()(int val){
            cout << val << " ";
        }
};
void test1(){
    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }

    //普通函数版本
    for_each(v.begin(), v.end(), print01);
    cout << endl;

    //仿函数版本
    for_each(v.begin(), v.end(), MyFunc());
    cout << endl;

}

int main(){
    test1();
    return 0;
}
```

transform算法

```c++
//transform算法
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class transf{
    public:
        int operator()(int val){
            return val;
        }
};

void print1(int val){
    cout << val << " ";
}
void test1(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    vector<int> target;
    target.resize(v.size());
    transform(v.begin(), v.end(), target.begin(), transf());

    for_each(target.begin(), target.end(), print1);
    cout << endl;
}

int main(){
    test1();
    return 0;
}
```

### 常用的查找算法

find 查找元素

```c++
//find算法 查找元素
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//1、查找内置数据类型
void test1(){
    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }

    //无论是否找到，都会返回迭代器
    vector<int>::iterator it  = find(v.begin(), v.end(), 50);
    if(it == v.end()){
        cout << "没找到" << endl;
    }
    else {
        cout << *it << endl;
    }

}

class Person{
    public:
        Person(string name, int age){
            this->mName = name;
            this->mAge = age;
        }
        string mName;
        int mAge;
        
        //重载==，用引用必须使用const修饰，繁殖修改底层代码。不用引用，不加const。因为是拷贝出来的，不会修改
        bool operator== (const Person & p2){
            return this->mName == p2.mName && this->mAge == p2.mAge;
        }
};

//2、查找自定义数据类型,查找的时候，需要重载==
void test2(){
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator it = find(v.begin(), v.end(), Person("aaa", 10000));
    if(it == v.end()){   
        cout << "没找到" << endl;
    }
    else {
        cout << it->mName << " " << it->mAge << endl;
    }
}
int main(){
    test1();
    test2();
    return 0;
}
```

find_if 条件查找元素

```c++
//查找算法 find_if
//按值查找元素，找到返回指定位置的迭代器，找不到返回尾部迭代器
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Greater{
    public:
        bool operator()(int val){
            return val > 5;
        }
};

class Person{
    public:
        Person(string name, int age){
            this->mName = name;
            this->mAge = age;
        }
        string mName;
        int mAge;
};

class MyCompare{
    public:
        bool operator()(Person & p){
            return p.mAge > 20;
        }
};

//1、内置数据类型
void test1(){
    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }

    vector<int>::iterator it = find_if(v.begin(), v.end(), Greater());
    if(it == v.end()){
        cout << "没找到" << endl;
    }
    else {
        cout << *it << endl;
    }
}
//2、自定义数据类型
void test2(){
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator it = find_if(v.begin(), v.end(), MyCompare());
    if(it == v.end()){
        cout << "没找到" << endl;
    }
    else {
        cout << it->mName << " " << it->mAge << endl;
    }
}

int main(){
    test1();
    test2();
    return 0;
}
```

adjacent_find 查找相邻重复元素

​	总结：题目中出现需要查找相邻重复元素时，直接使用STL中adjacent_find即可

```c++
//常用查找算法adjacent_find
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test1(){
    vector<int> v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);

    vector<int>::iterator it = adjacent_find(v.begin(), v.end());

    if(v.end() == it){
        cout << "未找到" << endl;
    }
    else {
        cout << *it << endl;
    }

}
int main(){
    test1();
    return 0;
}
```

binary_search

```c++
//查找指定元素，二分查找
//查到，返回true。没查到,返回false
//在无序序列中不可以使用
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test1(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    //如果是无序序列，查找的结果未知
    bool ret = binary_search(v.begin(), v.end(), 9);
    if(ret){
        cout << true << endl;
    }
    else {
        cout << false << endl;
    }
}
int main(){
    test1();
    return 0;
}
```

​	总结：二分查找效率很高，值得注意的是查找的容器中元素必须是有序的序列

count算法

```c++
//count统计元素个数
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//1、统计内置数据类型
void test1(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);
    v.push_back(40);
    cout << count(v.begin(), v.end(), 40) <<endl;
}
//2、统计自定义数据类型
class Person{
    public:
        Person(string name, int age){
            this->mName = name;
            this->mAge = age;
        }
        string mName;
        int mAge;
        
        //重载==，用引用必须使用const修饰，繁殖修改底层代码。不用引用，不加const。因为是拷贝出来的，不会修改
        bool operator== (const Person & p2){
            // return this->mName == p2.mName && this->mAge == p2.mAge;
            return this->mAge == p2.mAge;
        }
};
void test2(){
    vector<Person> v;
    v.push_back(Person("aa", 10));
    v.push_back(Person("bb", 10));
    v.push_back(Person("aa", 10));
    v.push_back(Person("aa", 10));

    //需要重载==
    //查找年龄相等的人数
    cout << count(v.begin(), v.end(), Person("aa", 10));
}
int main(){
    test1();
    test2();
    return 0;
}
```

​	总结：统计自定义数据类型的时候，一定要重载==

count_if

```c++
//count_if 按条件统计元素个数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//1、内置数据类型
class Greater20{
    public:
        bool operator()(int val){
            return val > 20;
        }
};
void test1(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    int num = count_if(v.begin(), v.end(), Greater20());
    cout << num << endl;

}
//2、自定义数据类型
class Person{
    public:
        Person(string name, int age){
            this->mName = name;
            this->mAge = age;
        }
        string mName;
        int mAge;
        
        //重载==，用引用必须使用const修饰，防止修改底层代码。不用引用，不加const。因为是拷贝出来的，不会修改
        // bool operator== (const Person & p2){
        //     return this->mName == p2.mName && this->mAge == p2.mAge;
        // }
};

class Mycom{
    public:
        bool operator()(const Person & p){
            return p.mAge == 10;
        }
};
void test2(){
    vector<Person> v;
    v.push_back(Person("aa", 10));
    v.push_back(Person("bb", 10));
    v.push_back(Person("cc", 10));
    v.push_back(Person("dd", 10));
    v.push_back(Person("ff", 10));
    v.push_back(Person("ee", 10));

    int num = count_if(v.begin(), v.end(), Mycom());
    cout << num << endl;
}
int main(){
    test1();
    test2();
    return 0;
}
```

### 常用的排序算法

sort

```c++
//常用排序算法
//sort算法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Comp(int v1, int v2){
    return v1 > v2;
}

void myprint(int val){
    cout << val << " ";
}
void test1(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);

    sort(v.begin(),v.end(), Comp);
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), myprint);
    cout << endl;

}
int main(){
    test1();
    return 0;
}
```

random_shuffle

```c++
//random_shuffle
//洗牌，指定范围内的元素随机调整次序
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
void myprint(int val){
    cout << val << " ";
}
void test1(){
    srand((unsigned int)time(NULL));
    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), myprint);
    cout << endl;
    //洗牌算法 每一次打乱的结果,可以设置时间种子。得到真随机数
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), myprint);
    cout << endl;
}
int main(){
   
    test1();
    return 0;
}
```

merge算法

```c++
//merge算法
//两个容器元素合并，并存储到另一容器中。两个容器必须有序
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void myprint(int val){
    cout << val << " ";
}
void test1(){
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 10; i++){
        v1.push_back(i);
        v2.push_back(i+1);
    }


    //目标容器
    vector<int> vTarget;
    //提前给目标容器分配内存
    vTarget.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), myprint);

}
int main(){
    test1();
    return 0;
}
```

reverse算法

```c++
//reverse反转算法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void myprint(int val){
    cout << val << " ";
}
void test1(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    //参数是迭代器区间。自定义数据类型也可以反转
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), myprint);
}
int main(){
    test1();
    return 0;
}
```

### 常用拷贝和替换算法

copy

```c++
//常用拷贝和替换算法
//copy,容器内指定范围的元素拷贝到另一容器中
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void myprint(int val){
    cout << val << " ";
}
void test1(){
    vector<int> v1;
    for (int i = 0; i < 10; i++){
        v1.push_back(i);
    }

    vector<int> v2;
    //需要提前开辟空间
    v2.resize(v1.size());
    copy(v1.begin(), v1.end(), v2.begin());

    for_each(v2.begin(), v2.end(), myprint);
}
int main(){
    test1();
    return 0;
}
```

replace

```c++
//replace
//将容器内指定范围的旧元素修改为新元素
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class MyPrint{
    public:
        void operator()(int val){
            cout << val << " ";
        }
};
void test1(){
    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }

    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    //内置数据类型替换
    replace(v.begin(), v.end(), 1, 30);
    for_each(v.begin(), v.end(), MyPrint());
}

class Person{
    public:
        Person(string name, int age){
            this->mName = name;
            this->mAge = age;
        }
        string mName;
        int mAge;
        
        //重载==，用引用必须使用const修饰，繁殖修改底层代码。不用引用，不加const。因为是拷贝出来的，不会修改
        bool operator== (const Person & p2){
            // return this->mName == p2.mName && this->mAge == p2.mAge;
            return this->mAge == p2.mAge;
        }
};

void myprint(const Person & p){
    cout << p.mName << " " << p.mAge << endl;
}
void test2(){
    vector<Person> v;
    v.push_back(Person("aaa", 100));
    v.push_back(Person("aaa", 100));
    v.push_back(Person("aaa", 100));
    v.push_back(Person("aaa", 100));
    v.push_back(Person("aaa", 100));
    Person p1 ("aaa", 100);
    replace(v.begin(), v.end(), p1, Person("bbb", 120));

    for_each(v.begin(), v.end(), myprint);
}
int main(){
    test1();
    test2();
    return 0;
}
```

replace_if

```c++
//replace_if将区间内的元素按条件替换成指定的元素
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Compare{
    public:
        bool operator()(int val){
            return val == 10;
        }
};

void test1(){
    vector<int> v;
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(50);

    replace_if(v.begin(), v.end(), Compare(), 30);

    for (int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}

int main(){
    test1();
    return 0;
}
```

​	总结：replace_if按条件查找，可以利用仿函数灵活筛选满足的条件

swap

```c++
//swap算法
//互换两个容器内的元素
#include <iostream>
#include <vector>
using namespace std;
void test1(){
    vector<int> v1;
    vector<int> v2;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);

    v2.push_back(1);
    v2.push_back(12);
    v2.push_back(3);
    v2.push_back(4);

    v1.swap(v2);
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << " "  << v2[i] << endl;
    }
}
int main(){
    test1();
    return 0;
}
```

​	总结：容器类型相同，才可以交换

### 常用算数生成算法

头文件为<numeric>

accumulate

```c++
#include <iostream>
#include <vector>
#include <numeric>
//常用算数生成算法
using namespace std;

void test1(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    //起始值是起始累加的值
    int total = accumulate(v.begin(), v.end(), 1);
    cout << total << endl;
}
int main(){
    test1();
    return 0;
}
```

fill

```c++
#include <iostream>
#include <vector>
using namespace std;

//常用算数生成算法fill
void test1(){
    vector<int> v;
    v.resize(10);
    fill(v.begin(), v.end(), 100);
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << endl;
    }
}

int main(){
    test1();
    return 0;
}

```

### 常用的集合算法

set_intersection

​	总结：求交集的两个集合必须是有序序列、目标容器开辟空间需要取两个容器的最小值、返回值是最会一个元素后一个位置的迭代器

set_union

set_difference

```c++
//set算法
//交、并、差
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test1(){
    vector<int> v1;
    vector<int> v2;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);

    v2.push_back(20);
    v2.push_back(40);
    v2.push_back(50);

    vector<int> target;
    //提前开辟空间。交集最特殊的情况就是大容器包含小容器
    // target.resize(min(v1.size(), v2.size()));
    //并集特殊情况，size相加
    // target.resize(v1.size()+v2.size());
    //差集最特殊情况 max(size)
    // target.resize(max(v1.size(), v2.size()));
    target.resize(10);
    vector<int>::iterator itend ;
    itend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
    itend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
    itend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
    for (vector<int>::iterator it = target.begin(); it != itend; it++){
        cout << *it << " ";
    }
    cout << endl;
    cout << *itend << endl;
}
int main(){
    test1();
    return 0;
}
```

