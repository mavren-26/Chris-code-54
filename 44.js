function countSafeZones(n, edges, infected, safe) {
    const g = Array.from({length:n},()=>[]);
    for (let [u,v] of edges) {
        g[u].push(v);
        g[v].push(u);
    }

    const INF = 1e9;
    const time = Array(n).fill(INF);
    const q = [];

    for (let x of infected) {
        time[x] = 0;
        q.push(x);
    }

    for (let i=0;i<q.length;i++) {
        let u = q[i];
        for (let v of g[u]) {
            if (time[v] > time[u] + 1) {
                time[v] = time[u] + 1;
                q.push(v);
            }
        }
    }

    const vis = Array(n).fill(false);
    function dfs(u) {
        vis[u] = true;
        let ok = time[u] === INF;
        for (let v of g[u]) {
            if (safe[v] && !vis[v]) {
                ok = ok && dfs(v);
            }
        }
        return ok;
    }

    let ans = 0;
    for (let i=0;i<n;i++) {
        if (safe[i] && !vis[i] && dfs(i))
            ans++;
    }
    return ans;
}

console.log(
    countSafeZones(
        7,
        [[0,1],[1,2],[2,3],[3,4],[4,5],[5,6]],
        [0],
        [false,true,true,false,true,true,true]
    )
);
