'''
Word Break Problem 
Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.
This is a famous Google interview question, also being asked by many other companies now a days.

Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes 
The string can be segmented as "i like".

Input:  ilikesamsung
Output: ======= ALL POSSIBLE WORDS - Break Sentences ===
The string can be segmented as "i like samsung" 
or "i like sam sung".

'''



def wordbreak(op,i,s,d):
  s1 = s
  if(s1.replace(" ","")== op):
    print(s)
    return
  use=[]
  for x in d:
    if( x in op and x[0]==op[i]   ):
      use.append(x)
  for x in use:
    wordbreak(op,i +len(x),s+x+" ",d)
  return
  
d=["word","b","br","brea","bre","break","bike","this","r","e","a","k","ak","problem"]
d.sort()
wordbreak("wordbreakproblem",0,"",d )


'''
OUTPUT :::

word b r e a k problem 
word b r e ak problem 
word br e a k problem 
word br e ak problem 
word bre a k problem 
word bre ak problem 
word brea k problem 
word break problem 



'''
