/*
 * 主函数
 * @Author lin wei ye
 */
#include "student_list.h"
#include "student.h"

#include <iostream>
#include <fstream>
using namespace std;

/*
 * 1.新建学生健康表
 * @return 链表的头指针
 */
StudentList<Student> *CreatNewList()
{
    StudentList<Student> *new_list = new StudentList<Student>;
    return new_list;
}

/*
 * 2.向学生健康表添加新的学生信息
 * 输入一个学生的信息，头插入到链表
 * @param objext 链表对象,引用做参数
 * 
 */
template<typename T>
void AddNewInfo(StudentList<T> &object)
{
    cout << "Input number name birthday sex condition" << endl;
    Student node;
    cin >> node.number_ >> node.name_ >> node.birthday_ >> node.sex_ >> node.condition_;
    object.add(node);
}

/*
 * 3.向学生健康表插入新的学生信息(按位置号来描述)"
 * @param objext 链表对象,引用做参数
 * @param location 要插入的位置
 */
template<typename T>
void InsertNewInfo(StudentList<T> &object, int location)
{
    cout << "Input number name birthday sex condition" << endl;
    Student node;
    cin >> node.number_ >> node.name_ >> node.birthday_ >> node.sex_ >> node.condition_;

    object.insert(node, object.Findlocation(location));
}

/*
 * 4.在健康表删除指定学生的信息(按学号操作)"
 * @param objext 链表对象,引用做参数
 * @param number 要删除的学生的学号
 */
template<typename T>
void DeleteInfo(StudentList<T> &object, int number)
{
    Student node;
    node.number_ = number;
    object.Delete(node);
}

/*
 * 5.为某个学生修改身体状况信息(按学号操作)"
 * @param objext 链表对象,引用做参数
 * @param number 要删除的学生的学号
 */
template<typename T>
void ModifyInfo(StudentList<T> &object, int number)
{
    cout << "input new info" << endl;   
    DeleteInfo(object,number);
    AddNewInfo(object);
}
/*
 * 6.按学生的学号排序并显示结果
 * @param objext 链表对象,引用做参数
 */
template<typename T>
void SortAndDisplayAllStudentInfo(StudentList<T> &object)
{
    object.SortList();
    object.traversal(); 
}

/*
 * 7.在健康表中查询学生的信息(按学号查询)
 * @param objext 链表对象,引用做参数
 * @param number 要删除的学生的学号
 */
template<typename T>
void SearchInfo(StudentList<T> &object, int number)
{
    Student node;
    node.number_ = number;
    StudentNode<T> *tmp_node = object.find(node); 
    cout << tmp_node -> data.number_ << endl << tmp_node -> data.name_ << endl << tmp_node -> data.birthday_ << endl << tmp_node -> data.sex_ << endl << tmp_node -> data.condition_ << endl;
}

/*
 * 8.在屏幕中输出全部学生信息"
 */
template<typename T>
void DisplayAllStudentInfo(StudentList<T> &object)
{
    object.traversal(); 
}

/*
 * 9.从文件读取所有学生健康表信息
 */
template<typename T>
void ReadForFile(StudentList<T> object)
{
    Student stu_node;
    fstream read_file; 
    read_file.open("student_info", ios::in | ios::binary);
    while (read_file.read((char *)&stu_node, sizeof(Student)))
    {
        cout << stu_node.number_ << endl << stu_node.name_ << endl << stu_node.birthday_ << endl <<  stu_node.sex_ << endl <<  stu_node.condition_ << endl;
        cout << endl;
    }
    read_file.close();
}

/*
 * 10.向文件写入所有学生健康表信息
 */
template<typename T>
void WriteFile(StudentList<T> object)
{
    StudentNode<T> *tmp = new StudentNode<T>();
    tmp = object.return_headnode_point();
    fstream write_file;
    write_file.open("student_info", ios::out | ios::binary | ios::trunc);
    while (tmp != NULL)
    {
        write_file.write((char *)&(tmp -> data), sizeof(Student));
        tmp = tmp -> next;
    }
    write_file.close();
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
void choose(StudentList<T> &object)
{
    ShowMenu();
    int n;
    cin >> n;
    switch(n)
    {
        case 1:
            CreatNewList();
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
    StudentList<Student> obj;
    while (1)
        choose(obj);
    return 0;
}

