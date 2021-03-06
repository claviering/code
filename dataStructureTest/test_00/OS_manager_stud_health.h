/*************************************************************************
	> File Name: OS_manager_stud_health.h
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Sep 2016 09:17:55 PM CST
 ************************************************************************/

/*
 * 实验0：（只供学期初练习，不计入实验成绩中）
 *
 *实验内容：
 *
 *1.用面向对象程序设计方法（需要使用C++程序设计语言）实现一个“学生健康情况管理系统”。
 *
 *【问题描述】
 *   实现学生健康情况管理的几个操作功能（新建、插入、删除、从文件读取、写入文件和查询、屏幕输出等功能）。健康表中学生的信息有学号、姓名、出生日期、性别、身体状况等。
 *
 *即系统的菜单功能项如下：
 *
 *1------新建学生健康表
 *新建一个对象，输入名字
 *2------向学生健康表添加新的学生信息
 *操作空表
 *3------向学生健康表插入新的学生信息（按位置号来描述插入点）
 *对旧信息更新
 *4------在健康表删除指定学生的信息（按学号操作）
 *就是删除，值为空
 *5------为某个学生修改身体状况信息（按学号操作）
 *就是修改，还是有的
 *6------按学生的学号排序并显示结果
 *7------在健康表中查询学生信息（按学生学号来进行查找）
 *8------在屏幕中输出全部学生信息
 *9------从文件中读取所有学生健康表信息
 *10------向文件写入所有学生健康表信息
 *11-----退出
 *
 *2.请使用模板的设计方法再次实现该系统。
 *
 *3.如果要实现一个商品进销存管理系统，你觉得该如何解决？
 *
*/

#include <iostream>
using namespace std;

const string INPUT_STUDENT_NAME = "input a student name";

class Student
{
    private:
        int m_num;
        string m_name;
        string m_birth;
        string m_gender;
        string m_condition;
    public:
        void Student();
        void creatTable();
        void addInfo();
        void addNewInfo();
        void delInfo();
        void modifyInfo();
        void sortBynum();
        void inquiryBynum();
        void displayAllInfo();
        void readForFile();
        void writeToFile();
        void exitOS();
};
void Student::Student()
{

}

void Student::creatTable()
{
    Student stud;
    cout << INPUT_STUDENT_NAME << endl;
    cin >> stud.m_name;
}

void Student::addInfo()
{
	Student stud;

	cout << INPUT_STUDENT_BIRTHDAY << endl;
	cin >> stud.m_birth;

	cout << INPUT_STUDENT_GENDER << endl;
	cin >> stud.m_gender;

	cout << INPUT_STUDENT_CONDITION << endl;
	cin >> stud.m_condition;
	
}

void Student::addNewInfo()
{
	Student stud;

	cout << "old infomation" << endl;
	cout << stud.m_name << endl;
	cout << stud.m_num << endl;
	cout << stud.m_birth << endl;
	cout << stud.m_condition << endl;
	cout << stud.m_gender << endl;

	cout << "which info would you would to chang " << endl;
	cout << "1: name 2: num 3:birth 4:condition 5:gender" << endl;
	int choose;
	cin >> choose;
	
}
