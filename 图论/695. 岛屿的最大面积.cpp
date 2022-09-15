#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int count = 0;
    void dfs(vector<vector<int>>& grid, int r, int c)
    {  
        
            grid[r][c] = '0';
            count++; 
            int nr = grid.size();
            int nc = grid[0].size();

            if(r-1 >= 0 && grid[r-1][c] == '1') dfs(grid, r-1, c);
            if(r+1 < nr && grid[r+1][c] == '1') dfs(grid, r+1, c);
            if(c-1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c-1);
            if(c+1 < nc && grid[r][c+1] == '1') dfs(grid, r, c+1);        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        int ans = 0;
        for (int r = 0; r < nr; r++)
        {
            for (int c = 0; c < nc; c++)
            {
                if (grid[r][c] == '1')
                {
                    dfs(grid, r, c);
                    ans = max(ans, count);
                    count = 0;
                }
            }
        }
        return ans;
    }
};