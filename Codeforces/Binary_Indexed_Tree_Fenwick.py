class BIT:
    def __init__(self,n):
        self.sums = [0]*(n+1)
    
    def update(self,idx,val):
        while idx<len(self.nums):
            self.sums[idx]+=val
            idx+=(idx)&(-idx)

    def query(self,idx):
        s=0
        while idx>0:
           s+=self.sum[idx]
           idx-=(idx&(-idx))
        return s
 
        