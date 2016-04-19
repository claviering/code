#include<iostream>
#include<stack>
#include<ctype.h>

using namespace std;

/*test: 3*2+4/2*(2+3)+6  ->  3 2 * 4 2 / 2 3 + + 6 +   */

char postexp[255];// 保存后缀表达式

void in2post(char *Exp)//将存放在Exp中以'\0'作结束的中缀表达式转换为后缀表达式 
{    
  stack<char>st2;// 开辟一个运算符栈    

  int  k=0;  //记录后缀表达式的当前存放位置

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
		   postexp[k]=' ';  k++; // 运算对象的分割符
			      break;
       case '(':  st2.push( '(' ); //  ( 入栈
	          i=i+1;
	          break;
       case ')':  ch=st2.top( );
	          while ( ch!='(' ) 
		  {
		    st2.pop(); 
		    postexp[k]=ch; k++;
		    ch=st2.top( );
		   }
		   st2.pop(); //去掉(
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
			else  break ; // 跳出循环 	
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
