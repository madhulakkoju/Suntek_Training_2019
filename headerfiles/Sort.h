#include<stdlib.h>
/*
Madhu 
17241A05F3
1.BUBBLE SORT FOR ARRAY
    BubbleSort_Asc(int * a, int a_size)
    BubbleSort_Desc(int * a, int a_size)

2. INSERTION SORT
    InsertionSort_Asc(int * a, int a_size)
    InsertionSort_Desc(int * a, int a_size)

3. SELECTION SORT
    SelectionSort_Asc(int * a, int a_size)
    SelectionSort_Desc(int * a, int a_size)

4. 

*/


void swap(int* a, int *b)
{
  int t = *a;
  *a=*b;
  *b=t;
}

// SELECTION SORT FOR ARRAY ASCENDING ORDERWS
void SelectionSort_Asc(int* a, int a_size)
{
  int finals=0;
  for(int i=0;i<a_size;i++)
  {
    int min = finals;
    for(int j=finals;j<a_size;j++ )
    {
      if(a[min] > a[j])
      min=j;
    }
    swap(&a[finals],&a[min]);
    finals++;
  }
}

// SELECTION SORT FOR ARRAY DESCENDING ORDERWS
void SelectionSort_Desc(int* a, int a_size)
{
  int finals=0;
  for(int i=0;i<a_size;i++)
  {
    int min = finals;
    for(int j=finals;j<a_size;j++ )
    {
      if(a[min] < a[j])
      min=j;
    }
    swap(&a[finals],&a[min]);
    finals++;
  }
}

// BUBBLE SORT for ARRAY ____ ASCENDING ORDER
void BubbleSort_Asc(int* a,int a_size)
{
  for(int i=0;i<a_size;i++)
  {
    int flag= 0;
    for(int j=i+1;j<a_size;j++)
    {
      if(a[i] > a[j])
      {
        swap(&a[i],&a[j]);
        flag =1;
      }
    }
    if(flag == 1 )
    continue;
  }
  return;
}

// BUBBLE SORT FOR ARRAY _____ DESCENDING ORDER
void BubbleSort_Desc(int* a,int a_size)
{
  for(int i=0;i<a_size;i++)
  {
    int flag =0;
    for(int j=i+1;j<a_size;j++)
    {
      if(a[i] < a[j])
      {
        swap(&a[i],&a[j]);
        flag=1;
      }
    }
    if(flag == 0)
    break;
  }
  return;
}

//  INSERTION SORT ARRAY ASCENDING ORDER

void InsertionSort_Asc(int* a,int a_size)
{
  int mole = 0;
  for(int i=1 ;i<a_size; i++)
  {
    int check_val = a[i];
    for(int j=mole;j>=0;j--)
    {
      if(a[j] > check_val )
      {
        swap(&a[j],&a[j+1]);
        continue;
      }
      if(a[j] < check_val )
      {
        break;
      }
    }
    mole++;
  }
}

// INSERTION SORT ARRAY DESCENDING ORDER

void InsertionSort_Desc(int* a,int a_size)
{
  int mole = 0;
  for(int i=1 ;i<a_size; i++)
  {
    int check_val = a[i];
    for(int j=mole;j>=0;j--)
    {
      if(a[j] < check_val )
      {
        swap(&a[j],&a[j+1]);
        continue;
      }
      if(a[j] > check_val )
      {
        break;
      }
    }
    mole++;
  }
}



