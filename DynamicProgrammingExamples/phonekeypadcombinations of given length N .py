
'''

refer
https://www.techiedelight.com/count-total-possible-combinations-n-digit-numbers-mobile-keypad/
'''

a=[['1','2','3'],['4','5','6'],['7','8','9'],["-1",'0',"-1"]]
com=[]
def move(x,y):
  if(x>3 or y>2):
    return
  if(a[x][y] == -1):
    return
  s=""
  make(x,y,n,s)
  
  move(x,y+1)
  move(x+1,y)
  
  return
  
def make(x,y,l,s):
  if(x>3 or y>2):
    return
  if(x<0 or y<0):
    return
  if a[x][y] == "-1":
    return
  s= s+ a[x][y]
  if(l==1):
    #print(s)
    com.append(s)
    return
  make(x,y,l-1,s)
  make(x,y+1,l-1,s)
  make(x+1,y,l-1,s)
  make(x-1,y,l-1,s)
  make(x,y-1,l-1,s)
  
  return
n=int(input())
move(0,0)
com = list(set(com))
com.sort()
print(com)
