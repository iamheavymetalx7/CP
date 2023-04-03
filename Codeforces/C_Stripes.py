import os
import sys
import threading,io 

# if(os.path.exists("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt")):
#     sys.stdin = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt", 'r')
#     sys.stdout = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt", 'w') 
# else:
#     input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
    
def solve():
    a=[]
    for _ in range(8):
        a.append(list(str(input())))

    for i in range(8):
        if a[i]==["R"]*8:
            print("R")
            return
        if a[i]==["B"]*8:
            print("B")
            return
    for i in range(8):
        if [row[i] for row in a]==["R"]*8:
            print("R")
            return
        if [row[i] for row in a]==["B"]*8:
            print("B")
            return
        


t=int(input())
for _ in range(t):
    solve()