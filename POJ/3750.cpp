#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int num;
    char name[200];
    struct node*next;
};
struct node*creat(int n)
{
    int i;
    struct node*p,*tail,*head;
    p=(struct node*)malloc(sizeof(struct node));
    p->num=1;
    scanf("%s%*c",&p->name);
    p->next=NULL;
    head=p;
    tail=p;
    for(i=2;i<=n;i++)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->num=i;
        scanf("%s%*c",&p->name);
        tail->next=p;
        tail=p;
        p->next=NULL;
    }
    tail->next=head;
    return head;
}
int sel(struct node*head,int s,int m,int n)
{
    int num=0,i;
    int count=0;
    struct node*p,*q;
    q=head;
    while(q->next!=head)
        q=q->next;
        for(i=0;i<s-1;i++)
        {q=q->next;}
        //printf("被删除的人的序号依次是:");
        while(count<n-1)
        {
            p=q->next;
            num++;
            if(num%m==0)
            {
                q->next=p->next;
                printf("%s\n",p->name);
                free(p);
                count++;
            }
            else
            q=p;
        }
        printf("%s",q->name);
}
int main()
{
    int n,m,s;
    struct node*head;
    scanf("%d",&n);
    head=creat(n);
    scanf("%d,%d",&s,&m);
   sel(head,s,m,n);
    return 0;
}
