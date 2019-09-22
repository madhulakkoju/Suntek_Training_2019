/*
SINGLE LINKED LIST IMPLEMENTATION USING STATIC FIXED SIZE ARRAY
The essence of a general Linked list is preserved using Abstract Datatype
*/

#include <stdio.h>
#define max  20
int arr[max];
int cur = 0,start = 0;
void insert_end(int val)
{
  arr[cur] = val;
  cur++;
  printf("Inserted \n");
}
void insert_begin(int val)
{
  if(cur>= max -1)
  {
    printf("LIST FULL ");
    return;
  }
  for(int i=cur;i>=start;i--)
  {
    arr[i+1] = arr[i];
  }
  arr[0]=val;
  cur++;
}

void insert_at(int val,int loc)
{
  if(cur>= max -1)
  {
    printf("LIST FULL ");
    return;
  }
  for(int i=loc-1;i<=cur;i++)
  {
    arr[i+1] = arr[i];
  }
  arr[loc-1]=val;
  cur++;
}

void delete_end()
{
  cur--;
}
void delete_begin()
{
  if(cur<= start)
  {
    printf("LIST EMPTY ");
    return;
  }
  printf("%d  Deleted\n",arr[0]);
  for(int i=start+1;i<=cur;i++)
  {
    arr[i-1] = arr[i];
  }
  cur--;
}

void delete_at(int loc)
{
  if(cur <= start)
  {
    printf("LIST EMPTY ");
    return;
  }
  printf("%d  Deleted \n",arr[loc-1]);
  for(int i= loc;i<=cur;i++)
  {
    arr[i-1] = arr[i];
  }
  cur--; 
}

void display()
{
  for(int i = start;i<cur;i++)
  {
    printf("%d  -> ",arr[i]);
  }
}
void main() {
  int ch,val,loc;
  while(1)
  {
    printf("\n1.insert at end\n2.delete at end\n3.Deisplay\n4.Insert at beginning\n5.Delete at Beginning\n6.Insert at a location\n7.Insert after location\n8.delete at location\n9.delete after location\n     0.exit\n others :: DISPLAY\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1 : printf("Which value to insert at end ::  ");
               scanf("%d",&val);
               insert_end(val);
               break;
      case 2 : printf("Delete action at end \n");
                delete_end();
                break;
      case 3: printf("Display\n");
              display();
              break;
      case 4: printf("Insert at beginning\n value : ");
              scanf("%d",&val);
              insert_begin(val);
              break;
      case 5:printf("Delete at beginning  \n");
              delete_begin();
              break;
      case 6:printf("Inserting at loc \n  value  : ");
              scanf("%d",&val);
              printf("Which location  : ");
              scanf("%d",&loc);
              insert_at(val,loc);
              break;
      case 7: printf("Insert after loc \n value : ");
              scanf("%d",&val);
              printf(" After Which location  : ");
              scanf("%d",&loc);
              insert_at(val,loc+1);
              break;
      case 8: printf("Delete at loc\n value :  ");
              scanf("%d",&loc);
              delete_at(loc);
              break;
      case 9 : printf("Delete after which location : \n loc ::  ");
              scanf("%d",&loc);
              delete_at(loc+1);
              break;
      case 0 : exit(0);
      default: display();break;
    }
  }
}

/*
INPUT OUTPUT   :::::::::::::::::::::::::::::::

1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
1
Which value to insert at end ::  1
Inserted

1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
1
Which value to insert at end ::  2
Inserted

1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
3
Display
1  -> 2  ->
1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
2
Delete action at end

1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
3
Display
1  ->
1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
4
Insert at beginning
 value : 5

1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
3
Display
5  -> 1  ->
1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
5
Delete at beginning
5  Deleted

1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
3
Display
1  ->
1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
6
Inserting at loc
  value  : 6
Which location  : 1

1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
3
Display
6  -> 1  ->
1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
1
Which value to insert at end ::  5
Inserted

1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
1
Which value to insert at end ::  66
Inserted

1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
3
Display
6  -> 1  -> 5  -> 66  ->
1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
7
Insert after loc
 value : 25
 After Which location  : 2

1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
3
Display
6  -> 1  -> 25  -> 5  -> 5  ->
1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
8
Delete at loc
 value :  3
5  Deleted

1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
3
Display
6  -> 1  -> 5  -> 5  ->
1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
9
Delete after which location :
 loc ::  2
5  Deleted

1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY
3
Display
6  -> 1  -> 5  ->
1.insert at end
2.delete at end
3.Deisplay
4.Insert at beginning
5.Delete at Beginning
6.Insert at a location
7.Insert after location
8.delete at location
9.delete after location
     0.exit
 others :: DISPLAY


*/
