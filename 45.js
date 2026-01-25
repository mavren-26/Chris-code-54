function canReach(n, edges, unlock) {
    const g = Array.from({length:n},()=>[]);
    for (let [u,v] of edges) {
        g[u].push(v);
        g[v].push(u);
    }

    const INF = 1e9;
    const time = Array(n).fill(INF);
    const q = [];
    time[0] = unlock[0];
    q.push(0);

    for (let i=0;i<q.length;i++) {
        let u = q[i];
        for (let v of g[u]) {
            let arrive = Math.max(time[u] + 1, unlock[v]);
            if (arrive < time[v]) {
                time[v] = arrive;
                q.push(v);
            }
        }
    }

    const vis = Array(n).fill(false);
    function dfs(u) {
        if (u === n-1) return true;
        vis[u] = true;
        for (let v of g[u]) {
            if (!vis[v] && time[v] >= time[u] + 1) {
                if (dfs(v)) return true;
            }
        }
        return false;
    }

    return dfs(0);
}

console.log(
    canReach(
        5,
        [[0,1],[1,2],[2,3],[3,4]],
        [0,2,1,3,4]
    )
);
