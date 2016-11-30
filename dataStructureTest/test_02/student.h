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
        Student();
        friend bool operator < (Student s1,Student s2);
        friend bool operator > (Student s1,Student s2);
        friend ostream &operator << (ostream &os,Student s);
};

Student::Student()
{
    cout << "input number name birthday sex condition" << endl;
    cin >> number_ >> name_ >> birthday_ >> sex_ >> condition_;
}

ostream &operator << (ostream &os,Student s)
{
    os << s.number_ << " " << s.name_ << " " << s.birthday_ << " " << s.sex_ << " " << s.condition_;
    return os;
}

bool operator < (Student s1,Student s2)
{
    if (s1.number_ < s2.number_)
        return 1;
    else
        return 0;
}
bool operator > (Student s1,Student s2)
{
    if (s1.number_ > s2.number_)
        return 1;
    else
        return 0;
}

#endif
