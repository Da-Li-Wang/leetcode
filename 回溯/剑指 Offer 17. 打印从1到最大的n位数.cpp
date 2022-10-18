class Solution {
public:
    vector<string> nums = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    string cur;
    vector<int> ans;
    void dfs(int pos, int n)
    {
        if(pos == n)
        {
            ans.push_back(stoi(cur));
            return;
        }

        int start = pos == 0 ? 1 : 0;
        for(int i = start; i < 10; i++)
        {
            cur += nums[i];
            dfs(pos+1, n);
            cur.pop_back();
        }
    }    
    vector<int> printNumbers(int n) {
        for(int i = 1; i <= n; i++)dfs(0, i);
        return ans;
    }
};