#include<stdio.h>
#include<iostream.h>


struct LinkNode {           //���嵥������Ľ��ṹ
	int data;
	LinkNode *next;
};

void Print(LinkNode *h);  //�������

LinkNode *Create(int n);     //ͷ���뽨������

/* my code */
/**********************************************************************/

int linkLen(LinkNode *h) 
{
	static int len = 0;
	if (h != NULL)
	{
		len++;
		return linkLen(h -> next);
	}
	else
		return len;
}

void repPrintLink(LinkNode *h)
{
	if (h != NULL)
	{
		cout << h -> data << ends;
		repPrintLink(h -> next);

	}
}

LinkNode *repCreate(int n)
{


}

/**********************************************************************/


void main()
{
    LinkNode *head;    // ��ͷ���
    int n;

	head=0;  

  	cout<<"\nplease enter the number of nodes(insert in head):";
	cin>>n;
	head=Create(n);  //��������
    Print(head);    //�������

	int l = linkLen(head);
	cout << l << endl;
	repPrintLink(head);

	Print(head);   //�������

}


LinkNode *Create(int n)
{
  LinkNode *p, *h=0;
  int i;

  for(i=1;i<=n;i++)
  {
	  p=new LinkNode;
	  p->data=i;
	  p->next=h;
	  h=p;
  };
  return h;
}


void Print(LinkNode *h)
{
 LinkNode *p=h;

 cout<<"\n The data in the link are:\n";
 while ( p!=0)
 {
	 cout<<p->data<<"   ";
	 p=p->next;
 }
 cout<<"\n\n\n";
}
