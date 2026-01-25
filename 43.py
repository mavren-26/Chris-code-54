from collections import deque

def can_escape(grid, sx, sy):
    n, m = len(grid), len(grid[0])
    INF = 10**9
    fire = [[INF]*m for _ in range(n)]
    q = deque()

    for i in range(n):
        for j in range(m):
            if grid[i][j] == 1:
                fire[i][j] = 0
                q.append((i, j))

    dirs = [(1,0),(-1,0),(0,1),(0,-1)]
    while q:
        x, y = q.popleft()
        for dx, dy in dirs:
            nx, ny = x+dx, y+dy
            if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] != 2:
                if fire[nx][ny] > fire[x][y] + 1:
                    fire[nx][ny] = fire[x][y] + 1
                    q.append((nx, ny))

    visited = [[False]*m for _ in range(n)]

    def dfs(x, y, t):
        if x == 0 or y == 0 or x == n-1 or y == m-1:
            return True
        visited[x][y] = True
        for dx, dy in dirs:
            nx, ny = x+dx, y+dy
            if 0 <= nx < n and 0 <= ny < m:
                if not visited[nx][ny] and grid[nx][ny] == 0:
                    if t+1 < fire[nx][ny]:
                        if dfs(nx, ny, t+1):
                            return True
        return False

    return dfs(sx, sy, 0)

# Driver
grid = [
    [0,0,0,2],
    [1,2,0,0],
    [0,0,0,0]
]
print(can_escape(grid, 2, 0))
