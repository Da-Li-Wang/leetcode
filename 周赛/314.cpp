//https://leetcode.cn/circle/discuss/YNdXJT/
//2/4


//处理用时最长的那个任务的员工
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = logs[0][0], time = logs[0][1];
        for(int i = 1; i < logs.size(); i++)
        {
            int temp = logs[i][1] - logs[i-1][1];
            if(temp > time) 
            {
                time = temp;
                ans = logs[i][0];
            }
            else if(temp == time) ans = min(ans, logs[i][0]);
        }
        return ans;
    }
};

//找出前缀异或的原始数组
//异或的逆运算还是异或
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n);
        ans[0] = pref[0];
        for(int i = 1; i < n; i++)
        {
            ans[i] = pref[i-1] ^ pref[i];
        }
        return ans;
    }
};


//使用机器人打印字典序最小的字符串
//栈 单调性
class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> f(n+1);
        f[n] = 'z' + 1;
        for(int i = n-1; i >-1; --i)
        {
           f[i] = min(s[i], f[i+1]); 
        }

        string ans;
        stack<char> str;
        for(int i = 0; i < n; i++)
        {
            str.push(s[i]);
            while(!str.empty() && str.top() <= f[i+1]) ans.push_back(str.top()), str.pop();
        }

        return ans;
    }
};


//矩阵中和能被 K 整除的路径

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