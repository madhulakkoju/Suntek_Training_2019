// large Plus finding with dynamic programming
/*

Find size of the largest ‘+’ formed by all ones in a binary matrix
Given a N X N binary matrix, find the size of the largest ‘+’ formed by all 1s.

Example:
10
1 0 1 1 1 1 0 1 1 1
1 0 1 0 1 1 1 0 1 1 
1 1 1 0 1 1 0 1 0 1
0 0 0 0 1 0 0 1 0 0
1 0 0 0 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 0 0 0 1 0 0 1 0 1
1 0 1 1 1 1 0 0 1 1
1 1 0 0 1 0 0 0 0 0
1 0 1 1 1 1 0 1 0 0

***** 17 answer
For above matrix, largest ‘+’ would be formed by highlighted part of size 17.

*/

#include<stdio.h>
#include<stdlib.h>

int *a[50];
int *visit[50];
int siz=0;
int n;

int minim(int aa[])
{
  int g=aa[0];
  for(int i=1;i<4;i++)
  {
    if(g > aa[i])
    g = aa[i];
  }
  return g;
}
int check(int x,int y,int type);
void recursioncheck(int x,int y);

int main()
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    a[i] = (int *)malloc(sizeof(int)*n);
    visit[i] = (int *)malloc(sizeof(int)*n);
    for(int j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
  recursioncheck(n/2,n/2);
  printf("%d",(siz - 1)*4 + 1);
  return 0;
}

int check(int x,int y,int type)
{
  if(x<0 || x>=n  || y>=n || y<0 ) return 0;
  if(a[x][y]==0) return -1;
  if(type == 1)  return 1 + check(x,y-1,type);
  if(type == 2)  return 1 + check(x+1,y,type);
  if(type == 3)  return 1 + check(x,y+1,type);
  if(type == 4)  return 1 + check(x-1,y,type);
}
void recursioncheck(int x,int y)
{ if(x<0 || x>=n  || y>=n || y<0 ) return;
  if(visit[x][y] != 0) return;
  int aa[4];
  for(int i=0;i<4;i++)
    aa[i] = check(x,y,i+1);
  int g = minim(aa);
  if(siz < g) siz = g;
  visit[x][y] = 1;
  recursioncheck(x-1,y);recursioncheck(x+1,y);
  recursioncheck(x,y+1);recursioncheck(x,y-1);
  return;
}



