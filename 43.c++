#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool dfs(int x, int y, int t, vector<vector<int>>& grid,
         vector<vector<int>>& fire, vector<vector<bool>>& vis) {
    int n = grid.size(), m = grid[0].size();
    if (x==0 || y==0 || x==n-1 || y==m-1) return true;
    vis[x][y] = true;

    for (int i=0;i<4;i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx>=0 && ny>=0 && nx<n && ny<m &&
            !vis[nx][ny] && grid[nx][ny]==0 && t+1 < fire[nx][ny]) {
            if (dfs(nx, ny, t+1, grid, fire, vis)) return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> grid = {
        {0,0,0,2},
        {1,2,0,0},
        {0,0,0,0}
    };
    int n=grid.size(), m=grid[0].size();
    const int INF = 1e9;
    vector<vector<int>> fire(n, vector<int>(m, INF));
    queue<pair<int,int>> q;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(grid[i][j]==1){
                fire[i][j]=0;
                q.push({i,j});
            }

    while(!q.empty()){
        auto [x,y]=q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!=2){
                if(fire[nx][ny] > fire[x][y]+1){
                    fire[nx][ny] = fire[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m,false));
    cout << dfs(2,0,0,grid,fire,vis);
}
