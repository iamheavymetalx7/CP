class DSU:
    def __init__(self,n):
        self.rank =[1 for _ in range(n+1)]
        self.par =[i for i in range(n+1)]

    def find(self,p):
        p=self.par[p]
        while p!=self.par[p]:
            self.par[p] = self.par[self.par[p]]
            p=self.par[p]
        return p


    def merge(self,x,y):
        x=self.find(x)
        y=self.find(y)

        if x==y:
            return False
        if self.rank[y]>self.rank[x]:
            x,y=y,x

        self.par[y]=x
        self.rank[x]+=self.rank[y]

        return True
    
        
