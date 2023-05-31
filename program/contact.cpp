#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
//设计联系人结构体
struct Person{
    //姓名
    string m_Name;
    //性别
    int m_Sex;
    //年龄
    int m_Age;

    //联系电话
    string m_Phone;
    //住址
    string m_Addr;
};

//设计通讯录结构体
struct Addressbooks{
    //通讯录中保存的联系人数组
    Person personArray[MAX];

    //通讯录中当前记录联系人个数
    int m_Size;
};

//菜单显示
void showMenu(){
    cout << "***********************" << endl;
    cout << "***** 1、添加联系人 *****" << endl;
    cout << "***** 2、显示联系人 *****" << endl;
    cout << "***** 3、删除联系人 *****" << endl;
    cout << "***** 4、查找联系人 *****" << endl;
    cout << "***** 5、修改联系人 *****" << endl;
    cout << "***** 6、清空联系人 *****" << endl;
    cout << "***** 0、退出通讯录 *****" << endl;
    cout << "***********************" << endl;
}
//添加函数
void addPerson(Addressbooks* abs){
    //判断通讯录是否已满
    if(abs->m_Size == MAX){
        cout << "通讯录已满，无法添加" << endl;
        return ;
    }
    else {
        //添加具体联系人
        //姓名
        string name;
        cout << "请输入姓名: " << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        //性别
        int sex = 0;
        cout << "请输入性别: " << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        while (true)
        {   
            cin >> sex;
            if(sex == 1 || sex == 2){
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }else {
                cout << "输入有误，请重新输入" << endl;
            }
        }
        
        //年龄
        int age;        
        cout << "请输入年龄: " << endl;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        //电话
        string phone;
        cout << "请输入联系电话: " <<endl;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;
        //住址
        string add;
        cout << "请输入家庭住址: " << endl;
        cin >> add;
        abs->personArray[abs->m_Size].m_Addr = add;

        //更新通讯录人数
        abs->m_Size ++;
        cout << "添加成功" << endl;
        //请按任意键继续
        system("pause");
        //清屏操作
        system("cls");
    }
};

//显示所有联系人
void showPerson(Addressbooks* abs){
    //判断通讯录人数是否为0，如果为0，提示记录为空
    //如果不为0，显示记录的联系人信息
    if(abs->m_Size == 0){
        cout << "当前通讯录为空" << endl;
    }else {
        for (int i = 0; i < abs->m_Size; i++){
            cout << "姓名: " << abs->personArray[i].m_Name << "\t";
            //三目运算符
            cout << "性别: " << (abs->personArray[i].m_Sex == 1?"男":"女")<< "\t";
            cout << "年龄: " << abs->personArray[i].m_Age << "\t";
            cout << "电话: " << abs->personArray[i].m_Phone << "\t";
            cout << "住址: " << abs->personArray[i].m_Addr << endl;
        }
    }

    system("pause");
    system("cls");
};
//检测联系人是否存在函数,如果存在，返回联系人所在数组中的具体位置，不存在则返回-1;
//参数1 通讯录， 参数2 对比姓名
int isExist(Addressbooks* abs, string name){
    for (int i = 0; i <abs-> m_Size; i++){
        //找到姓名
        if(abs->personArray[i].m_Name == name){
            return i;
        }
    }
    //没有找到，返回-1
    return -1;
};
//删除指定联系人
void deletePerson(Addressbooks* abs){
    cout << "请输入要删除的联系人" <<endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if(ret != -1){
        //查找到此人，进行删除操作
        for(int i = ret; i < abs->m_Size; i++){
            //数据前移
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size--;
        cout << "删除成功" << endl;
    } else {
        cout << "查无此人" << endl;
    }
};

//查询指定联系人
void findPerson(Addressbooks* abs){
    cout << "请输入你要查找的联系人" <<endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if(ret != -1){
        //找到了
        cout << "姓名: " << abs->personArray[ret].m_Name << "\t";
        //三目运算符
        cout << "性别: " << (abs->personArray[ret].m_Sex == 1?"男":"女")<< "\t";
        cout << "年龄: " << abs->personArray[ret].m_Age << "\t";
        cout << "电话: " << abs->personArray[ret].m_Phone << "\t";
        cout << "住址: " << abs->personArray[ret].m_Addr << endl;
    } else{
        cout << "未找到联系人" << endl;
    }
};

void modifyPerson(Addressbooks* abs){
    cout << "请输入你要修改的联系人" <<endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if(ret != -1){
        //姓名
        string name;
        cout << "请输入姓名: " << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;
        //性别
        int sex = 0;
        cout << "请输入性别: " << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        while (true)
        {   
            cin >> sex;
            if(sex == 1 || sex == 2){
                abs->personArray[ret].m_Sex = sex;
                break;
            }else {
                cout << "输入有误，请重新输入" << endl;
            }
        }
        
        //年龄
        int age;        
        cout << "请输入年龄: " << endl;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        //电话
        string phone;
        cout << "请输入联系电话: " <<endl;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;
        //住址
        string add;
        cout << "请输入家庭住址: " << endl;
        cin >> add;
        abs->personArray[ret].m_Addr = add;

    } else {
        cout << "未找到联系人" << endl;      
    }
};

//清空联系人
void cleanPerson(Addressbooks* abs){
    abs->m_Size = 0;
    cout << "通讯录清空" <<endl;
    
}
int main() {
    //创建通讯录结构体变量
    Addressbooks abs;
    abs.m_Size = 0;

    int select = 0;
    while (true){
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1:
            addPerson(&abs);
        // 1、添加联系人
            break;
        case 2:
        // 2、显示联系人
            showPerson(&abs);
            break;
        case 3:
        //3、删除联系人
            deletePerson(&abs);
            break;
        case 4:
        //4、查找联系人
            findPerson(&abs);
            break;
        case 5:
        //5、修改联系人
            modifyPerson(&abs);
            break;
        case 6:
        //6、清空联系人
            cleanPerson(&abs);
            break;
        case 0:
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
        default:
            break;
        }
    }
    
    
}