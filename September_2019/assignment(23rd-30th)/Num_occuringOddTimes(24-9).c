  
#include<stdio.h>
#include<stdlib.h>
int main()
  {
  int odd=0,gg,inp;
  char ch;
  while(1)
    {
    scanf("%d",&inp);
    gg=scanf("%c",&ch);
    odd = odd^inp;
    if(gg==EOF)
      break;
    }
  printf("%d",odd);
  return 0; 
  }
