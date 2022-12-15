
from collections import deque
from collections import defaultdict

for testcase in range(int(input())):
    string=str(input())

    dic=defaultdict(list)

    for j in range(len(string)):
        dic[ord(string[j])-ord('a')+1].append(j+1)
    
    l=(ord(string[0])-ord('a')+1)
    r=(ord(string[-1])-ord('a')+1)
    
    ans=[]

    if l<r:
        for i in range(l,r+1):
            if i in dic:
                ans+=dic[i]
    else:
        for k in range(l,r-1,-1):
            if k in dic:
                ans+=dic[k]

    print(abs(ord(string[0])-ord(string[-1])),len(ans))
    print(*ans)