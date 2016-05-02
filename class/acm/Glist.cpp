#include<iostream>
#include<queue>
using namespace std;


void main()
{
   queue<char> qu;

   char str[255];


   int i,s, max=-32767;
  
   qu.push('A');

   while(!qu.empty())
   {
      qu.pop();
      cin.getline(str,255);
	  i=0;
      while(str[i]!='\0')
       {
          if (isdigit(str[i]))
		  {
		     s=0;
			 do 
			 {
			    s=s*10+str[i]-48;
				i++;
			 }while (isdigit(str[i]));
		    if (s>max) max=s;
		   }
		  else if ( isalpha(str[i]))
		   { 
		     qu.push(str[i]);
		     i++;
			}
          else i++;
		}
    }

  cout<<max;


}