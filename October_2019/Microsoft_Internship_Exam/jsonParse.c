
int jsonParse(char** input1)
{
  int max =0,push =0;
  for(i=0;i<strlen(input1);i++)
  {
  if(input1[i]=='['||input1[i]=='{'||input1[i]=='(')
  {
  push ++;
  if(max<push) max = push;
  }
  else if(input1[i]==']'||input1[i]=='}'||input1[i]==')')
  {
  push--;
  }
  }
  return max;
}

/*
INPUT / OUTPUT

input1 ::  {[[()]]}

output >> 4

*/
