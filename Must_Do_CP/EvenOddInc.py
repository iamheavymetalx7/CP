import sys
import math, itertools, collections
##dictionary
sys.stdin=open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')
sys.stdout=open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')
'''

for test in range(int(input())):
    n=int(input())
    a1 = [*map(int, input().split())]
    string=str(input())
    a2=[s for s in string]

    dic = collections.defaultdict(set)
    for i in range(len(a1)):
        dic[a2[i]].add(a1[i])

    print(dic)

    def common_member(a, b):
        a_set = set(a)
        b_set = set(b)
        if (a_set & b_set):
            return True 
        else:
            return False

    dic_list = list(dic)

    def solve(): 
        for i in range(len(dic)):
            for j in range(i+1, len(dic)):

                if common_member(dic[dic_list[i]],dic[dic_list[j]]):
                    return "NO"
                else:
                    return "YES"

    if len(dic)==1:
        print("YES")
    else:
        print(solve())
'''
for _ in range (int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    s = input().strip()
    dic = {}
    res = []
    for i in range (n):
        if a[i] not in dic:
            dic[a[i]] = s[i]
        res.append(dic[a[i]])
    print(res)
    if res!=list(s):
        print("NO")
    else:
        print("YES")