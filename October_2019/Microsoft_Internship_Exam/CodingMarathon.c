int marathon(int input1,int input2,int input3[])
{
  if(input2 <= 0)
  {
   return 0; 
  }
  int i =0;
  long int t=0;
  for(i=0;i<input1;i++)
  {
   for(int j = i+1;j<input1;j++)
   {
    if(input3[i]<input3[j])
    {
     t =input3[j];
      input3[j]=input3[i];
      input3[i]=t;
    }
   }
  }
  t=0;
  for(i=0;i<input2;i++)
    t+= input3[i];
  return t;
}

/*
OUTPUT  :   RETURN SUM OF MARKS OF FIRST K TOP SCORERS.

INPUT1  :  N = TOTAL PARTICIPANTS
INPUT2  :  K = TOP SCORERS 
INPUT3  :  ARRAY OF LENGTH N WITH SCORES OF ALL N PARTICIPANTS


*/
