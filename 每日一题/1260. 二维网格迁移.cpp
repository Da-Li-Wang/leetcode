#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid[0].size(), m = grid.size();
        int all = m * n;
        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[((n * i + j + k) % all)/ n][((n * i + j + k) % all)% n] = grid[i][j];
            }  
        }
        
        return ans;
    }
};