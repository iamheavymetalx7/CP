from collections import deque
def isValid(i, j, N, M):
    return (0 <= i < M) and (0 <= j < N)
def isSafe(i, j, maze, result):
    return maze[i][j] == 'O' and result[i][j] == -1

def getDistance(maze):
    if not maze or not len(maze):
        return []
 
    (M, N) = (len(maze), len(maze[0]))
    result = [[0 for x in range(N)] for y in range(M)]
    q = deque()
    for i in range(M):
        for j in range(N):
            if maze[i][j] == 'M':
                q.append((i, j, 0))
 
                result[i][j] = 0
 
            else:
                result[i][j] = -1
 
    row = [0, -1, 0, 1]
    col = [-1, 0, 1, 0]
 
    while q:
        x, y, distance = q.popleft()
        for i in range(len(row)):
            if isValid(x + row[i], y + col[i], N, M) and \
                    isSafe(x + row[i], y + col[i], maze, result):
                result[x + row[i]][y + col[i]] = distance + 1
                q.append((x + row[i], y + col[i], distance + 1))
 
    return result
 