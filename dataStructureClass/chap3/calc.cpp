/* 
 * USER claviering
 *
 * DATE Thu Nov 10 23:51:28 CST 2016
 *
 * 多为整数的算术表达式计算 
 *
 * 为了实现对多为整数的运算
 * 先把字符串转成数字保存到队列里,并且保存为负数，解决输出后缀表达式的问题
 * 运算符对应的ascii码
 * +43
 * -45
 * *42
 * /47
 * .46
 * (40
 * )41
 * 再从队列里那数出来操作
 */
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

/*
 * 返回运算符的优先级，用于读到的运算符和栈里的运算做比较
 * @param a 运算符对应的ASCII码
 */
int priority(int a) 
{
    int temp;
    if (a == -42 || a == -47)
        temp = 2;
    else if (a == -43 || a == -45)
        temp = 1;
    return temp;
}

/*
 * 判断读到位置是否是运算符
 * @param a 运算符对应的ASCII码
 */
bool isOperator(int a)
{
    if (a == -43 || a == -45 || a == -42 || a == -47)
        return true;
    else 
        return false;
}


/*
 * 把字符串转换成数字，保存到队列里
 * @param infix 中序表达式的字符串
 * @param q 要保存的队列
 */
void ChangeToNumber(string infix,queue<int> &q)
{
    int n = 0;
    bool is_number = 1;
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            is_number = 1;
            n *= 10;
            n += infix[i] - '0';
        }
        else
        {
            if (is_number)
            {
                q.push(n);
                n = 0.00;
            }
            int oper_int = (int)infix[i];
            q.push(-oper_int);
            is_number = 0;
        }
    }
    if (n)
        q.push(n);
}


/*
 * 把中序表达式转化成后缀表达式，保存到队列postfix里
 * @param infix 中序表达式的字符串
 * @param postfix 保存后缀表达式的队列
 */
void getPostfixExp(string infix,queue<int> &postfix)
{
    queue<int> q; //把中序表达式字符串转换成数字保存到队列里
    ChangeToNumber(infix,q);

    stack<int> operator_stack;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        if (isOperator(p))
        {
            while (!operator_stack.empty() && isOperator(operator_stack.top()) && priority(operator_stack.top()) >= priority(p))
            {
                postfix.push(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.push(p);
        }
        else if (p == -40)
        {
            operator_stack.push(p);
        }
        else if (p == -41)
        {
            while (operator_stack.top() != -40)
            {
                postfix.push(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.pop();
        }
        else
        {
            postfix.push(p);
        }
    }
    while (!operator_stack.empty())
    {
        postfix.push(operator_stack.top());
        operator_stack.pop();
    }
}

/*
 * 得到栈里的两个数字
 * @param num_stack 保存数字的栈
 * @param first 第一个数字
 * @param second 第二个数字
 */
void getTwoNums(stack<int>& num_stack, int& first, int& second)
{
    second = num_stack.top();
    num_stack.pop();

    first = num_stack.top();
    num_stack.pop();
}

/*
 * 使用后置表达式计算
 * @param postfix 保存后置表达式的队列
 */
int postfixCalculate(queue<int> &postfix)
{
    int first, second;
    stack<int> num_stack;
    while (!postfix.empty())
    {
        int p = postfix.front();
        postfix.pop();
        if (p == -42)
        {
            getTwoNums(num_stack, first, second);
            num_stack.push(first * second);
        }
        else if (p == -47)
        {
            getTwoNums(num_stack, first, second);
            num_stack.push(first / second);
        }
        else if (p == -43)
        {
            getTwoNums(num_stack, first, second);
            num_stack.push(first + second);
        }
        else if (p == -45)
        {
            getTwoNums(num_stack, first, second);
            num_stack.push(first - second);
        }
        else
        {
            num_stack.push(p);
        }
    }
    int result = num_stack.top();
    num_stack.pop();
    return result;
}

/*
 * 输出后缀表达式
 * @param q 保存后缀表达式的队列
 */
void DisplayPostfix(queue<int> q)
{
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        if (n > 0)
            cout << n << " ";
        else
            cout << (char)-n << " ";
    }
    cout << endl;
}

int main()
{
    queue<int> post; //保存后置运算符的表达式

    while (1)
    {
        string infix;
        cin >> infix;
        getPostfixExp(infix,post);
        DisplayPostfix(post);
        cout << postfixCalculate(post) << endl;
    }
    return 0;
}

