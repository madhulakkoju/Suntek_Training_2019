import numpy as np
print ('Hello World')
n = 8
a=np.array([[0,0,1,1,0,0,0,0],[1,1,1,1,1,1,0,0],[0,0,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,0,0,1,1,1,1,1],[0,1,0,1,0,0,0,1],[0,0,0,1,0,0,0,0],[0,0,0,1,0,0,0,0]])
visit = np.zeros((8,8),dtype=np.int)
siz = 0
def check(x,y,typ):
  if(x<0 or x>=n  or y>=n or y<0 ):
    return 0
  if(a[x][y]==0):
    return -1
  elif(typ==1):
    return 1+check(x,y-1,typ)
  elif(typ==2):
    return 1+check(x+1,y,typ)
  elif(typ==3):
    return 1+check(x,y+1,typ)
  elif(typ==4):
    return 1+check(x-1,y,typ)
def recursioncheck(x,y):
  if(x<0 or x>=n  or y>=n or y<0 ):
    return 
  if(visit[x][y] != 0):
    return
  g = min(check(x,y,1),check(x,y,2),check(x,y,3),check(x,y,4))
  global siz
  if(siz < g):
    siz = g
  visit[x][y] = 1
  recursioncheck(x-1,y)
  recursioncheck(x+1,y)
  recursioncheck(x,y+1)
  recursioncheck(x,y-1)
  return
print(a)
recursioncheck(4,4)
print((siz - 1)*4 + 1)
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
