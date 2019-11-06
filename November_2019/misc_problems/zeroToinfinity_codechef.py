'''

Alice and Bob created N and M recipes, respectively (N,M≥1), and submitted them to Chef for evaluation. Each recipe is represented by a string containing only lowercase English letters. Let's denote Alice's recipes by A1,A2,…,AN and Bob's recipes by B1,B2,…,BM.

Accidentally, Chef mixed up those recipes ― now, he has L=N+M recipes in a sequence S1,S2,…,SL. Thankfully, the recipes created by Alice and Bob are distinguishable from each other. It is well-known that for each recipe s created by Alice, the following property holds, and for each recipe created by Bob, it does not hold: For each 1≤l<r≤|s|, the substring sl,sl+1,…,sr contains at least as many vowels as consonants. The letters 'a', 'e', 'i', 'o', 'u' are vowels, while the other letters are consonants.

The score of a candidate who made K recipes is calculated as the product of xcfxKc for all letters c that occur in at least one of these recipes; here, xc is the number of recipes which contain the letter c and fxc is the total number of occurrences of this letter in all K recipes.

Let's denote the scores of Alice and Bob by scA and scB respectively. Chef wants to know their ratio scA/scB. We know that Chef is a legendary cook, but he is not very good at calculating, so he is asking you to find that number.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer L.
L lines follow. For each valid i, the i-th of these lines contains a single string Si.
Output
For each test case, if the ratio of scores exceeds 107, print a single line containing the string "Infinity" (without quotes); otherwise, print a single line containing one real number scA/scB.

Your answer will be considered correct if its absolute or relative error does not exceed 10−6. It is guaranteed that scA/scB does not lie in the range 107±10.

Constraints
1≤T≤105
2≤L≤105
2≤|Si|≤105 for each valid i
for each valid i, Si contains only lowercase English letters
the sum of |S1|+|S2|+…+|SL| over all test cases does not exceed 107
Subtasks
Subtask #1 (25 points):

L≤10
|Si|≤10 for each valid i
Subtask #2 (75 points): original constraints

Example Input
2
4
aba
abc
bab
aac
3
aba
baab
abc
Example Output
1.1250000
0.0277778
Explanation
Example case 1: The recipes "aba" and "aac" are created by Alice, while the recipes "abc" and "bab" are created by Bob. The scores are:

scA=xafxNa⋅xbfxNb⋅xcfxNc=242⋅112⋅112=18
scB=xafxMa⋅xbfxMb⋅xcfxMc=222⋅232⋅112=19
scAscB=1/81/9=1.125


'''

t = int(input())
for test in range(0,t):
    l = int(input())
    s=[]
    sa = []
    sb = []
    for i in range(0,l):
        s.append(input())
    for i in range(0,l):
        cstr = s[i]
        vow = 0
        con = 0
        for j in range(0,len(cstr)):
            if cstr[j] in ['a','e','o','i','u']:
                vow = vow + 1
            else: 
                con = con + 1
        if(vow >= con):
            sa.append(cstr)
        else :
            sb.append(cstr)
    check = []    # fx
    check_cnt =[]
    for i in range(0,len(sa)):
        for xy  in sa[i]:
            if xy not in check :
                check.append(xy)
                check_cnt.append(1)
            else:
                check_cnt[check.index(xy)] = check_cnt[check.index(xy)] + 1
    check_x = []
    for i in check:
        gg = 0
        for j in sa:
            if i in j:
                gg = gg +1
        check_x.append(gg)
    sca = 1.000
    for i in range(0,len(check_x)):
      sca = sca * (check_x[i]/pow(check_cnt[i],len(sa)))
    check2 = []
    check2_cnt=[]
    for i in range(0,len(sb)):
        for xy  in sb[i]:
            if xy not in check2 :
                check2.append(xy)
                check2_cnt.append(1)
            else:
                check2_cnt[check2.index(xy)] = check2_cnt[check2.index(xy)] + 1
    check2_x=[]
    for i in check2:
        gg =0
        for j in sb:
            if i in j:
                gg = gg +1
        check2_x.append(gg)
    scb = 1.000
    for i in range(0,len(check2_x)):
        scb = scb * (check2_x[i]/pow(check2_cnt[i],len(sb)))
    val = sca/scb
    if(val >pow(10,7)):
      print("Infinity")
    else:
      print("%9.7f" %(val))
                
        
            
        
