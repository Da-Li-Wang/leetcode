#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        int nr = grid.size();
        int nc = grid[0].size();

        for (int r = 0; r < nr; r++)
        {
            for (int c = 0; c < nc; c++)
            {
                if (grid[r][c] == 0)
                {
                    bool judge = true;
                    dfs(grid, r, c, judge);
                    if (judge)
                    {
                        count++;
                        //cout << "r: " << r << "c: " << c << endl; 
                    }
                    
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, bool &judge)
    {
        int nr = grid.size();
        int nc = grid[0].size();

        if (r == 0 || c == 0 || r == nr - 1 || c == nc - 1)
        {   
            judge = false;
        }
            grid[r][c] = 1;

        if (r-1 >= 0 && grid[r-1][c] == 0 ) dfs(grid, r-1, c, judge);
        if (r+1 < nr && grid[r+1][c] == 0 ) dfs(grid, r+1, c, judge);
        if (c-1 >= 0 && grid[r][c-1] == 0 ) dfs(grid, r, c-1, judge);
        if (c+1 < nc && grid[r][c+1] == 0 ) dfs(grid, r, c+1, judge);              
    }
};

/*
[0,0,1,1,0,1,0,0,1,0]
[1,1,*,1,1,0,1,1,1,0]
[1,*,1,1,1,0,0,1,1,0]
[0,1,1,0,0,0,0,1,0,1]
[0,0,0,0,0,0,1,1,1,0]
[0,1,0,1,0,1,0,1,1,1]
[1,0,1,0,1,1,0,0,0,1]
[1,1,1,1,1,1,0,0,0,0]
[1,1,1,0,0,1,0,1,0,1]
[1,1,1,0,1,1,0,1,1,0]
*/