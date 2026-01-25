from collections import deque

def can_reach(n, edges, unlock):
    g = [[] for _ in range(n)]
    for u,v in edges:
        g[u].append(v)
        g[v].append(u)

    INF = 10**9
    time = [INF]*n
    q = deque()
    time[0] = max(0, unlock[0])
    q.append(0)

    while q:
        u = q.popleft()
        for v in g[u]:
            arrive = max(time[u] + 1, unlock[v])
            if arrive < time[v]:
                time[v] = arrive
                q.append(v)

    vis = [False]*n
    def dfs(u):
        if u == n-1:
            return True
        vis[u] = True
        for v in g[u]:
            if not vis[v] and time[v] >= time[u] + 1:
                if dfs(v):
                    return True
        return False

    return dfs(0)

# Driver
n = 5
edges = [(0,1),(1,2),(2,3),(3,4)]
unlock = [0,2,1,3,4]

print(can_reach(n, edges, unlock))
