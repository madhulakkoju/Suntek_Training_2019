'''

This problem is different from the hard version. In this version Ujan makes exactly one exchange. You can hack this problem only if you solve both problems.

After struggling and failing many times, Ujan decided to try to clean up his house again. He decided to get his strings in order first.

Ujan has two distinct strings s and t of length n consisting of only of lowercase English characters. He wants to make them equal. Since Ujan is lazy, he will perform the following operation exactly once: he takes two positions i and j (1≤i,j≤n, the values i and j can be equal or different), and swaps the characters si and tj. Can he succeed?

Note that he has to perform this operation exactly once. He has to perform this operation.

Input
The first line contains a single integer k (1≤k≤10), the number of test cases.

For each of the test cases, the first line contains a single integer n (2≤n≤104), the length of the strings s and t.

Each of the next two lines contains the strings s and t, each having length exactly n. The strings consist only of lowercase English letters. It is guaranteed that strings are different.

Output
For each test case, output "Yes" if Ujan can make the two strings equal and "No" otherwise.

You can print each letter in any case (upper or lower).

Example
inputCopy
4
5
souse
houhe
3
cat
dog
2
aa
az
3
abc
bca
outputCopy
Yes
No
No
No
Note
In the first test case, Ujan can swap characters s1 and t4, obtaining the word "house".

In the second test case, it is not possible to make the strings equal using exactly one swap of si and tj.


'''



t = int(input())
for ii in range(0,t):
    n = int(input())
    a = input()
    b = input()
    flag =0
    gflag =0
    for i in range(0,n):
        if(flag == 0 and a[i]!=b[i]):
            flag = 1
            aa = a[i]
            bb = b[i]
        elif(flag ==1 and a[i] != b[i]):
            if(a[i]==aa and b[i]==bb):
                continue
            else:
                gflag =1
                break
    if(gflag==0):
        if(a.replace(aa,bb)==b):
            print("Yes")
        else:
            print("No")
    else:
        print("No")
