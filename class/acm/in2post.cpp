#include<iostream>
#include<stack>
#include<ctype.h>

using namespace std;

/*test: 3*2+4/2*(2+3)+6  ->  3 2 * 4 2 / 2 3 + + 6 +   */

char postexp[255];// �����׺���ʽ

void in2post(char *Exp)//�������Exp����'\0'����������׺���ʽת��Ϊ��׺���ʽ 
{    
  stack<char>st2;// ����һ�������ջ    

  int  k=0;  //��¼��׺���ʽ�ĵ�ǰ���λ��

  int i=0;    
  char ch;    
  while ( Exp[i]!='\0') 
 {
   switch( Exp[i] ) 
   {
        case '0':     
        case '1':	  
        case '2':    
        case '3':
        case '4':   
	case '5':   
        case '6':      
	case '7':	
        case '8': 	
 	case '9': do 
		  {
		        postexp[k]=Exp[i];	k++;
		        i=i+1;
		   } while ( isdigit( Exp[i] ) ); 
		   postexp[k]=' ';  k++; // �������ķָ��
			      break;
       case '(':  st2.push( '(' ); //  ( ��ջ
	          i=i+1;
	          break;
       case ')':  ch=st2.top( );
	          while ( ch!='(' ) 
		  {
		    st2.pop(); 
		    postexp[k]=ch; k++;
		    ch=st2.top( );
		   }
		   st2.pop(); //ȥ��(
		   i=i+1;
		   break;
       case '+':
       case '-': if ( !st2.empty( ) )
		 {
	             ch=st2.top( );
	             while ( ch!='(' ) 
  		     {
		        st2.pop( );
			postexp[k]=ch; k++;
                        if ( !st2.empty( ) )  
			    ch=st2.top( );       
			else  break ; // ����ѭ�� 	
		      } // while 
		  } // if 
                  st2.push(Exp[i]);
                  i=i+1;
	          break;
       case '/':
       case '*':
                  if ( !st2.empty( ) ) 
		  {
  	            ch=st2.top( );
	            if(( ch=='*')||(ch=='/')) 
		     {
                       st2.pop( );
		       postexp[k]=ch; k++;
                     } // if 
		  }
		  st2.push(Exp[i]);
                  i=i+1;
		  break;
	   } // switch
	 } // while
  while ( !st2.empty( ) ) 
  {
     ch=st2.top( ); st2.pop();
     postexp[k]=ch; k++;
  }   // while 
}  // in2post


void main()
{
    char exp[255];

	cin.getline(exp,255);
	in2post(exp);

	cout<<"inorder expression:"<<exp<<endl<<endl;
	cout<<"post expression:"<<postexp<<endl;

}
