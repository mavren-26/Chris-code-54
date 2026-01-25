#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool dfs(int u, int target, vector<vector<int>>& g,
         vector<int>& time, vector<bool>& vis) {
    if (u == target) return true;
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v] && time[v] >= time[u] + 1) {
            if (dfs(v, target, g, time, vis))
                return true;
        }
    }
    return false;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {
        {0,1},{1,2},{2,3},{3,4}
    };
    vector<int> unlock = {0,2,1,3,4};

    vector<vector<int>> g(n);
    for (auto &e : edges) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }

    vector<int> time(n, 1e9);
    queue<int> q;
    time[0] = unlock[0];
    q.push(0);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            int arrive = max(time[u] + 1, unlock[v]);
            if (arrive < time[v]) {
                time[v] = arrive;
                q.push(v);
            }
        }
    }

    vector<bool> vis(n, false);
    cout << dfs(0, n-1, g, time, vis);
}
