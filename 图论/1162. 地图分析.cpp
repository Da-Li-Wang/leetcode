#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    static constexpr int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    static constexpr int MAX_N = 100 + 5;

    struct Coordinate {
        int x, y, step;
    };

    int n, m;
    vector<vector<int>> a;

    bool vis[MAX_N][MAX_N];

    int findNearestLand(int x, int y) {
        memset(vis, 0, sizeof vis);
        queue <Coordinate> q;
        q.push({x, y, 0});
        vis[x][y] = 1;
        while (!q.empty()) {
            auto f = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = f.x + dx[i], ny = f.y + dy[i];
                if (!(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1)) {
                    continue;
                }
                if (!vis[nx][ny]) {
                    q.push({nx, ny, f.step + 1});
                    vis[nx][ny] = 1;
                    if (a[nx][ny]) {
                        return f.step + 1;
                    }
                }
            }
        }
        return -1;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->m = grid.at(0).size();
        a = grid;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!a[i][j]) {
                    ans = max(ans, findNearestLand(i, j));
                }
            }
        }
        return ans;
    }
};



class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
                static const int dx[4] = {1, 0, 0, -1};
        static const int dy[4] = {0, 1, -1, 0};


        queue<pair<int, int>> FK;

        int nr = grid.size(), nc = grid[0].size();
        
        for(int r = 0; r < nr; r++){
            for (int c = 0; c < nc; c++)
            {
                if (grid[r][c] == 1)
                {
                    FK.push({r,c});
                }
                
            }
        }

        if (FK.empty())
        {
           return -1;
        }
        
        pair<int, int> pos;
        bool hasocean = false;
        while(!FK.empty())
        {
            pos.first = FK.front().first, pos.second = FK.front().second;
            FK.pop();
            for (int i = 0; i < 4; i++)
            {
                int newX = pos.first + dx[i];
                int newY = pos.second + dy[i];
                 if (newX < 0 || newX >= nr || newY < 0 || newY >= nc || grid[newX][newY] != 0) {
                    continue;
                }
                grid[newX][newY] = grid[pos.first][pos.second] + 1;
                FK.push({newX,newY});
                hasocean = true;
            }
            
        }


        if (!hasocean) {
            return -1;
        }

        return grid[pos.first][pos.second] - 1;
    }
};