#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int count = 0;
    int numEnclaves(vector<vector<int>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        int ans = 0;
        for (int r = 0; r < nr; r++)
        {
            for (int c = 0; c < nc; c++)
            {
                //cout << "c：" << c << "r: " << r << endl; 
                if(grid[r][c] == 1)
                {
                    bool judge = true;
                    ans += dfs(grid, r, c, judge);
                    count = 0;
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& grid, int r, int c, bool judge)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        //cout << "r: " << r << "c: " << c << endl;
        if (r == 0 || c == 0 || r == nr - 1 || c == nc - 1)
        {   
            judge = false;
        }
            grid[r][c] = 0;
            if (judge)
            {
                count++;
            }
            else
            {
                count = 0;
            }
        if (r-1 >= 0 && grid[r-1][c] == 1 ) dfs(grid, r-1, c, judge);
        if (r+1 < nr && grid[r+1][c] == 1 ) dfs(grid, r+1, c, judge);
        if (c-1 >= 0 && grid[r][c-1] == 1 ) dfs(grid, r, c-1, judge);
        if (c+1 < nc && grid[r][c+1] == 1 ) dfs(grid, r, c+1, judge); 
        return count;
    }
};

/*
[0,0,1,1,1,0,1,1,1,0,1]
[1,1,1,1,0,1,0,1,1,0,0]
[0,1,0,1,1,0,0,0,0,1,0]
[1,0,1,1,1,1,1,0,0,0,1]
[0,0,1,0,1,1,0,0,1,0,0]
[1,0,0,1,1,1,0,0,0,1,1]
[0,1,0,1,1,0,0,0,1,0,0]
[0,1,1,0,1,0,1,1,1,0,0]
[1,1,0,1,1,1,0,0,0,0,0]
*/