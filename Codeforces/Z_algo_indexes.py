
from collections import Counter, defaultdict, deque

def zfunc(st):
    n=len(st)
    z = [0 for _ in range(n)]
    l,r=0,0
    for i in range(1,n):

        if i<=r:
            z[i]= min(r-i+1,z[0+i-l])



        while (i+z[i]<n and st[z[i]]==st[i+z[i]]):
            z[i]+=1
        
        if z[i]+i-1>r:
            l=i
            r=z[i]+i-1
    return z 
s=input()
p=input()
st = p+"$"+s
print(st)
lenp,lens=len(p),len(s)
z_arr = zfunc(st)




for i in range(len(st)):
    if z_arr[i]==lenp:
        print(i-lenp-1)