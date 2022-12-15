def min_swaps(arr):
    min_swaps = float('inf')
    for i in range(len(arr)):
        swaps = 0
        sum = 0
        for j in range(i, len(arr)):
            sum += arr[j]
            if sum < 0:
                swaps += 1
            min_swaps = min(min_swaps, swaps)
    return min_swaps

print(min_swaps([-1,-1,-1,1,1,1,1]))