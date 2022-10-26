#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int m, n, d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    struct P{ int x, y, t;};
    void DFS(vector<vector<int>>& grid, int x, int y) {
        grid[x][y] = 2;
        for(int i=0;i<4;i++){ // 遍历4个邻接方向
            int xx=x+d[i][0], yy=y+d[i][1];
            if(xx>=0 && xx<m && yy>=0 && yy<n && grid[xx][yy]==1) // 新位置不越界且未被访问，DFS新位置
                DFS(grid, xx, yy);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        bool flag = false; // 标记是否找到第一个岛
        queue<P> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(grid[i][j]==1){
                    if(!flag){
                        DFS(grid, i, j); // 找到第一个岛，将岛上格点全标记为2
                        flag = true;
                    }else{ // 第二个岛的格点入队、初始距离置为0，并标记为已访问
                        q.emplace(P{i, j, 0});
                        grid[i][j] = 1;
                    }
                }
        }
        while(!q.empty()){
            auto [x, y, t] = q.front();
            q.pop();
            for(int i=0;i<4;i++){ // 遍历4个邻接方向
                int xx=x+d[i][0], yy=y+d[i][1];
                if(xx>=0 && xx<m && yy>=0 && yy<n && grid[xx][yy]!=1){ // 新位置不越界且未被访问
                    if(grid[xx][yy] == 2) // 新位置为第一个岛屿，返回当前距离
                        return t;
                    q.emplace(P{xx, yy, t+1}); // 新位置入队，距离+1
                    grid[xx][yy] = 1; // 标记新位置已访问
                }
            }  
        }
        return 0;
    }
};


class Solution {
public:
    int r, c, go[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    
    struct p
    {
        int x, y, dis;
    };

    void dfs(int i, int j, vector<vector<int>>& grid)
    {
        grid[i][j] = 2;
        for(int count = 0; count < 4; count++)
        {
            int tx = go[count][0] + i;
            int ty = go[count][1] + j;
            if(tx >= 0 && tx < r && ty >=0 && ty < c && grid[tx][ty] == 1)
            {
                dfs(tx, ty, grid);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        r = grid.size(), c = grid[0].size();
        queue<p> que;
        bool findfirst = false;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 1)
                {
                    if(!findfirst)
                    {
                        findfirst = true;
                        dfs(i, j, grid);
                    }
                    else
                    {
                        que.push(p{i, j, 0});
                    }
                } 
            }
        }

        while(!que.empty())
        {
            auto [x, y, t] = que.front();
            que.pop();
            for(int i=0;i<4;i++){ 
                int xx=x+go[i][0], yy=y+go[i][1];
                if(xx>=0 && xx<r && yy>=0 && yy<c && grid[xx][yy]!=1){ 
                    if(grid[xx][yy] == 2) 
                        return t;
                    que.emplace(p{xx, yy, t+1}); 
                    grid[xx][yy] = 1; 
                }
            }  
        }

        return 0; 
    }
};