def maxSubarrays(nums):
    curr=nums[0]
    cnt=1
    f=False
    i=1
    n=len(nums)
    
    if n==1:
        return 1
    if nums==[0]*(n):
        return n
    while i<n:
        
        curr= curr&nums[i]
        print(curr,i,'iskimaa',nums[i])
        if curr==0:
            if i+1>=n:
                break
            while i+1<n and nums[i+1]==0:
                cnt+=1
                i+=1
            curr= nums[i+1]
            i+=1
            print(curr,"here")
                
            cnt+=1
        i+=1
    
    if curr==0:
        f=True
        cnt+=1
    return cnt+(-1 if f else 0)

val = maxSubarrays([0,8,0,0,0,23])
print(val)


# [0,8,0,0,0,23]

# [8,10,23,26,21,28,21,14,21,14,9,16,24,29,7,26] : 4

print(28&21)

