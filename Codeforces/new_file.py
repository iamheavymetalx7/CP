import math
mx = 10**6
spf = [False,False]+[True for i in range(mx)]
for i in range(2,int(math.sqrt(mx))+1):
    if spf[i]==True:
        for j in range(i*i,mx+1,i):
            spf[j]=False

p=[]

for i in range(len(spf)):
    if spf[i]:
        p.append(i)
p.sort()
n=len(p)

cnt=0
from bisect import bisect_left, bisect_right
N =int(input())

idx=bisect_right(p,N)


# x^y^z=0
# 2^y^z=0
# z= 2^y
a=[]
for i in range(1,idx):
    z= 2^p[i]
    if (2<p[i]<z or 2<z<p[i]) and z<=N:
        cnt+=1
        a.append([2,p[i],z])
print(cnt)
print(a)