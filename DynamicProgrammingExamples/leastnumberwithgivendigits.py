def create(x,n):
  s=[]
  x.sort()
  s.extend(x)
  i=0
  while True:
    i=i+1
    if i > 150:
      return -1
    a = s.pop(0)
    for g in x:
      s.append(int(str(a)+str(g)))
      if(s[-1]%n==0):
        return s[-1]
m = int(input())
x= input().split(' ')
y=[]
for xx in x:
  y.append(int(xx))
n = int(input())
print(create(y,n))
