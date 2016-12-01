/*
 * Copyright (C) 
 *
 * USER claviering 
 *
 * DATE 2016-11-30
 *
 * Distributed under terms of the WTFPL license.
 */

/*
 * 函数说明：
 * void choose(AVLTree<T> &object)
 * @param object 健康变的对象
 * 主函数调用choose就可以
 */
#include <iostream>
#include <stdlib.h>
#include "student.h"
#include "student_tree.h"
using namespace std;

/*
 * 1.新建学生健康表
 */
template<typename T>
void CreatNewList(AVLTree<T> &object)
{
    object.Delete();
}

/*
 * 2.向学生健康表添加新的学生信息
 * @param objext AVLTree对象,引用做参数
 * 
 */
template<typename T>
void AddNewInfo(AVLTree<T> &object)
{
    Student new_student(1);
    object.insert(new_student);
}

/*
 * 3.向学生健康表插入新的学生信息(按位置号来描述)"
 * @param objext AVLTree对象,引用做参数
 * @param location 要插入的位置,AVLTree 没有位置要求
 */
template<typename T>
void InsertNewInfo(AVLTree<T> &object, int location)
{
    AddNewInfo(object);
}

/*
 * 4.在健康表删除指定学生的信息(按学号操作)"
 * @param objext AVLTree对象,引用做参数
 * @param number 要删除的学生的学号
 */
template<typename T>
void DeleteInfo(AVLTree<T> &object, int number)
{
    Student node;
    node.number_ = number;
    object.Delete(node);
}

/*
 * 5.为某个学生修改身体状况信息(按学号操作)"
 * @param objext AVLTree对象,引用做参数
 * @param number 要修改的学生的学号
 */
template<typename T>
void ModifyInfo(AVLTree<T> &object, int number)
{
    DeleteInfo(object,number);
    AddNewInfo(object);
}
/*
 * 6.按学生的学号排序并显示结果
 * @param objext AVLTree对象,引用做参数
 */
template<typename T>
void SortAndDisplayAllStudentInfo(AVLTree<T> &object)
{
    object.traversal();
}

/*
 * 7.在健康表中查询学生的信息(按学号查询)
 * @param objext AVLTree对象,引用做参数
 * @param number 要查询的学生的学号
 */
template<typename T>
void SearchInfo(AVLTree<T> &object, int number)
{
    Student tmp;
    tmp.number_ = number;
    TreeNode<T> *p = object.find(tmp);
    cout << p->data << endl;
}

/*
 * 8.在屏幕中输出全部学生信息"
 */
template<typename T>
void DisplayAllStudentInfo(AVLTree<T> &object)
{
    object.traversal(); 
    cout << endl;
}

/*
 * 9.从文件读取所有学生健康表信息
 */
template<typename T>
void ReadForFile(AVLTree<T> object)
{
    Student stu_node;
    fstream read_file; 
    read_file.open("student_info", ios::in | ios::binary);
    while (read_file.read((char *)&stu_node, sizeof(Student)))
    {
        cout << stu_node;
        cout << endl;
    }
    read_file.close();
}

/*
 * 10.向文件写入所有学生健康表信息
 */
template<typename T>
void WriteFile(AVLTree<T> object)
{
    fstream write_file;
    write_file.open("student_info", ios::out | ios::binary | ios::trunc);
    write_file.close();
    object.Write();
}

/*
 * 11.退出
 */
void Exit()
{
    exit(0);
}

/*
 * 输出选择菜单
 * @return 返回菜单号
 * 
 */
void ShowMenu()
{
    cout << "1.新建学生健康表" << endl 
         << "2.向学生健康表添加新的学生信息" << endl 
         << "3.向学生健康表插入新的学生信息(按位置号来描述从0开始)" << endl 
         << "4.在健康表删除指定学生的信息(按学号操作)" << endl 
         << "5.为某个学生修改身体状况信息(按学号操作)" << endl 
         << "6.按学生的学号排序并显示结果" << endl 
         << "7.在健康表中查询学生的信息(按学号查询)" << endl
         << "8.在屏幕中输出全部学生信息" << endl 
         << "9.从文件读取所有学生健康表信息" << endl 
         << "10.向文件写入所有学生健康表信息" << endl 
         << "11.退出" << endl; 
    cout << "input choose" << endl;

}

/*
 *功能选择函数
 *@param 
 */
template<typename T>
void choose(AVLTree<T> &object)
{
    ShowMenu();
    int n;
    cin >> n;
    switch(n)
    {
        case 1:
            CreatNewList(object);
            break;
        case 2:
            AddNewInfo(object);
            break;
        case 3:
            cout << "input location" << endl;
            int location;
            cin >> location;
            InsertNewInfo(object,location);
            break;
        case 4:
            cout << "input student number" << endl;
            int number;
            cin >> number;
            DeleteInfo(object,number);
            break;
        case 5:
            cout << "input student number" << endl;
            cin >> number;
            ModifyInfo(object,number);
            break;
        case 6:
            SortAndDisplayAllStudentInfo(object);
            break;
        case 7:
            cout << "input student number" << endl;
            cin >> number;
            SearchInfo(object,number);
            break;
        case 8:
            DisplayAllStudentInfo(object);
            break;
        case 9:
            ReadForFile(object);
            break;
        case 10:
            WriteFile(object);
            break;
        case 11:
            Exit();
            break;
    }

}

int main()
{
    AVLTree<Student> s;
    while (1)
        choose(s);
    return 0;
}
