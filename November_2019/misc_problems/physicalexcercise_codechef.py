'''
Chef decided to exercise by running somewhere from ShareChat. He chose three sets of points in a plane:

A set of N points (numbered 1 through N): for each valid i, the i-th of them has coordinates (ai,bi).
A set of M points (numbered 1 through M): for each valid i, the i-th of them has coordinates (ci,di).
A set of K points (numbered 1 through K): for each valid i, the i-th of them has coordinates (ei,fi).
ShareChat has coordinates (x,y). Chef must choose one point (aj,bj), one point (ck,dk), and one point (el,fl). Then, he starts running from ShareChat, visits the chosen points (aj,bj) and (ck,dk) in any order, and then runs to the point (el,fl), where he finishes his run.

Help Chef find the minimum distance he has to run.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers x and y.
The second line contains three space-separated integers N, M and K.
The third line contains 2N space-separated integers a1,b1,a2,b2,…,aN,bN.
The fourth line contains 2M space-separated integers c1,d1,c2,d2,…,cM,dM.
The fifth line contains 2K space-separated integers e1,f1,e2,f2,…,eK,fK.
Output
For each test case, print a single line containing one real number ― the minimum distance.

Your answer will be considered correct if its absolute or relative error does not exceed 10−6.

Constraints
1≤T≤5,000
1≤N,M,K≤5,000
0≤x,y≤109
0≤ai,bi≤109 for each valid i
0≤ci,di≤109 for each valid i
0≤ei,fi≤109 for each valid i
the sum of N+M+K over all test cases does not exceed 15,000
Subtasks
Subtask #1 (50 points): 1≤N,M,K≤100
Subtask #2 (50 points): original constraints

Example Input
2
1 4
3 2 2
4 4 2 0 8 1
10 1 3 1
1 3 9 5
6 4
2 2 3
7 10 5 7
1 6 2 3
1 8 0 7 0 2
Example Output
8.1820424980
8.6995968482
Explanation
Example case 1:



The black point is ShareChat,
Points from the first set are red.
Points from the second set are green.
Points from the third set are blue.
The black line corresponds to Chef's run.
Chef should run from (1,4) to (3,1), then to (2,0) and then to (1,3). The distance is 13−−√+2–√+10−−√≐8.1820424980.

Example case 2:



Chef should run from (6,4) to (5,7), then to (1,6) and then to (0,7). The distance is 10−−√+17−−√+2–√≐8.6995968482.


'''
import math

def dist(x,y,a,b):
    return math.sqrt((x-a)*(x-a)+(y-b)*(y-b))

t = int(input())
for tt in range(0,t):
    x,y = map(int,input().split())
    n,m,k = map(int,input().split())
    test = list(map(int,input().split()))
    np1=[]
    np2=[]
    for i in range(0,len(test)):
        if i%2 == 0:
            np1.append(test[i])
        else :
            np2.append(test[i])
    #print(np1)
    #print(np2)
    test = list(map(int,input().split()))
    mp1=[]
    mp2=[]
    for i in range(0,len(test)):
        if i%2 == 0:
            mp1.append(test[i])
        else :
            mp2.append(test[i])
    #print(mp1)
    #print(mp2)
    test = list(map(int,input().split()))
    kp1=[]
    kp2=[]
    for i in range(0,len(test)):
        if i%2 == 0:
            kp1.append(test[i])
        else :
            kp2.append(test[i])
    #print(kp1)
    #print(kp2)
    g =0.0
    min = 9999.999
    for i in range(0,n):
        g = dist(x,y,np1[i],np2[i])
        for j in range(0,m):
            aa = g + dist(np1[i],np2[i],mp1[j],mp2[j])
            for h in range(0,k):
                bb = aa + dist(mp1[j],mp2[j],kp1[h],kp2[h])
                if bb<min:
                    min = bb
                #--------------------------------------
    for i in range(0,m):
        g = dist(x,y,mp1[i],mp2[i])
        for j in range(0,n):
            
            aa = g + dist(mp1[i],mp2[i],np1[j],np2[j])
            for h in range(0,k):
                
                bb = aa + dist(np1[j],np2[j],kp1[h],kp2[h])
                if bb<min:
                    min = bb
                #--------------------------------------
        
    print(round(min,10))
    
    
    
    
