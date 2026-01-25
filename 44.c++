#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool dfs(int u, vector<vector<int>>& g, vector<bool>& safe,
         vector<bool>& vis, vector<int>& time) {
    vis[u] = true;
    bool ok = (time[u] == 1e9);
    for (int v : g[u]) {
        if (safe[v] && !vis[v]) {
            ok &= dfs(v, g, safe, vis, time);
        }
    }
    return ok;
}

int main() {
    int n = 7;
    vector<vector<int>> edges = {
        {0,1},{1,2},{2,3},{3,4},{4,5},{5,6}
    };

    vector<vector<int>> g(n);
    for (auto &e : edges) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }

    vector<int> infected = {0};
    vector<bool> safe = {0,1,1,0,1,1,1};

    vector<int> time(n, 1e9);
    queue<int> q;
    for (int x : infected) {
        time[x] = 0;
        q.push(x);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (time[v] > time[u] + 1) {
                time[v] = time[u] + 1;
                q.push(v);
            }
        }
    }

    vector<bool> vis(n, false);
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (safe[i] && !vis[i]) {
            if (dfs(i, g, safe, vis, time))
                result++;
        }
    }

    cout << result;
}
