from collections import deque

def count_safe_zones(n, edges, infected, safe):
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)

    INF = 10**9
    time = [INF]*n
    q = deque()

    for x in infected:
        time[x] = 0
        q.append(x)

    while q:
        u = q.popleft()
        for v in g[u]:
            if time[v] > time[u] + 1:
                time[v] = time[u] + 1
                q.append(v)

    visited = [False]*n

    def dfs(u):
        visited[u] = True
        ok = time[u] == INF
        for v in g[u]:
            if safe[v] and not visited[v]:
                ok &= dfs(v)
        return ok

    count = 0
    for i in range(n):
        if safe[i] and not visited[i]:
            if dfs(i):
                count += 1

    return count

# Driver
n = 7
edges = [(0,1),(1,2),(2,3),(3,4),(4,5),(5,6)]
infected = [0]
safe = [False,True,True,False,True,True,True]

print(count_safe_zones(n, edges, infected, safe))
