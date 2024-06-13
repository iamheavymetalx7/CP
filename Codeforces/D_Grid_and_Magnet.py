import sys

# sys.setrecursionlimit(1000005)
# sys.set_int_max_str_digits(200005)
int1 = lambda x: int(x)-1
pDB = lambda *x: print(*x, end="\n", file=sys.stderr)
p2D = lambda x: print(*x, sep="\n", end="\n\n", file=sys.stderr)
def II(): return int(sys.stdin.readline())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def LI1(): return list(map(int1, sys.stdin.readline().split()))
def LLI1(rows_number): return [LI1() for _ in range(rows_number)]
def SI(): return sys.stdin.readline().rstrip()
from os import path

if (path.exists('input.txt')):
    sys.stdin  = open('input.txt', 'r')  
    sys.stdout = open('output.txt', 'w') 


dij = [(0, 1), (-1, 0), (0, -1), (1, 0)]
# dij = [(0, 1), (-1, 0), (0, -1), (1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)]
# inf = -1-(-1 << 31)
inf = -1-(-1 << 62)

# md = 10**9+7
md = 998244353

def dfs(i,j):
    vis[i][j]=1
    st=[(i,j)]
    ij=set()
    ij.add(i*w+j)
    while st:
        i,j=st.pop()
        for di, dj in dij:
            ni, nj = i+di, j+dj
            if ni < 0 or nj < 0 or ni >= h or nj >= w: continue
            nij=ni*w+nj
            if nij in ij:continue
            ij.add(nij)
            vis[ni][nj]=1
            if mag[ni][nj]:continue
            st.append((ni,nj))
    return len(ij)

h,w=LI()
ss=[SI() for _ in range(h)]
mag=[[0]*w for _ in range(h)]
vis = [[0]*w for _ in range(h)]
for i in range(h):
    for j in range(w):
        if ss[i][j]=="#":
            mag[i][j]=1
            for di, dj in dij:
                ni, nj = i+di, j+dj
                if ni < 0 or nj < 0 or ni >= h or nj >= w: continue
                mag[ni][nj]=1
ans=1
for i in range(h):
    for j in range(w):
        if mag[i][j]:continue
        if vis[i][j]:continue
        print(i,j, dfs(i,j))
        print(vis)
        ans=max(ans,dfs(i,j))

print(ans)
