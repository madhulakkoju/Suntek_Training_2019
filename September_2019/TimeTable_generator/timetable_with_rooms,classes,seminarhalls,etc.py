'''
In this program i tried to solve the problem of clashes due to intersection of classes in different year.
i have presumed that the departments donot merge or donot have their faculty in and out. 
the condition ofeach faculty working only 35 hrs a week has been added to this.
the preferences have been assumed to be the classses dealt by each faculty. will have to work on it.
back up classes havent been added with this program yet.
the room details of classes and labs have been added . but the phase of shared classes were not added yet.
Shared Rooms are not added to reduce complexion 
seminar halls have been added just to display details of the class that is  present in the department .

the output has a typical structure. It shows day wise time table of the whole week. 
'''

f0 = open("cls.txt","a")
f1 = open("fac.txt","a")
f2 = open("lab.txt","a")
f3 = open("fac_details.txt","a")
days=['Monday','Tuesday','Wednesday','Thursday','Friday','Saturday']
import numpy as np
f_details=[]
classes=[]
sec =['A','B','C','D','E','F','G','H','I','J','K','L']
year_count=int(input("How many years ?"))
years=[]
print("Enter the yeasrs considered in Ascending order please. " )
for g in range(0,year_count):
  years.append(int(input("Which year : ")))
sections_count = int(input("How many sections in each year ? "))
class_count = year_count * sections_count
hrs = int(input("How many hours per day ?  "))
lab_count = int(input("how many labs to each year ? "))
lab_names=[]
x=[]
ak=[]
rooms_lab=[]
f_lab=[]
klab=[]
for i in range(0,year_count):
  print("year " + str(years[i]))
  x=[]
  ak=[]
  klab=[]
  for j in range(0,lab_count):
    x.append(input("Lab name : "))
    klab.append(input("Room number: "))
    ak.append(input("Faculty 1 name : "))
    ak.append(input("Faculty 2 name : "))
  lab_names.append(list(x))
  f_lab.append(list(ak))
  rooms_lab.append(list(klab))
lab_check = np.zeros((year_count*sections_count,lab_count),dtype=np.int)
lab_hr =np.zeros((year_count,lab_count,hrs),dtype='object')
lab_freq = 1
lab_time=int(input("How many hours of lab per each session : "))
for i in range(0,year_count):
  for j in range(0,sections_count):
    classes.append(str(years[i])+str(sec[j]))
sub_count = int(input("count of Subjects to each year's classes ? ")) 
week_classes= hrs*6 - lab_freq*lab_time*lab_count
sub_names=[]
x=[]
for ii in range(0,year_count):
  print(" year "+ str(years[ii]))
  x=[]
  for jj in range(0,sub_count):
    x.append(input("Subject name :  "))
  sub_names.append(list(x))
#rooms
rooms=[]
for hj in range(0,len(classes)):
  print(" Room alloted for the class " + classes[hj]+"  ")
  rooms.append(input("== ::  "))

sub_div = []
div=[]
for i in range(0,sub_count):
	div.append(week_classes//sub_count)
for i in range(0,week_classes % sub_count):
	div[i]=div[i]+1
for i in range(0,class_count):
  sub_div.append(list(div))
f3.write(" ==========>> FACULTY DETAILS  <<==============\n\n")
def get_faculty(id_f ):
  f3.write("\n******************************\n\nFACULTY ID : "+ str(id_f))
  f_name = input("Faculty Name : ")
  f3.write("Name : "+str(f_name))
  f_yr_count = int(input("How many years students does he deal ?  "))
  y=[]
  sub=[]
  for gg in range(0,f_yr_count):
    y.append(int(input(" which yr : ")))
    sub.append(input("subject : "))
  for gg in range(0,f_yr_count):
    f3.write("  YEAR  "+str(y[gg])+"        Subject :   ")
    f3.write(str(sub[gg]) + "\n")
  f_class_count = int(input("How many sections / classes on the whole should he attend ?:"))
  f_classes =[]
  print("Enter class in form of 3A for third year A section ")
  for i in range(0,f_class_count):
    f_classes.append(input("Which class  "))
  f3.write("\n   Sections dealt with ......\n ")
  for i in range(0,f_class_count):
    f3.write("  "+str(f_classes[i]) +"  ")
  f3.write("Total Sections Count  :"+str(f_class_count) + "\n")
  f_details.append([int(id_f),f_name,f_class_count,f_classes,y,sub,35])#35 is max hrs of work in week

f_count = int(input("How many faculty ?  "))
for k in range(0,f_count):
  get_faculty(k+1)
print(f_details)
f_hr = np.zeros((f_count,hrs),dtype='object')
halls_count = int(input("How many seminar halls : "))
halls=[]
for i in range(0,halls_count):
  halls.append(input("Seminar Hall Room No   :   "))


for day_cnt in range(0,6):
  print(days[day_cnt]+"\n********************************************\n")  
  f_hr = np.zeros((f_count,hrs),dtype='object') 
  lab_hr =np.zeros((year_count,lab_count,hrs),dtype='object')  
  f0.write("\n\n"+days[day_cnt])
  f0.write("\n********************************************\n")
  f1.write("\n\n"+days[day_cnt])
  f1.write("\n********************************************\n")
  f2.write("\n\n"+days[day_cnt])
  f2.write("\n********************************************\n")
  sec_c = 0
  for cl in range(0,year_count*sections_count):
    if(sec_c >= sections_count):
      sec_c = 0
    class_name = classes[cl]
    f0.write(" " + str(class_name)+" Room : "+ str(rooms[cl]) +"   :::   ")
    yr_c = years.index(int(class_name[0]))
    left = hrs
    while(left > 0):
      for la in range(0,lab_count):
        if(lab_check[cl][la]<lab_freq and left >= lab_time and lab_hr[yr_c ][la][hrs-left]==0):
          print('lab update')
          for kk in range(0,lab_time):
            lab_hr[yr_c][la][hrs-left] = class_name
            left = left - 1
            if(kk==lab_time//2):
              f0.write(str(lab_names[yr_c][la])+str("  ")+str(rooms_lab[yr_c][la])) 
            else:
              f0.write(" ")
          lab_check[cl][la] = lab_check[cl][la] + 1
          break
      for fc in range(0,f_count):
        if(left <= 0):
          break
        if(f_details[fc][6]<=1):
          break
        if(class_name in f_details[fc][3] and years[yr_c] in f_details[fc][4] and f_hr[fc][hrs - left]==0 ):
          print("Subject Update")
          gh = f_details[fc][4].index(years[yr_c])
          su =f_details[fc][5][gh]
          ind = sub_names[yr_c].index(su)
          if(sub_div[cl][ind]>2 and left >= 2 and left!=(hrs//2)+1):
            sub_div[cl][ind] = sub_div[cl][ind] - 2
            f_hr[fc][hrs-left] = class_name
            f_hr[fc][hrs-left+1] = class_name
            f0.write(" "+su+" ")
            f0.write(" "+su+" ")
            left = left - 2
            f_details[fc][6] = f_details[fc][6] -2
          else:
            sub_div[cl][ind] = sub_div[cl][ind] - 1
            f_hr[fc][hrs-left] = class_name
            f0.write(" "+su+" ")
            left = left - 1
            f_details[fc][6] = f_details[fc][6] - 1
    f0.write("\n")
    sec_c = sec_c + 1
  f0.write("\n******************************\n")
  print(f_hr)
  print(lab_hr)
  print(" ")
  for ghij in range(0,f_count):
    f1.write("  " + str(f_details[ghij][0]) + "  " + str(f_details[ghij][1])+"   :    ")
    for ghi in range(0,hrs):
      if(f_hr[ghij][ghi]==0):
        f1.write(" FREE  ")
      else:
        f1.write(" " +str(f_hr[ghij][ghi])+"( "+str(rooms[ classes.index(str(f_hr[ghij][ghi]))])+")  ")
    f1.write("\n")
  for ghij in range(0,year_count):
    f2.write("   " + str(years[ghij])+  "  Year  \n")
    for ghi in range(0,lab_count):
      f2.write("  " + str(lab_names[ghij][ghi])+"Room "+ str(rooms_lab[ghij][ghi]) + "   :   ")
      for gh in range(0,hrs):
        f2.write(" "+str(lab_hr[ghij][ghi][gh])+" ")
      f2.write("\n")
    f2.write("\n*****************************************\n")
f1.close()
f2.close()
#adding faculty details to class timetable
f0.write("\n-------- FACULTY DETAILS -----------\n")
for i in range(0,f_count):
  f0.write(" "+ str(f_details[i][1])+"\n")
  for j in range(0,len(f_details[i][5])):
    f0.write("\t: "+str(f_details[i][4][j])+"  "+str(f_details[i][5][j])+"\n")
f0.write("\n-------- LAB FACULTY DETAILS -----------\n")
for i in range(0,len(lab_names)):
  f0.write("  YEAR  " + str(years[i]))
  for j in range(0,len(lab_names[i])):
    f0.write("\n"+str(lab_names[i][j])+"  LAB ==  Room : "+str(rooms_lab[i]))
    f0.write("\n  "+str(f_lab[i][0])+"   "+str(f_lab[i][1]))
f0.write("\n---------- SEMINAR HALLS -----------\n")
for i in range(0,halls_count):
  f0.write(" Seminar Hall   :  " + str(halls[i])+"\n")
f0.write("-------------------------------------------\n")
f3.write("\n========>> LAB FACULTY DETAILS <<============\n")
for i in range(0,len(lab_names)):
  f3.write("  YEAR  " + str(years[i]))
  for j in range(0,len(lab_names[i])):
    f3.write("\n"+str(lab_names[i][j])+"  LAB ==  Room : "+str(rooms_lab[i][j]))
    f3.write("\n  "+str(f_lab[i][0])+"   "+str(f_lab[i][1]))
f3.write("-------------------------------------------\n")
f0.close()        
f3.close()
'''
INPUT FORMAT  :::::

How many years ?1
Enter the yeasrs considered in Ascending order please.
Which year : 1
How many sections in each year ? 6
How many hours per day ?  6
how many labs to each year ? 3
year 1
Lab name : MCLL
Room number: 1401
Faculty 1 name : MC1
Faculty 2 name : MC2
Lab name : JVLL
Room number: 1402
Faculty 1 name : JV1
Faculty 2 name : JV2
Lab name : CDLL
Room number: 1403
Faculty 1 name : CD1
Faculty 2 name : CD2
How many hours of lab per each session : 3
count of Subjects to each year's classes ? 6
 year 1
Subject name :  AINN
Subject name :  IOTS
Subject name :  JAVA
Subject name :  PYTH
Subject name :  UNIX
Subject name :  CNET
 Room alloted for the class 1A
== ::  1001
 Room alloted for the class 1B
== ::  1002
 Room alloted for the class 1C
== ::  1003
 Room alloted for the class 1D
== ::  1004
 Room alloted for the class 1E
== ::  1005
 Room alloted for the class 1F
== ::  1006
How many faculty ?  6
Faculty Name : ACS
How many years students does he deal ?  1
 which yr : 1
subject : AINN
How many sections / classes on the whole should he attend ?:6
Enter class in form of 3A for third year A section
Which class  1A
Which class  1B
Which class  1C
Which class  1D
Which class  1E
Which class  1F
Faculty Name : ICS
How many years students does he deal ?  1
 which yr : 1
subject : IOTS
How many sections / classes on the whole should he attend ?:6
Enter class in form of 3A for third year A section
Which class  1A
Which class  1B
Which class  1C
Which class  1D
Which class  1E
Which class  1F
Faculty Name : JCS
How many years students does he deal ?  1
 which yr : 1
subject : JAVA
How many sections / classes on the whole should he attend ?:6
Enter class in form of 3A for third year A section
Which class  1A
Which class  1B
Which class  1C
Which class  1D
Which class  1E
Which class  1F
Faculty Name : PCS
How many years students does he deal ?  1
 which yr : 1
subject : PYTH
How many sections / classes on the whole should he attend ?:6
Enter class in form of 3A for third year A section
Which class  1A
Which class  1B
Which class  1C
Which class  1D
Which class  1E
Which class  1F
Faculty Name : UCS
How many years students does he deal ?  1
 which yr : 1
subject : UNIX
How many sections / classes on the whole should he attend ?:6
Enter class in form of 3A for third year A section
Which class  1A
Which class  1B
Which class  1C
Which class  1D
Which class  1E
Which class  1F
Faculty Name : CCS
How many years students does he deal ?  1
 which yr : 1
subject : CNET
How many sections / classes on the whole should he attend ?:6
Enter class in form of 3A for third year A section
Which class  1A
Which class  1B
Which class  1C
Which class  1D
Which class  1E
Which class  1F

How many seminar halls : 1
Seminar Hall Room No   :   6001

================================================================================================
OUTPUT FORMAT :::
=============
cls.txt ( FOR CLASS STUDENTS // CLASSES DETAILS  )

Monday
********************************************
 1A Room : 1001   :::    MCLL  1401  AINN  AINN  IOTS 
 1B Room : 1002   :::    JVLL  1402  IOTS  IOTS  JAVA 
 1C Room : 1003   :::    CDLL  1403  JAVA  JAVA  PYTH 
 1D Room : 1004   :::    AINN  AINN  IOTS  PYTH  PYTH  UNIX 
 1E Room : 1005   :::    IOTS  IOTS  JAVA  UNIX  UNIX  CNET 
 1F Room : 1006   :::    JAVA  JAVA  PYTH  CNET  CNET  AINN 

******************************


Tuesday
********************************************
 1A Room : 1001   :::    JVLL  1402  AINN  AINN  IOTS 
 1B Room : 1002   :::    MCLL  1401  IOTS  IOTS  JAVA 
 1C Room : 1003   :::    AINN  AINN  IOTS  JAVA  JAVA  PYTH 
 1D Room : 1004   :::    CDLL  1403  PYTH  UNIX  UNIX 
 1E Room : 1005   :::    IOTS  IOTS  JAVA  UNIX  CNET  CNET 
 1F Room : 1006   :::    JAVA  JAVA  PYTH  CNET  PYTH  AINN 

******************************


Wednesday
********************************************
 1A Room : 1001   :::    CDLL  1403  AINN  IOTS  IOTS 
 1B Room : 1002   :::    AINN  AINN  IOTS  JAVA  JAVA  PYTH 
 1C Room : 1003   :::    MCLL  1401  IOTS  IOTS  JAVA 
 1D Room : 1004   :::    JVLL  1402  PYTH  UNIX  CNET 
 1E Room : 1005   :::    IOTS  JAVA  JAVA  UNIX  CNET  AINN 
 1F Room : 1006   :::    JAVA  PYTH  UNIX  CNET  AINN  AINN 

******************************


Thursday
********************************************
 1A Room : 1001   :::    AINN  IOTS  JAVA  PYTH  PYTH  UNIX 
 1B Room : 1002   :::    CDLL  1403  AINN  AINN  IOTS 
 1C Room : 1003   :::    JVLL  1402  IOTS  JAVA  PYTH 
 1D Room : 1004   :::    MCLL  1401  JAVA  JAVA  CNET 
 1E Room : 1005   :::    IOTS  JAVA  PYTH  UNIX  CNET  AINN 
 1F Room : 1006   :::    JAVA  PYTH  UNIX  CNET  IOTS  IOTS 

******************************


Friday
********************************************
 1A Room : 1001   :::    AINN  IOTS  JAVA  PYTH  UNIX  UNIX 
 1B Room : 1002   :::    IOTS  JAVA  PYTH  UNIX  UNIX  CNET 
 1C Room : 1003   :::    JAVA  PYTH  UNIX  CNET  CNET  AINN 
 1D Room : 1004   :::    PYTH  UNIX  CNET  AINN  AINN  IOTS 
 1E Room : 1005   :::    MCLL  1401  IOTS  JAVA  PYTH 
 1F Room : 1006   :::    JVLL  1402  JAVA  PYTH  JAVA 

******************************


Saturday
********************************************
 1A Room : 1001   :::    AINN  IOTS  JAVA  PYTH  UNIX  CNET 
 1B Room : 1002   :::    IOTS  JAVA  PYTH  UNIX  CNET  CNET 
 1C Room : 1003   :::    JAVA  PYTH  UNIX  CNET  AINN  IOTS 
 1D Room : 1004   :::    PYTH  UNIX  CNET  AINN  IOTS  IOTS 
 1E Room : 1005   :::    JVLL  1402  IOTS  JAVA  PYTH 
 1F Room : 1006   :::    MCLL  1401  CDLL  1403 

******************************

-------- FACULTY DETAILS -----------
 ACS
	: 1  AINN
 ICS
	: 1  IOTS
 JCS
	: 1  JAVA
 PCS
	: 1  PYTH
 UCS
	: 1  UNIX
 CCS
	: 1  CNET

-------- LAB FACULTY DETAILS -----------
  YEAR  1
MCLL  LAB ==  Room : 1401
  MC1   MC2
JVLL  LAB ==  Room : 1402
  JV1   JV2
CDLL  LAB ==  Room : 1403
  CD1   CD2
---------- SEMINAR HALLS -----------
 Seminar Hall   :  6001
-------------------------------------------
CDLL  1403 ======== THIS REPRESENTS THE LAB NAME AND ROOMUMBER AND DEPICTS 3 HRS OF LAB  
1F Room : 1006   :: ======== REPRESENTS CLASS NAME AND THE ROOM WHERE THE CLASS WORK IS TAKEN FOR RESPECTIVE CALSS
==========================================================================================================================
FAC_DETAILS.TXT ( FACULTY DETAILS )

 ==========>> FACULTY DETAILS  <<==============


******************************

FACULTY ID : 1Name : ACS  YEAR  1        Subject :   AINN

   Sections dealt with ......
   1A    1B    1C    1D    1E    1F  Total Sections Count  :6

******************************

FACULTY ID : 2Name : ICS  YEAR  1        Subject :   IOTS

   Sections dealt with ......
   1A    1B    1C    1D    1E    1F  Total Sections Count  :6

******************************

FACULTY ID : 3Name : JCS  YEAR  1        Subject :   JAVA

   Sections dealt with ......
   1A    1B    1C    1D    1E    1F  Total Sections Count  :6

******************************

FACULTY ID : 4Name : PCS  YEAR  1        Subject :   PYTH

   Sections dealt with ......
   1A    1B    1C    1D    1E    1F  Total Sections Count  :6

******************************

FACULTY ID : 5Name : UCS  YEAR  1        Subject :   UNIX

   Sections dealt with ......
   1A    1B    1C    1D    1E    1F  Total Sections Count  :6

******************************

FACULTY ID : 6Name : CCS  YEAR  1        Subject :   CNET

   Sections dealt with ......
   1A    1B    1C    1D    1E    1F  Total Sections Count  :6
   
-------- LAB FACULTY DETAILS -----------
  YEAR  1
MCLL  LAB ==  Room : 1401
  MC1   MC2
JVLL  LAB ==  Room : 1402
  JV1   JV2
CDLL  LAB ==  Room : 1403
  CD1   CD2

THIS FILE IS MEANT FOR OFFICE PURPOSE OR DATA BEHIND . THISFILE SHOWS US THE DETAILS OF EACH FACULTY
================================================================================================================
FAC.TXT ( FACULTY TIMETABLE )


Monday
********************************************
  1  ACS   :     1D( 1004)   1D( 1004)   FREE   1A( 1001)   1A( 1001)   1F( 1006)  
  2  ICS   :     1E( 1005)   1E( 1005)   1D( 1004)   1B( 1002)   1B( 1002)   1A( 1001)  
  3  JCS   :     1F( 1006)   1F( 1006)   1E( 1005)   1C( 1003)   1C( 1003)   1B( 1002)  
  4  PCS   :     FREE   FREE   1F( 1006)   1D( 1004)   1D( 1004)   1C( 1003)  
  5  UCS   :     FREE   FREE   FREE   1E( 1005)   1E( 1005)   1D( 1004)  
  6  CCS   :     FREE   FREE   FREE   1F( 1006)   1F( 1006)   1E( 1005)  


Tuesday
********************************************
  1  ACS   :     1C( 1003)   1C( 1003)   FREE   1A( 1001)   1A( 1001)   1F( 1006)  
  2  ICS   :     1E( 1005)   1E( 1005)   1C( 1003)   1B( 1002)   1B( 1002)   1A( 1001)  
  3  JCS   :     1F( 1006)   1F( 1006)   1E( 1005)   1C( 1003)   1C( 1003)   1B( 1002)  
  4  PCS   :     FREE   FREE   1F( 1006)   1D( 1004)   1F( 1006)   1C( 1003)  
  5  UCS   :     FREE   FREE   FREE   1E( 1005)   1D( 1004)   1D( 1004)  
  6  CCS   :     FREE   FREE   FREE   1F( 1006)   1E( 1005)   1E( 1005)  


Wednesday
********************************************
  1  ACS   :     1B( 1002)   1B( 1002)   FREE   1A( 1001)   1F( 1006)   1F( 1006)  
  2  ICS   :     1E( 1005)   FREE   1B( 1002)   1C( 1003)   1C( 1003)   1A( 1001)  
  3  JCS   :     1F( 1006)   1E( 1005)   1E( 1005)   1B( 1002)   1B( 1002)   1C( 1003)  
  4  PCS   :     FREE   1F( 1006)   FREE   1D( 1004)   FREE   1B( 1002)  
  5  UCS   :     FREE   FREE   1F( 1006)   1E( 1005)   1D( 1004)   FREE  
  6  CCS   :     FREE   FREE   FREE   1F( 1006)   1E( 1005)   1D( 1004)  


Thursday
********************************************
  1  ACS   :     1A( 1001)   FREE   FREE   1B( 1002)   1B( 1002)   1E( 1005)  
  2  ICS   :     1E( 1005)   1A( 1001)   FREE   1C( 1003)   1F( 1006)   1F( 1006)  
  3  JCS   :     1F( 1006)   1E( 1005)   1A( 1001)   1D( 1004)   1D( 1004)   FREE  
  4  PCS   :     FREE   1F( 1006)   1E( 1005)   1A( 1001)   1A( 1001)   1C( 1003)  
  5  UCS   :     FREE   FREE   1F( 1006)   1E( 1005)   FREE   1A( 1001)  
  6  CCS   :     FREE   FREE   FREE   1F( 1006)   1E( 1005)   1D( 1004)  


Friday
********************************************
  1  ACS   :     1A( 1001)   FREE   FREE   1D( 1004)   1D( 1004)   1C( 1003)  
  2  ICS   :     1B( 1002)   1A( 1001)   FREE   1E( 1005)   FREE   1D( 1004)  
  3  JCS   :     1C( 1003)   1B( 1002)   1A( 1001)   1F( 1006)   1E( 1005)   1F( 1006)  
  4  PCS   :     1D( 1004)   1C( 1003)   1B( 1002)   1A( 1001)   1F( 1006)   1E( 1005)  
  5  UCS   :     FREE   1D( 1004)   1C( 1003)   1B( 1002)   1B( 1002)   1A( 1001)  
  6  CCS   :     FREE   FREE   1D( 1004)   1C( 1003)   1C( 1003)   1B( 1002)  


Saturday
********************************************
  1  ACS   :     1A( 1001)   FREE   FREE   1D( 1004)   1C( 1003)   FREE  
  2  ICS   :     1B( 1002)   1A( 1001)   FREE   1E( 1005)   1D( 1004)   1D( 1004)  
  3  JCS   :     1C( 1003)   1B( 1002)   1A( 1001)   FREE   1E( 1005)   FREE  
  4  PCS   :     1D( 1004)   1C( 1003)   1B( 1002)   1A( 1001)   FREE   1E( 1005)  
  5  UCS   :     FREE   1D( 1004)   1C( 1003)   1B( 1002)   1A( 1001)   FREE  
  6  CCS   :     FREE   FREE   1D( 1004)   1C( 1003)   1B( 1002)   1B( 1002)  

THIS DEPICTS A 6HR LONG TIMETABLE TO EACH FACLTY ON EACH DAY OF THE WEEK. 
FREE DEPICTS THAT IT IS A FREE CLASS 
THE CLASS NAME  AND ROOM NUMBER THAT HE HAS TO VISIT ARE MENTIONED AT THE HOUR SLOT 
EXAMPLE ::: 1F( 1006)

===============================================================================================================

LAB.TXT ( LAB TIMETABLE )


Monday
********************************************
   1  Year  
  MCLLRoom 1401   :    1A  1A  1A  0  0  0 
  JVLLRoom 1402   :    1B  1B  1B  0  0  0 
  CDLLRoom 1403   :    1C  1C  1C  0  0  0 

*****************************************


Tuesday
********************************************
   1  Year  
  MCLLRoom 1401   :    1B  1B  1B  0  0  0 
  JVLLRoom 1402   :    1A  1A  1A  0  0  0 
  CDLLRoom 1403   :    1D  1D  1D  0  0  0 

*****************************************


Wednesday
********************************************
   1  Year  
  MCLLRoom 1401   :    1C  1C  1C  0  0  0 
  JVLLRoom 1402   :    1D  1D  1D  0  0  0 
  CDLLRoom 1403   :    1A  1A  1A  0  0  0 

*****************************************


Thursday
********************************************
   1  Year  
  MCLLRoom 1401   :    1D  1D  1D  0  0  0 
  JVLLRoom 1402   :    1C  1C  1C  0  0  0 
  CDLLRoom 1403   :    1B  1B  1B  0  0  0 

*****************************************


Friday
********************************************
   1  Year  
  MCLLRoom 1401   :    1E  1E  1E  0  0  0 
  JVLLRoom 1402   :    1F  1F  1F  0  0  0 
  CDLLRoom 1403   :    0  0  0  0  0  0 

*****************************************


Saturday
********************************************
   1  Year  
  MCLLRoom 1401   :    1F  1F  1F  0  0  0 
  JVLLRoom 1402   :    1E  1E  1E  0  0  0 
  CDLLRoom 1403   :    0  0  0  1F  1F  1F 

*****************************************
THIS TIMETABLE SERVES THE PURPOSE OF LAB FACULTY . IT SHOWS THE CLASS NAME THAT ARE GOING TO ATTEND THE LAB AT A PARTICULAR HOUR.
0'S DEPICT FREE HOUR.


THE LAB FACULTY OR THE REGULAR FACULTY WITH A FREE PERIOD CAN BE USED AS A BACK UP FACULTY. 
THIS CAN BE ADDED TO THE CODE AS WELL. WILL TRY ADDING IT .
'''
