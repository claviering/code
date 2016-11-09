//只能计算一位正数
//使用c++11标准编译
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int priority(char a) 
{
    int temp;
    if (a == '*' || a == '/')
        temp = 2;
    else if (a == '+' || a == '-')
        temp = 1;
    return temp;
}

bool isOperator(char ch)
{
    switch(ch)
    {
    case'+':
    case'-':
    case'*':
    case'/':
        return true;
    default:
        return false;
    }
}

string getPostfixExp(string& infix)
{
    stack<char> operator_stack;
    string postfix;
    for (auto p : infix)
    {
        if (isOperator(p))
        {
            while (!operator_stack.empty() && isOperator(operator_stack.top()) && priority(operator_stack.top()) >= priority(p))
            {
                postfix.push_back(operator_stack.top());
                postfix.push_back(' ');
                operator_stack.pop();
            }
            operator_stack.push(p);
        }
        else if (p == '(')
        {
            operator_stack.push(p);
        }
        else if (p == ')')
        {
            while (operator_stack.top() != '(')
            {
                postfix.push_back(operator_stack.top());
                postfix.push_back(' ');
                operator_stack.pop();
            }
            operator_stack.pop();
        }
        else
        {
            postfix.push_back(p);
            postfix.push_back(' ');
        }
    }
    while (!operator_stack.empty())
    {
        postfix.push_back(operator_stack.top());
        postfix.push_back(' ');
        operator_stack.pop();
    }
    postfix.pop_back();
    return postfix;
}

void getTwoNums(stack<int>& num_stack, int& first, int& second)
{
    second = num_stack.top();
    num_stack.pop();

    first = num_stack.top();
    num_stack.pop();
}

int postfixCalculate(string& postfix)
{
    int first, second;
    stack<int> num_stack;
    for (auto p : postfix)
    {
        switch (p)
        {
        case '*':
            getTwoNums(num_stack, first, second);
            num_stack.push(first * second);
            break;
        case '/':
            getTwoNums(num_stack, first, second);
            num_stack.push(first / second);
            break;
        case '+':
            getTwoNums(num_stack, first, second);
            num_stack.push(first + second);
            break;
        case '-':
            getTwoNums(num_stack, first, second);
            num_stack.push(first - second);
            break;
        case ' ':
            break;
        //   if the item is a number push it on the stack
        default:
            num_stack.push(p - '0');
            break;
        }
    }
    int result = num_stack.top();
    num_stack.pop();
    return result;
}

int main()
{
    while (1)
    {
        string infix;
        cin >> infix;
        string postfix = getPostfixExp(infix);
        cout << postfix << endl;
        cout << postfixCalculate(postfix) << endl;

    }
    return 0;
}

