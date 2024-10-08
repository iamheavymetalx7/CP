## this users' code gets accepted:e4q2pfnq 


# # /**
# # * author:Hisoka-TheMagician
# # * created: 09/08/2023 15:18 Chennai, India
# # **/
        
from collections import defaultdict

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        group_members = defaultdict(list)
        for member in range(self.n):
            group_members[self.find(member)].append(member)
        return group_members

    def __str__(self):
        return '\n'.join(f'{r}: {m}' for r, m in self.all_group_members().items())



N, M = map(int, input().split())
OX = list(map(int, input().split()))
OY = list(map(int, input().split()))

OE = []
for _ in range(M):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    OE.append((a, b, c))

ans = float("inf")
for tp in range(4):
    if tp == 0:
        E = OE
        Z = N
    elif tp == 1:
        X = [(i, N, x) for i, x in enumerate(OX)]
        E = OE + X
        Z = N + 1
    elif tp == 2:
        Y = [(i, N, y) for i, y in enumerate(OY)]
        E = OE + Y
        Z = N + 1
    else:
        X = [(i, N, x) for i, x in enumerate(OX)]
        Y = [(i, N+1, y) for i, y in enumerate(OY)]
        E = OE + X + Y
        Z = N + 2
    
    tmp = 0
    E.sort(key=lambda x:x[2])
    uf = UnionFind(Z)
    for a, b, c in E:
        if uf.same(a, b):
            continue
        tmp += c
        uf.union(a, b)
    
    if uf.group_count() == 1:
        ans = min(ans, tmp)

print(ans)
    
    









                                                                                                                        

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


# from types import GeneratorType
# def bootstrap(f, stack=[]):
#     def wrappedfunc(*args, **kwargs):
#         if stack:
#             return f(*args, **kwargs)
#         else:
#             to = f(*args, **kwargs)
#             while True:
#                 if type(to) is GeneratorType:
#                     stack.append(to)
#                     to = next(to)
#                 else:
#                     stack.pop()
#                     if not stack:
#                         break
#                     to = stack[-1].send(to)
#             return to
#     return wrappedfunc

# def solve():
#     import sys
#     input =sys.stdin.buffer.readline
    
#     n=ii()
#     g = [[] for _ in range(n)]

#     white = [0]*(n)
#     for _ in range(n-1):
#         a,b,t = mii()
#         a-=1
#         b-=1
#         g[a].append(b)
#         g[b].append(a)
#         if t==2:
#             white[a]=1
#             white[b]=1

#     d = [0]*n

#     @bootstrap
#     def dfs(node,prev):
#         # print(node,prev)
#         d[node]=white[node]

#         for adj in g[node]:
#             if adj==prev:
#                 continue

#             yield dfs(adj,node)

#             d[node]+=d[adj]
        
#         yield
    
#     dfs(0,-1)

#     ans =[]

#     for i in range(n):
#         if white[i] and d[i]==1:
#             ans.append(i)
    
#     # print(d,white)
#     print(len(ans))

#     for j in ans:
#         print(j+1,end=" ")


    

    
        
            
            
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
#     #dmain()

# # Comment Read()