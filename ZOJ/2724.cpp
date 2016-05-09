#include <cstdio>  
#include <queue>  
#include <cstring>  
using namespace std;  
  
struct Message {  //这里不要用typedef了，因为重载运算符参数类型Message不能识别；  
    char Name[200];  
    int data, priority;  
  
    bool operator < (const Message a) const  //重载 < 运算符自定义排序准则；  
    {  
        return a.priority < priority;  
    }  
};  
  
int main()  
{  
    priority_queue <Message> v; //定义一个优先队列的对象；  
    char command[200];  
  
    while(~scanf ("%s", command)) 
    {  //输入命令;  
        Message message;  
        if(strcmp (command, "GET") == 0)
        {  
            if(v.size () == 0)
            {      //队列为空；  
                printf ("EMPTY QUEUE!\n");  //使用cout<<"EMPTY QUEUE"<<endl;不会超时;  
            }
            else
            {  
                printf ("%s %d\n", v.top().Name, v.top().data); //使用cout<<v.top().Name<<v.top().data会超时；  
                v.pop ();    //出队列操作，即将当前消息清除;  
            }  
        }
        else if(strcmp (command, "PUT") == 0) 
        {  
            scanf ("%s %d %d", message.Name, &message.data, &message.priority);  
            v.push (message);   //入列；  
        }  
    }  
    return 0;  
} 
