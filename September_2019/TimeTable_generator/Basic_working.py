
'''
ASSUMPTIONS :
The Subject Time table is designed in such a way that all the faculty of a suject are considered to be a single entity.
All the timetables depict a scenario where a day's timetable is given to all classes at a time

Each hour / period of class is considered to be an Hour / 60 min.
The time for Lunch is not been depicted in the file but are considered while building code. It can be given afer half of the periods.

lab rooms, class rooms are not added in this.

the faculty are assumed to be completely dedicated to this year sections only.
'''
import numpy as np
import time 
sub_name=[]
lab_name=[]
class_name=[]
days=["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"]
f0 = open("cls.txt","a")
f1 = open("sub.txt","a")
f2 = open("lab.txt","a")
class_count=int(input("number of classes : "))
for i in range(0,class_count):
	class_name.append(input(" Class name --> "))
hrs=int(input("number of hours per day : "))
sub_count=int(input("number of subjects : "))
print("enter subjects in priority order")
for i in range(0,sub_count):
	sub_name.append(input("--> "))
lab_count=int(input("How Many Labs ?  : "))
for i in range(0,lab_count):
	lab_name.append(input("Lab Name --> "))
lab_time=int(input("Each Lab Time : "))
sub_hr = np.zeros((sub_count,hrs),dtype= 'object')
lab_hr =np.zeros((lab_count,hrs),dtype='object')
lab_check = np.zeros((class_count,lab_count),dtype=np.int)
lab_freq = 1
week_classes = hrs*6 - lab_count*lab_time*lab_freq
sub_div = []
div=[]
for i in range(0,sub_count):
	div.append(week_classes//sub_count)
for i in range(0,week_classes % sub_count):
	div[i]=div[i]+1
for i in range(0,class_count):
  sub_div.append(list(div))
print(sub_div)
print(lab_check)
print(lab_hr)
print(sub_hr)
day_cnt = 0
for day_cnt in range(0,6):
  time.sleep(5)
  sub_hr = np.zeros((sub_count,hrs),dtype='object')
  lab_hr =np.zeros((lab_count,hrs),dtype='object')
  f0 = open("cls.txt","a")
  f0.write(days[day_cnt])
  f0.write("\n*************************************************\n")
  f2 = open("lab.txt","a")
  f2.write(days[day_cnt])
  f2.write("\n*************************************************\n")
  f1 = open("sub.txt","a")
  f1.write(days[day_cnt])
  f1.write("\n*************************************************\n")
  print(days[day_cnt])
  print("Time Table for the day has started ")
  for cl in range(0,class_count):
    time.sleep(2)
    f0.write(class_name[cl]+"   ::   ")
    left = hrs
    while(left > 0):
      k=0
      if(left<=0):
        break
      for k in range(0,lab_count):
        if(lab_check[cl][k] < lab_freq and left >= lab_time and lab_hr[k][(hrs-left)]==0):
          print("lab update")
          lab_check[cl][k]= lab_check[cl][k] + 1
          for up in range(0,lab_time):
            lab_hr[k][hrs-left] = class_name[cl]
            left = left - 1
            f0.write("   ")
            if(up == lab_time//2):
              f0.write(" "+lab_name[k]+" ")
          break
      for k in range(0,sub_count):
        print(k)
        if(left <= 0):
          break
        if(sub_hr[k][hrs-left]!=0):
          continue
        if(k>= 6):
          k=0
        if(left<=0):
          break
        if(sub_hr[k][hrs-left]==0 and sub_div[cl][k]>0):
          print("sub update")
          if(sub_div[cl][k]>=2 and left >= 2 and left!=(hrs//2)+1):
            sub_div[cl][k] = sub_div[cl][k] - 2
            sub_hr[k][hrs-left] = class_name[cl]
            sub_hr[k][hrs-left+1] = class_name[cl]
            f0.write(" "+sub_name[k]+" ")
            f0.write(" "+sub_name[k]+" ")
            left = left - 2
          else:
            sub_div[cl][k] = sub_div[cl][k] - 1
            sub_hr[k][hrs-left] = class_name[cl]
            f0.write(" "+sub_name[k]+" ")
            left = left - 1
      
    f0.write("\n")
  f0.write("\n*************************************************\n")
  f0.close()
  f1 = open("sub.txt","a")
  for ii in range(0,sub_count):
    f1.write("\n " + sub_name[ii]+"  ::  ")
    for uu in range(0,hrs):
      f1.write(" "+str(sub_hr[ii][uu])+" ")
  f1.write("\n*************************************************\n")
  f1.close()
  f2 = open("lab.txt","a")
  for ii in range(0,lab_count):
    f2.write("\n "+lab_name[ii]+"  ::  ")
    for uu in range(0,hrs):
      f2.write(" "+str(lab_hr[ii][uu])+" ")
  f2.write("\n*************************************************\n")
  f2.close()
print("The Time Table is found in corresponding files")


'''
OUTPUT FORMAT ::::
-----------------FOR CLASSES-------------
Monday
*************************************************
A   ::          MCLL     AINN  AINN  UNIX 
B   ::          CDLL     UNIX  UNIX  CNET 
C   ::          JVLL     CNET  CNET  JAVA 
D   ::    AINN  AINN  UNIX  JAVA  JAVA  PYTH 
E   ::    UNIX  UNIX  CNET  PYTH  PYTH  IOTS 
F   ::    CNET  CNET  JAVA  IOTS  IOTS  AINN 

*************************************************
Tuesday
*************************************************
A   ::          CDLL     AINN  AINN  UNIX 
B   ::          MCLL     UNIX  UNIX  CNET 
C   ::    AINN  AINN  UNIX  CNET  CNET  JAVA 
D   ::          JVLL     JAVA  JAVA  PYTH 
E   ::    UNIX  UNIX  CNET  PYTH  PYTH  IOTS 
F   ::    CNET  CNET  JAVA  IOTS  IOTS  AINN 

*************************************************
Wednesday
*************************************************
A   ::          JVLL     AINN  UNIX  UNIX 
B   ::    AINN  AINN  UNIX  CNET  CNET  JAVA 
C   ::          MCLL     UNIX  UNIX  CNET 
D   ::          CDLL     PYTH  PYTH  IOTS 
E   ::    UNIX  CNET  CNET  JAVA  JAVA  AINN 
F   ::    CNET  JAVA  JAVA        MCLL    

*************************************************
Thursday
*************************************************
A   ::    UNIX  CNET  CNET  JAVA  JAVA  PYTH 
B   ::          JVLL     AINN  AINN  CNET 
C   ::          CDLL     UNIX  UNIX  JAVA 
D   ::          MCLL     CNET  CNET  IOTS 
E   ::    AINN  AINN  JAVA  IOTS  IOTS  AINN 
F   ::    PYTH  PYTH  AINN  PYTH  PYTH  UNIX 

*************************************************
Friday
*************************************************
A   ::    CNET  CNET  JAVA  PYTH  PYTH  IOTS 
B   ::    AINN  JAVA  JAVA  IOTS  IOTS  JAVA 
C   ::    JAVA  PYTH  PYTH  AINN  AINN  PYTH 
D   ::    UNIX  UNIX  CNET  UNIX  UNIX  CNET 
E   ::          MCLL     CNET  JAVA  AINN 
F   ::          CDLL           JVLL    

*************************************************

------------------------------ FOR SUBJECTS---------------------

Monday
*************************************************

 AINN  ::   D  D  0  A  A  F 
 UNIX  ::   E  E  D  B  B  A 
 CNET  ::   F  F  E  C  C  B 
 JAVA  ::   0  0  F  D  D  C 
 PYTH  ::   0  0  0  E  E  D 
 IOTS  ::   0  0  0  F  F  E 
*************************************************
Tuesday
*************************************************

 AINN  ::   C  C  0  A  A  F 
 UNIX  ::   E  E  C  B  B  A 
 CNET  ::   F  F  E  C  C  B 
 JAVA  ::   0  0  F  D  D  C 
 PYTH  ::   0  0  0  E  E  D 
 IOTS  ::   0  0  0  F  F  E 
*************************************************
Wednesday
*************************************************

 AINN  ::   B  B  0  A  0  E 
 UNIX  ::   E  0  B  C  C  A 
 CNET  ::   F  E  E  B  B  C 
 JAVA  ::   0  F  F  E  E  B 
 PYTH  ::   0  0  0  D  D  0 
 IOTS  ::   0  0  0  0  0  D 
*************************************************
Thursday
*************************************************

 AINN  ::   E  E  F  B  B  E 
 UNIX  ::   A  0  0  C  C  F 
 CNET  ::   0  A  A  D  D  B 
 JAVA  ::   0  0  E  A  A  C 
 PYTH  ::   F  F  0  F  F  A 
 IOTS  ::   0  0  0  E  E  D 
*************************************************
Friday
*************************************************

 AINN  ::   B  0  0  C  C  E 
 UNIX  ::   D  D  0  D  D  0 
 CNET  ::   A  A  D  E  0  D 
 JAVA  ::   C  B  B  0  E  B 
 PYTH  ::   0  C  C  A  A  C 
 IOTS  ::   0  0  0  B  B  A 
*************************************************


------------------------------ FOR LABS------------------------

Monday
*************************************************

 MCLL  ::   A  A  A  0  0  0 
 CDLL  ::   B  B  B  0  0  0 
 JVLL  ::   C  C  C  0  0  0 
*************************************************
Tuesday
*************************************************

 MCLL  ::   B  B  B  0  0  0 
 CDLL  ::   A  A  A  0  0  0 
 JVLL  ::   D  D  D  0  0  0 
*************************************************
Wednesday
*************************************************

 MCLL  ::   C  C  C  F  F  F 
 CDLL  ::   D  D  D  0  0  0 
 JVLL  ::   A  A  A  0  0  0 
*************************************************
Thursday
*************************************************

 MCLL  ::   D  D  D  0  0  0 
 CDLL  ::   C  C  C  0  0  0 
 JVLL  ::   B  B  B  0  0  0 
*************************************************
Friday
*************************************************

 MCLL  ::   E  E  E  0  0  0 
 CDLL  ::   F  F  F  0  0  0 
 JVLL  ::   0  0  0  F  F  F 
*************************************************

====> 0'S DEPICT AS FREE HOURS FOR FACULTY
====> LETTERS IN LAB FILE DEPICT CLASSES WHICH ATTEND THE  LAB
====> LETTERS IN SUBJECTS FILE DEPICT THE CLASS WHICH FACULTY HAS TO ATTEND
'''
