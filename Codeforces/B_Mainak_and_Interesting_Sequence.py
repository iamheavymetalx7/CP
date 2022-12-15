import sys, threading
import math
import time
from os import path
from collections import defaultdict, Counter, deque
from bisect import *
from string import ascii_lowercase
from functools import cmp_to_key
import heapq
 
 
# # # # # # # # # # # # # # # #
#       JAI SHREE RAM         #
# # # # # # # # # # # # # # # #


#codeforcesAssemble
## ihave seen enough today, just because i didnt write
## m-(n-1) as m-n+1 the code gives a TLE, like what?


##interesting observation of using 1's...
 
def lcm(a, b):
    return (a*b)//(math.gcd(a,b))
 
 
si= lambda:str(input())
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(map(int, input().split()))
i2c = lambda n: chr(ord('a') + n)
c2i = lambda c: ord(c) - ord('a')
    
    
def solve(t):
    n,m=mii()

    if m<n:
        print("NO")
        return
    if n%2:
        print("YES")
        print(*([1]*(n-1)+[m-(n-1)]*1))
        return
    if m%2:
        print("NO")
        return
    else:
        print("YES")
        print(*([1]*(n-2)+[(m-n+2)//2]*2))



def main():
    t = 1
    if path.exists("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt"):
        sys.stdin = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt", 'r')
        sys.stdout = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt", 'w')
        start_time = time.time()
        print("--- %s seconds ---" % (time.time() - start_time))
 
 
    sys.setrecursionlimit(10**5)
 
    t = int(input())
 
    for i in range(t):
        solve(i+1)
 
 
if __name__ == '__main__':
    main()


'''


#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    ll t, n, i, j, m, f;
    
    cin>>t;
    
    for(;t--;)
    {
        f=0;
        
        cin>>n>>m;
        ll a[n];
        
        if(m<n){
            cout<<"No\n";
            continue;
        }
        
        if((n%2)==1){
            for(i=0; i<n-1; i++){
                a[i]=1;
            }
            a[n-1]=m-(n-1);
        }else{
            for(i=0; i<n-2; i++){
                a[i]=1;
            }
            m=m-(n-2);
            
            if(m>0 && (m%2)==0){
                a[n-2]=m/2;
                a[n-1]=m/2;
            }else{
                f=1;
            }
        }
        
        if(f==1){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
            for(i=0; i<n; i++){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
    }
}


'''