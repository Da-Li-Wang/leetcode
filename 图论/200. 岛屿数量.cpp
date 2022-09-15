#include <iostream>
#include <vector>
#include <set>
#include <queue>


using namespace std;

//并查集
class Solution {
public:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> f;
        vector<int> rank;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    f.push_back(i*n + j);
                }
                else{
                    f.push_back(-1);
                }
                rank.push_back(0);
                
            }
        }

         for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '1') {
                    if (r - 1 >= 0 && grid[r-1][c] == '1') merge(f, rank, r * n + c, (r-1) * n + c);
                    if (r + 1 < n && grid[r+1][c] == '1') merge(f, rank, r * n + c, (r+1) * n + c);
                    if (c - 1 >= 0 && grid[r][c-1] == '1') merge(f, rank, r * n + c, r * n + c - 1);
                    if (c + 1 < n && grid[r][c+1] == '1') merge(f, rank, r * n + c, r * n + c + 1);
                }
            }
        }
        
        set<int> count;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (find(f,i*n+j) != '-1')
                {
                    count.emplace(find(f,i*n+j));
                }
            }
        }

        return count.size();
    }

    int find(vector<int>&f, int x)
    {
        while (x != f[x])
        {
            int parent = f[x];
            f[x] = f[parent];
            x = parent;
        }
        return x;
    }

    void merge(vector<int>& f, vector<int>& r, int x, int y)
    {
        int fx = find(f, x);
        int fy = find(f, y);
        if (fx == fy)
        {
            return;
        }

        if (r[fx] < r[fy])
        {
            f[fx] = fy;
        }
        else if(r[fy] < r[fx])
        {
            f[fy] = fx;
        }
        else{
            f[fx] = fy;
            r[fy]++;
        }
    }
};


//深度优先搜索
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if(!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r)
        {
            for (int c = 0; c < nc; ++c)
            {
                if (grid[r][c] == '1')
                {
                    ++num_islands;
                    dfs(grid, r, c);
                }   
            }   
        }
        return num_islands;   
    }

    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r-1 >= 0 && grid[r-1][c] == '1') dfs(grid, r-1, c);
        if (r+1 < nr && grid[r+1][c] == '1') dfs(grid, r+1, c);
        if (c-1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c-1);
        if (c+1 < nc && grid[r][c+1] == '1') dfs(grid, r, c+1);
    }
};


//广度优先搜索
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r)
        {
            for (int c = 0; c < nc; ++c)
            {
                if (grid[r][c] == '1')
                {
                    ++num_islands;
                    grid[r][c] = '0';
                    queue<pair<int, int>> neighbors;
                    neighbors.push({r, c});
                    while (!neighbors.empty())
                    {
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first, col = rc.second;
                        if (row - 1 >= 0 && grid[row-1][col] == '1')
                        {
                            neighbors.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if (row + 1 < nr && grid[row + 1][col] == '1')
                        {
                            neighbors.push({row + 1, col});
                            grid[row + 1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col-1] == '1')
                        {
                            neighbors.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if (col + 1 < nc && grid[row][col + 1] == '1')
                        {
                            neighbors.push({row, col + 1});
                            grid[row][col + 1] = '0';
                        }
                    }
                }
            }
        }
        return num_islands;
    }
};