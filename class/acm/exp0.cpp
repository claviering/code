#include<iostream>
#include<ctype.h>
#include<stack>  

using namespace std;

/* test:   4 2 / 6 +5*10/=4     */

int Compute(char *Exp)
{
  int i=0;     
  int factor=0;    
  int val1,val2;  
  stack<int> st;
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
	    case '9':  factor=0;  		
		       do {     //  合并出运算对象的值 			   
			     factor=factor*10+Exp[i]-48; 			 
			     i=i+1;
		          } while ( isdigit( Exp[i] ) ); 

		          st.push(factor);  // 运算对象入栈
			  i--;
		          break;
   	    case '+':val1=st.top();st.pop();
		     val2=st.top(); st.pop();
		     st.push(val1+val2);
		      break;
   	    case '-':val1=st.top();st.pop();
		     val2=st.top(); st.pop();
		     st.push(val2-val1);
		     break;
   	    case '*':val1=st.top();st.pop();
		     val2=st.top(); st.pop();
	     	     st.push(val1*val2);
		     break;
   	    case '/':val1=st.top();st.pop();
		     val2=st.top(); st.pop();
		     st.push(val2/val1);
		     break;	
	 } // swtich
	 i++;				 
	} // while  
  return st.top();
} //compute

void main()
{
     char exp[255];

     cin.getline(exp,255);

     cout<<exp<<"=";
     cout<<Compute(exp)<<endl;


}