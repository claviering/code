/********************************************************************
	> File Name: student.h
	> Author:lin wei ye 
	> Mail: 
	> Created Time: Mon 24 Oct 2016 09:50:03 PM PDT
 *******************************************************************/

/*
 *学生类
 *属性
 *name_名字
 *birthday_生日
 *sex_性别
 *condition_身体状况
 *
 *方法
 *SetData()获取输入，设置属性
 */

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
using namespace std;

class Student
{
    public:
        int number_;
        char name_[256];
        char birthday_[256];
        char sex_[256];
        char condition_[256];
        void SetData();
};

/*
 *设置学生信息
 *输入名字，生日，性别，身体状况
 */
void Student::SetData()
{
    cout << "input student name birthday sex condition" << endl;
    cin >> name_ >> birthday_ >> sex_ >> condition_;
}
#endif
