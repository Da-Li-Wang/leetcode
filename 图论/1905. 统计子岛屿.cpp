#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool judge;
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int nr = grid1.size();
        int nc = grid1[0].size();
        int ans = 0;
        for (int r = 0; r < nr; r++)
        {
            for (int c = 0; c < nc; c++)
            {
                if (grid2[r][c] == 1)
                {
                    judge = true;
                    dfs(grid1, grid2, r, c);
                    if (judge)
                    {
                        ans++;
                    }
                    
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c)
    {
        int nr = grid1.size();
        int nc = grid1[0].size();

        grid2[r][c] = 0;

        if (grid1[r][c] == 0)
        {
            judge = false;
        }
        
        if (r-1 >= 0 && grid2[r-1][c] == 1 ) dfs(grid1, grid2, r-1, c);
        if (r+1 < nr && grid2[r+1][c] == 1 ) dfs(grid1, grid2, r+1, c);
        if (c-1 >= 0 && grid2[r][c-1] == 1 ) dfs(grid1, grid2, r, c-1);
        if (c+1 < nc && grid2[r][c+1] == 1 ) dfs(grid1, grid2, r, c+1);
    }



};

