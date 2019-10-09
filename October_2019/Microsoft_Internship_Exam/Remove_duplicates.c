
char *removeDuplicates(char *input1)
{
 int i =0,j=0,m=0,tt=0;
  int n =strlen(input1);
  char c;
  char *ch =(char *)malloc(sizeof(char)*n);
  while(i<n)
  {
   tt=0;j=0;
    while(j<m)
    {
      if(input1[i]==ch[j])
      tt=1;
      j++;
    }
    if(tt=0)
      ch[m++]=input1[i];
    i++;
  }
  ch[m]='\0';
  return ch;
}
