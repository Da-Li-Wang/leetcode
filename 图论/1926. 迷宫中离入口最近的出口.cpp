#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int nr = maze.size();
        int nc = maze[0].size();

        queue<tuple<int, int, int>> box;
        box.emplace(entrance[0], entrance[1], 0);
        maze[entrance[0]][entrance[1]] = '+';
        while (!box.empty())
        {
            int m = box.size();
            auto[x, y, t] = box.front();
            
            box.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nt = t;
                if (nx >= 0 && nx < nr && ny >= 0 && ny < nc && maze[nx][ny] == '.')
                {
                    if (nx == 0 || ny == 0 || nx == nr - 1 || ny == nc - 1 )
                    {
                            return nt + 1;
                    }
                    maze[nx][ny] = '+';
                    box.emplace(nx, ny, nt+1);
                } 
                
            }
        }
        return -1;
    }
};

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        // 上下左右四个相邻坐标对应的行列变化量
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        queue<tuple<int, int, int>> q;
        // 入口加入队列并修改为墙
        q.emplace(entrance[0], entrance[1], 0);
        maze[entrance[0]][entrance[1]] = '+';
        while (!q.empty()){
            auto [cx, cy, d] = q.front();
            q.pop();
            // 遍历四个方向相邻坐标
            for (int k = 0; k < 4; ++k){
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                // 新坐标合法且不为墙
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.'){
                    if (nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1){
                        // 新坐标为出口，返回距离作为答案
                        return d + 1;
                    }
                    // 新坐标为空格子且不为出口，修改为墙并加入队列
                    maze[nx][ny] = '+';
                    q.emplace(nx, ny, d + 1);
                }
            }
        }
        // 不存在到出口的路径，返回 -1
        return -1;
    }
};

