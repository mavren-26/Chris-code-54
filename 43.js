function canEscape(grid, sx, sy) {
    const n = grid.length, m = grid[0].length;
    const INF = 1e9;
    const fire = Array.from({length:n},()=>Array(m).fill(INF));
    const q = [];
    const dirs = [[1,0],[-1,0],[0,1],[0,-1]];

    for(let i=0;i<n;i++)
        for(let j=0;j<m;j++)
            if(grid[i][j]===1){
                fire[i][j]=0;
                q.push([i,j]);
            }

    for(let h=0;h<q.length;h++){
        let [x,y]=q[h];
        for(let [dx,dy] of dirs){
            let nx=x+dx, ny=y+dy;
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!=2){
                if(fire[nx][ny] > fire[x][y]+1){
                    fire[nx][ny] = fire[x][y]+1;
                    q.push([nx,ny]);
                }
            }
        }
    }

    const vis = Array.from({length:n},()=>Array(m).fill(false));
    function dfs(x,y,t){
        if(x===0||y===0||x===n-1||y===m-1) return true;
        vis[x][y]=true;
        for(let [dx,dy] of dirs){
            let nx=x+dx, ny=y+dy;
            if(nx>=0 && ny>=0 && nx<n && ny<m &&
               !vis[nx][ny] && grid[nx][ny]===0 && t+1 < fire[nx][ny]){
                if(dfs(nx,ny,t+1)) return true;
            }
        }
        return false;
    }
    return dfs(sx,sy,0);
}

console.log(canEscape(
    [[0,0,0,2],[1,2,0,0],[0,0,0,0]],2,0
));
