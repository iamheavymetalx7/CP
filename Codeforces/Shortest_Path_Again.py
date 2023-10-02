# # /**
# # * author:Hisoka-TheMagician
# # * created: 01/09/2023 19:53 Chennai, India
# # **/
        




                                                                                                                        

# from __future__ import division, print_function

# import os,sys
# #sys.setrecursionlimit(9*10**8)
# from io import BytesIO, IOBase

# if sys.version_info[0] < 3:
#     from __builtin__ import xrange as range
#     from future_builtins import ascii, filter, hex, map, oct, zip

# from bisect import bisect_left as lower_bound, bisect_right as upper_bound 

# from math import sqrt
# def lmii():
#     return list(map(int,input().split()))

# def ii():
#     return int(input())

# def si():
#     return str(input())
# def lmsi():
#     return list(map(str,input().split()))
# def mii():
#     return map(int,input().split())

# def msi():
#     return map(str,input().split())

# i2c = lambda n: chr(ord('a') + n)
# c2i = lambda c: ord(c) - ord('a')

# import threading
# def dmain():
#     sys.setrecursionlimit(1000000)
#     threading.stack_size(1024000)
#     thread = threading.Thread(target=main)
#     thread.start()


# def joro(L):
#     return(''.join(map(str, L)))


# def decimalToBinary(n): return bin(n).replace("0b","")


# def isprime(n):
#     for i in range(2,int(n**0.5)+1):
#         if n%i==0:
#             return False
#     return True

 
 
# def SieveOfEratosthenes(n):
#     prime = [True for i in range(n + 1)]
#     p = 2
#     li = []
#     while (p * p <= n):
#         if (prime[p] == True):
#             for i in range(p * p, n + 1, p):
#                 prime[i] = False
#         p += 1
 
#     for p in range(2, len(prime)):
#         if prime[p]:
#             li.append(p)
#     return li
 
 
# def primefactors(n):
#     factors = []
#     while (n % 2 == 0):
#         factors.append(2)
#         n //= 2
#     for i in range(3, int(sqrt(n)) + 1, 2):  # only odd factors left
#         while n % i == 0:
#             factors.append(i)
#             n //= i
#     if n > 2:  # incase of prime
#         factors.append(n)
#     return factors
         
    
# from os import path
# def read():
#      if (path.exists('input.txt')):
#         sys.stdin  = open('input.txt', 'r')  
#         sys.stdout = open('output.txt', 'w') 
 
# def tr(n):
#     return n*(n+1)//2


        
# from collections import Counter, defaultdict, deque
# from heapq import *
# def solve():
#     import sys
#     input =sys.stdin.buffer.readline

#     n,m=mii()

#     to =[[] for _ in range(n)]
#     inf = int(1e19)

#     dic=defaultdict(int)
#     for _ in range(m):
#         u,v,c = mii()
#         u-=1
#         v-=1
#         if (u,v) not in dic and (v,u) not in dic:
#             dic[(u,v)]=c
#         else:
#             if (u,v) in dic:
#                 val = dic[(u,v)]
#                 dic[(u,v)]=min(val,c)
#             else:
#                 val = dic[(v,u)]
#                 dic[(v,u)]=min(val,c)
    
#     for key,v in dic.items():
#         a,b = key
#         to[a].append([b,v])
#         to[b].append([a,v])
#     # print(to)
  
#     mx = 3002

#     dd = [[inf]*(mx) for _ in range(mx)]

#     hp =[]
#     src =0

#     dd[src][0]=0
#     heappush(hp,[0,0,src])    #dis,cur,nd
#     cnt =0
#     print(to)
#     while hp:
#         print(len(hp),"szzzz")
#         dis,cur,u = heappop(hp)
#         print(dis,cur,u)

#         if cur>=n or dis>dd[u][cur]:
#             continue





#         for v,cost in to[u]:
#             if u==v:
#                 continue
#             nd = dis+cost*(cur+1)


#             if (cur)>=n or nd>=dd[v][cur+1]:
#                 continue
#             print(nd,cur+1,v,"going innnn")
#             dd[v][cur+1] = nd
#             heappush(hp,[nd,cur+1,v])

#     for i in range(n):
#         u = min(dd[i])
#         if u==inf:
#             print(-1)
#         else:
#             print(u)





    

    
    

    
    
        
            
            
# def main():
#     # for i in range(ii()):
#         solve()
                
            
                
                
                
                
            
    
            
            
    
    
    
    
        
            
    
            
            
            
        
    
        
    
    
        
        
        

            
                    
                
                    
                    
                    
                    
                    
                    
        
                
        
        
       
    
           
          
          
                
            
        
                
    
        
        
        
       
            
                
        




# # region fastio
# # template taken from https://github.com/cheran-senthil/PyRival/blob/master/templates/template.py

# BUFSIZE = 8192


# class FastIO(IOBase):
#     newlines = 0

#     def __init__(self, file):
#         self._fd = file.fileno()
#         self.buffer = BytesIO()
#         self.writable = "x" in file.mode or "r" not in file.mode
#         self.write = self.buffer.write if self.writable else None

#     def read(self):
#         while True:
#             b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
#             if not b:
#                 break
#             ptr = self.buffer.tell()
#             self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
#         self.newlines = 0
#         return self.buffer.read()

#     def readline(self):
#         while self.newlines == 0:
#             b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
#             self.newlines = b.count(b"\n") + (not b)
#             ptr = self.buffer.tell()
#             self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
#         self.newlines -= 1
#         return self.buffer.readline()

#     def flush(self):
#         if self.writable:
#             os.write(self._fd, self.buffer.getvalue())
#             self.buffer.truncate(0), self.buffer.seek(0)


# class IOWrapper(IOBase):
#     def __init__(self, file):
#         self.buffer = FastIO(file)
#         self.flush = self.buffer.flush
#         self.writable = self.buffer.writable
#         self.write = lambda s: self.buffer.write(s.encode("ascii"))
#         self.read = lambda: self.buffer.read().decode("ascii")
#         self.readline = lambda: self.buffer.readline().decode("ascii")


# def print(*args, **kwargs):
#     """Prints the values to a stream, or to sys.stdout by default."""
#     sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
#     at_start = True
#     for x in args:
#         if not at_start:
#             file.write(sep)
#         file.write(str(x))
#         at_start = False
#     file.write(kwargs.pop("end", "\n"))
#     if kwargs.pop("flush", False):
#         file.flush()


# if sys.version_info[0] < 3:
#     sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
# else:
#     sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

# input = lambda: sys.stdin.readline().rstrip("\r\n")

# # endregion


# if __name__ == "__main__":
#     read()
#     main()
# #     #dmain()

# Comment Read()


from __future__ import print_function
n,m=map(int, input().split())
edges = []
for i in range(m):
    a,b,c=map(int, input().split())
    a-=1
    b-=1
    edges.append((a,b,c))
dp = [float('inf') for i in range(n)]
dp[0]=0
ans= [float('inf')]*n
ans[0]=0
for j in range(1,n):
    newdp = [float('inf')]*n
    for s,e,c in edges:
        newdp[s]=min(newdp[s], j*c+dp[e])
        newdp[e]=min(newdp[e], j*c+dp[s])
    for i in range(n):
        ans[i]=min(ans[i], newdp[i])
    dp=newdp
for i in range(n):
    u=ans[i]
    if u==float('inf'):
        print(-1)
    else:
        print(u)