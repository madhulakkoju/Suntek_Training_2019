roman ={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
n=input()
l=[]
for x in range(0,len(n)):
  if(len(l)==0):
    l.append(roman[n[x]])
    continue
  val = roman[n[x]]
  while True:
    if(len(l)==0):
      break
    if(l[-1]<roman[n[x]]):
      val = val - l[-1]
      l.pop()
    else:
      break
  l.append(val)
print(sum(l))
      
