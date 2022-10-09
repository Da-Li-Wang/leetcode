
//深度优先搜索 指数级时间复杂度 TLE
class Solution {
public:
    int ans = 0, k, rows, cols, mod = 1e9 +7;
    vector<vector<int>> grid;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        this->k = k, this->rows = rows, this->cols = cols, this->grid = grid;
        dfs(0, 0, 0);
        return ans;

    }
    void dfs(int i , int j, int score)
    {
        int temp = grid[i][j];
        score += grid[i][j];
        grid[i][j] = -1;
        if(i == rows-1 && j == cols-1 && score % k == 0) ans = (ans + 1) % mod;
        
        if(i + 1 < rows && grid[i+1][j] != -1) dfs(i+1, j, score);
        if(j + 1 < cols && grid[i][j+1] != -1) dfs(i, j+1, score);
        grid[i][j] = temp;
        return;
    }

};

//记忆化搜索
class Solution {
public:
    int ans = 0, k, rows, cols, mod = 1e9 +7;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> v;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        this->k = k, this->rows = rows, this->cols = cols, this->grid = grid;
        v.resize(rows,vector<vector<int>>(cols,vector<int>(k+1,-1)));
        return dfs(0, 0, 0);
    }
    int dfs(int i , int j, int score)
    {
        int pre = score;
        if(v[i][j][score] != -1)
        {
            return v[i][j][score];
        }
        if(i == rows -1 && j == cols-1)
        {
            if((score + grid[i][j]) % k == 0)
            {
                v[i][j][score] = 1;
                return 1;
            }
            else
            {
                v[i][j][score] = 0;
                return 0;
            }
            score = (score + grid[i][j]) % k;
            int l = (i < rows-1) ? dfs(i+1,j,score) : 0;
            int r = (j < cols-1) ? dfs(i,j+1,score) : 0;
            int count = (l+r)%mod;
            v[i][j][pre] = count;
            return count;
        }
    }
};