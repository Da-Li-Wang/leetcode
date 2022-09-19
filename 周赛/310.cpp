//310
class Solution {
public:
    int partitionString(string s) {
        set<char> record;
        int ans = 1;
        for(auto it : s)
        {
            if(record.count(it))
            {
                ans++;
                record.clear();
                record.emplace(it);
            }
            else
            {
                record.emplace(it);
            }
            
        }
        return ans;
    }
};

//
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < n; ++i) 
        {
            if (heap.empty() || heap.top() >= intervals[i][0]) heap.push(intervals[i][1]);
            else {
                heap.pop();
                heap.push(intervals[i][1]);
            }
        }
        return heap.size();
    }
};
//线段树 不会做
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size(), ans = 1;
        vector<int> Dp(n, 1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j] && nums[i] - nums[j] <= k)
                {
                    Dp[i] = max(Dp[i], Dp[j] + 1);
                    ans = max(ans, Dp[i]);
                }
            }
        }
        return ans;
    }
};