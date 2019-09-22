'''
The timetable by this program might be built in keeping in mind some assumptions.

The Faculty are assumed to be teaching a single subject to all the sections of same year students.
The Faculty are assumed to be distinct for LAB and SUBJECTS .
The Maximum number of sections allowed for one year is 12
the lab frequency is taken as 1 directly, to serve purpose of maximizing the subject classes . 
If there is any change, the frequency can be input to meet our needs.

Assuming the details given are intact, we are not checking for the repetitions and authentications. 
Keeping in mind, the time and space overhead
This program works for different years classes. The output format is typical. 
The output given is in files.
A day's data defines the classes that faculty must attend and 0 for free hour.  ===  In Fac file
'''
f0 = open("cls.txt","a")
f1 = open("fac.txt","a")
f2 = open("lab.txt","a")
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
for i in range(0,year_count):
  print("year " + str(i+1))
  x=[]
  for j in range(0,lab_count):
    x.append(input("Lab name : "))
  lab_names.append(list(x))
lab_check = np.zeros((year_count*sections_count,lab_count),dtype=np.int)
lab_hr =np.zeros((year_count,lab_count,hrs),dtype='object')
lab_freq = 1
lab_time=int(input("How many hours of lab per each session : "))
for i in range(0,year_count):
  for j in range(0,sections_count):
    classes.append(str(i+1)+str(sec[j]))
sub_count = int(input("count of Subjects to each year's classes ? ")) 
week_classes= hrs*6 - lab_freq*lab_time*lab_count
sub_names=[]
x=[]
for ii in range(0,year_count):
  print(" year "+ str(ii+1))
  x=[]
  for jj in range(0,sub_count):
    x.append(input("Subject name :  "))
  sub_names.append(list(x))
sub_div = []
div=[]
for i in range(0,sub_count):
	div.append(week_classes//sub_count)
for i in range(0,week_classes % sub_count):
	div[i]=div[i]+1
for i in range(0,class_count):
  sub_div.append(list(div))
def get_faculty(id_f ):
  f_name = input("Faculty Name : ")
  f_yr_count = int(input("How many years students does he deal ?  "))
  y=[]
  sub=[]
  for gg in range(0,f_yr_count):
    y.append(int(input(" which yr : ")))
    sub.append(input("subject : "))
  f_class_count = int(input("How many sections / classes on the whole should he attend ?:"))
  f_classes =[]
  print("Enter class in form of 3A for third year A section ")
  for i in range(0,f_class_count):
    f_classes.append(input("Which class  "))
  f_details.append([int(id_f),f_name,f_class_count,f_classes,y,sub])
f_count = int(input("How many faculty ?  "))
for k in range(0,f_count):
  get_faculty(k+1)
print(f_details)
f_hr = np.zeros((f_count,hrs),dtype='object')
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
    f0.write(" " + str(class_name) +"    :   ")
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
              f0.write(lab_names[yr_c][la]) 
            else:
              f0.write("   ")
          lab_check[cl][la] = lab_check[cl][la] + 1
          #break
      for fc in range(0,f_count):
        if(left <= 0):
          break
        if(class_name in f_details[fc][3] and years[yr_c] in f_details[fc][4] and f_hr[fc][hrs - left]==0 ):
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
          else:
            sub_div[cl][ind] = sub_div[cl][ind] - 1
            f_hr[fc][hrs-left] = class_name
            f0.write(" "+su+" ")
            left = left - 1
    f0.write("\n")
    sec_c = sec_c + 1
  f0.write("\n******************************\n")
  print(f_hr)
  print(lab_hr)
  print(" ")
  for ghij in range(0,f_count):
    f1.write("  " + str(f_details[ghij][0]) + "  " + str(f_details[ghij][1])+"   :    ")
    for ghi in range(0,hrs):
      f1.write(" " +str(f_hr[ghij][ghi])+" ")
    f1.write("\n")
  for ghij in range(0,year_count):
    f2.write("   " + str(ghij+1)+"  Year  \n")
    for ghi in range(0,lab_count):
      f2.write("  " + str(lab_names[ghi])+ "   :   "
      for gh in range(0,hrs):
        f2.write(" "+str(lab_hr[ghij][ghi][gh])+" ")
      f2.write("\n")
    f2.write("\n\n")
f0.close()        
f1.close()
f2.close()

'''
Input for one year classes Time table ::::

How many years ?1
Enter the yeasrs considered in Ascending order please.
Which year : 1
How many sections in each year ? 6
How many hours per day ?  6
how many labs to each year ? 3
year 1
Lab name : CDLL
Lab name : MCLL
Lab name : JVLL
How many hours of lab per each session : 3
count of Subjects to each year's classes ? 6
 year 1
Subject name :  AINN
Subject name :  JAVA
Subject name :  CNET
Subject name :  UNIX
Subject name :  IOTS
Subject name :  PYTH
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

*********************************************************
OUTPUT FORMAT  :::::::::::
___________ FOR CLASSES : ____________________
ROWS depict the  sections in order A--B--C--D-- so on
COLUMNS depict hours in day's working
Monday
********************************************
   CDLL    AINN  AINN  JAVA 
   MCLL    JAVA  JAVA  CNET 
   JVLL    CNET  CNET  UNIX 
 AINN  AINN  JAVA  UNIX  UNIX  IOTS 
 JAVA  JAVA  CNET  IOTS  IOTS  PYTH 
 CNET  CNET  UNIX  PYTH  PYTH  AINN 

******************************


Tuesday
********************************************
   MCLL    AINN  AINN  JAVA 
   CDLL    JAVA  JAVA  CNET 
 AINN  AINN  JAVA  CNET  CNET  UNIX 
   JVLL    UNIX  IOTS  IOTS 
 JAVA  JAVA  CNET  IOTS  PYTH  PYTH 
 CNET  CNET  UNIX  PYTH  UNIX  AINN 

******************************


Wednesday
********************************************
   JVLL    AINN  JAVA  JAVA 
 AINN  AINN  JAVA  CNET  CNET  UNIX 
   CDLL    JAVA  JAVA  CNET 
   MCLL    UNIX  IOTS  PYTH 
 JAVA  CNET  CNET  IOTS  PYTH  AINN 
 CNET  UNIX  IOTS  PYTH  AINN  AINN 

******************************


Thursday
********************************************
 AINN  JAVA  CNET  UNIX  UNIX  IOTS 
   JVLL    AINN  AINN  JAVA 
   MCLL    JAVA  CNET  UNIX 
   CDLL    CNET  CNET  PYTH 
 JAVA  CNET  UNIX  IOTS  PYTH  AINN 
 CNET  UNIX  IOTS  PYTH  JAVA  JAVA 

******************************


Friday
********************************************
 AINN  JAVA  CNET  UNIX  IOTS  IOTS 
 JAVA  CNET  UNIX  IOTS  IOTS  PYTH 
 CNET  UNIX  IOTS  PYTH  PYTH  AINN 
 UNIX  IOTS  PYTH  AINN  AINN  JAVA 
   CDLL    JAVA  CNET  UNIX 
   MCLL    CNET  UNIX  CNET 

******************************


Saturday
********************************************
 AINN  JAVA  CNET  UNIX  IOTS  PYTH 
 JAVA  CNET  UNIX  IOTS  PYTH  PYTH 
 CNET  UNIX  IOTS  PYTH  AINN  JAVA 
 UNIX  IOTS  PYTH  AINN  JAVA  JAVA 
   MCLL    JAVA  CNET  UNIX 
   CDLL    CNET  UNIX  IOTS 

******************************
______________  FOR FACULTY :::::::: ________
ROWS depict the class - section names that the faculty with ID as row number has to attend
Columns depict hours 
0's depict FREE HOURS

Monday
********************************************
 1D  1D  0  1A  1A  1F 
 1E  1E  1D  1B  1B  1A 
 1F  1F  1E  1C  1C  1B 
 0  0  1F  1D  1D  1C 
 0  0  0  1E  1E  1D 
 0  0  0  1F  1F  1E 


Tuesday
********************************************
 1C  1C  0  1A  1A  1F 
 1E  1E  1C  1B  1B  1A 
 1F  1F  1E  1C  1C  1B 
 0  0  1F  1D  1F  1C 
 0  0  0  1E  1D  1D 
 0  0  0  1F  1E  1E 


Wednesday
********************************************
 1B  1B  0  1A  1F  1F 
 1E  0  1B  1C  1C  1A 
 1F  1E  1E  1B  1B  1C 
 0  1F  0  1D  0  1B 
 0  0  1F  1E  1D  0 
 0  0  0  1F  1E  1D 


Thursday
********************************************
 1A  0  0  1B  1B  1E 
 1E  1A  0  1C  1F  1F 
 1F  1E  1A  1D  1D  0 
 0  1F  1E  1A  1A  1C 
 0  0  1F  1E  0  1A 
 0  0  0  1F  1E  1D 


Friday
********************************************
 1A  0  0  1D  1D  1C 
 1B  1A  0  1E  0  1D 
 1C  1B  1A  1F  1E  1F 
 1D  1C  1B  1A  1F  1E 
 0  1D  1C  1B  1B  1A 
 0  0  1D  1C  1C  1B 


Saturday
********************************************
 1A  0  0  1D  1C  0 
 1B  1A  0  1E  1D  1D 
 1C  1B  1A  1F  1E  0 
 1D  1C  1B  1A  1F  1E 
 0  1D  1C  1B  1A  1F 
 0  0  1D  1C  1B  1B 
******************************

____________ FOR LABS ____________-
ROWS Depict the the classes that attend the LAB at a point of time in a day
0's depict free hours of lab 


Monday
********************************************
 1A  1A  1A  0  0  0 
 1B  1B  1B  0  0  0 
 1C  1C  1C  0  0  0 




Tuesday
********************************************
 1B  1B  1B  0  0  0 
 1A  1A  1A  0  0  0 
 1D  1D  1D  0  0  0 




Wednesday
********************************************
 1C  1C  1C  0  0  0 
 1D  1D  1D  0  0  0 
 1A  1A  1A  0  0  0 




Thursday
********************************************
 1D  1D  1D  0  0  0 
 1C  1C  1C  0  0  0 
 1B  1B  1B  0  0  0 




Friday
********************************************
 1E  1E  1E  0  0  0 
 1F  1F  1F  0  0  0 
 0  0  0  0  0  0 




Saturday
********************************************
 1F  1F  1F  0  0  0 
 1E  1E  1E  0  0  0 
 0  0  0  0  0  0 

--------------------------------------------------------------------
PREFERENCES are not taken in this program. 
Will Try attempting in the next program 


'''

