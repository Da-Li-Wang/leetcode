#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    set<vector<int>> choosed;
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int sum = 0;
        combSum(candidates, target, temp, sum);
        return ans;
    }

    void combSum(vector<int>& candidates, int target, vector<int> temp, int sum){
        if (!choosed.count(temp) && sum == target)
        {
            ans.push_back(temp);
            
        }
        
        for (auto it : candidates)
        {
            if (sum < target)
            {
                temp.push_back(it);
                combSum(candidates, target, temp, sum + it);
            }
        }
        return;        
    }

};

class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};
