#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    const int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    const int dy[8] = {-1, 0, 1, -1, 1, 0, -1, 1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        int n = grid.size(), ans = 1;
        queue<pair<int, int>> q;
        q.emplace(0,0);
        grid[0][0] = 1;
        while (!q.empty())
        {
            int count = q.size();
            while (count--)
            {
                auto [x, y] = q.front();
                q.pop();
                if (x == n - 1 && y == n -1) return ans;
                 for(int i=0;i<8;i++){                       //遍历八个方向的
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx<0||ny<0||nx>=n||ny>=n)continue;   //判断是否越界
                    if(grid[nx][ny]==0){        //判断是否能走
                        q.emplace(nx,ny);
                        grid[nx][ny]=1;         //标记
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        int n=grid.size(),ans=1;
        const int dire[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
        queue<pair<int,int> > q;
        q.emplace(0,0);         //从0,0开始
        grid[0][0]=1;           //标记为1代表走过
        while(!q.empty()){      //bfs
            int m=q.size();
            while(m--){
                auto [x,y]=q.front();
                q.pop();
                if(x==n-1&&y==n-1)return ans;
                for(int i=0;i<8;i++){                       //遍历八个方向的
                    int nx=x+dire[i][0];
                    int ny=y+dire[i][1];
                    if(nx<0||ny<0||nx>=n||ny>=n)continue;   //判断是否越界
                    if(grid[nx][ny]==0){        //判断是否能走
                        q.emplace(nx,ny);
                        grid[nx][ny]=1;         //标记
                    }
                }
            }
            ans++;          //记录循环次数
        }
        return -1;
    }
};
