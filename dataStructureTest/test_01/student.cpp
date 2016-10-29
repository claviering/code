/*
 * 主函数
 * @Author lin wei ye
 */
#include "student_list.h"
#include "student.h"

#include <iostream>
using namespace std;

/*
 * 输出选择菜单
 * @return 返回菜单号
 * 
 */
int ShowMenu()
{
    cout << "1.新建学生健康表" << endl 
         << "2.向学生健康表添加新的学生信息" << endl 
         << "3.向学生健康表插入新的学生信息(按位置号来描述)" << endl 
         << "4.在健康表删除指定学生的信息(按学号操作)" << endl 
         << "5.为某个学生修改身体状况信息(按学号操作)" << endl 
         << "6.按学生的学号排序并显示结果" << endl 
         << "7.在健康表中查询学生的信息(按学号查询)" << endl
         << "8.在屏幕中输出全部学生信息" << endl 
         << "9.从文件读取所有学生健康表信息" << endl 
         << "10.向文件写入所有学生健康表信息" << endl 
         << "11.退出" << endl; 
    cout << "input choose" << endl;

    int n;
    cin >> n;
    return n;
}

    /*
     *功能选择函数
     *@param 
     */
void choose()
{

}


int main()
{
    choose();
    return 0;
}

