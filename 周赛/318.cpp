//https://leetcode.cn/contest/weekly-contest-318/
// 3/4 又被rejudge了
// 2/4
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

//https://leetcode.cn/problems/apply-operations-to-an-array/
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                nums[i] = 2*nums[i];
                nums[i+1] = 0;
            }
        }
        vector<int> ans(n);
        int ptr = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0){
                ans[ptr] = nums[i];
                ptr++;
            } 
        }
        return ans;
    }
};


//https://leetcode.cn/problems/maximum-sum-of-distinct-subarrays-with-length-k/
//这题被rejudge了
//啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0, ans = -1;
        set<int> record;//傻逼！！！！！
        for (int i = 0, j = 0; j < n; ++j) {
            if(record.count(nums[j]) || j-i == k)
            {
                record.erase(nums[i]);//会出现 【1 1】 3 -> 1 【1 3】情况时 把1删掉的情况
                sum -= nums[i];
                i++;
            }
            record.emplace(nums[j]);
            sum += nums[j];
            if(record.size() == k && j - i == k-1) ans = max(sum, ans);
        }
        return ans == -1 ? 0 : ans;
    }
};


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0, ans = -1;
        map<int, int> record;
        for (int i = 0, j = 0; j < n; ++j) {
            if(j-i == k)
            {
                record[nums[i]]--;
                if(!record[nums[i]]) record.erase(nums[i]);//
                sum -= nums[i];
                i++;
            }
            record[nums[j]]++;
            sum += nums[j];
            if(record.size() == k && j - i == k-1) ans = max(sum, ans);
        }
        return ans == -1 ? 0 : ans;
    }
};

//https://leetcode.cn/problems/total-cost-to-hire-k-workers/description/
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que1;
        //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que2;
        priority_queue<int, vector<int>, greater<>> que1;
        priority_queue<int, vector<int>, greater<>> que2;
        int n = costs.size() ,right = n-1, left = 0;
        long long ans = 0;
        while(k--)
        {
            while(left <= right && que1.size() < candidates)
            {
                que1.push(costs[left]);
                left++;
            }
            while(left <= right && que2.size() < candidates)
            {
                que2.push(costs[right]);
                right--;
            }

            if(!que1.empty() && !que2.empty() && que1.top() <= que2.top())
            {
                ans += que1.top();
                que1.pop();
            }
            else if(!que1.empty() && !que2.empty() && que1.top() > que2.top())
            {
                ans += que2.top();
                que2.pop();
            }
            else if(que2.empty() && !que1.empty())
            {
                ans += que1.top();
                que1.pop();
            }
            else if(que1.empty() && !que2.empty())
            {
                ans += que2.top();
                que2.pop();
            }
        }
        return ans;
    }
};


const int N = 110;
long long f[N][N], g[N][N];
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = robot.size(), m = factory.size();
        memset(f, 0x3f, sizeof(f));
        memset(g, 0x3f, sizeof(g));
        f[0][0] = 0;
        for(int i = 0; i <= m; i++) g[0][i] = 0;


        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                long long d = 0;
                for(int ii = i-1; ii >= 0 && i - ii <= factory[j-1][1]; ii--)
                {
                    d += abs(robot[ii] - factory[j-1][0]);
                    f[i][j] = min(f[i][j], g[ii][j-1] + d);//f[i][j] 表示已经送走了前i个机器人，且第i个机器人送去工厂j的最小总距离
                }
            }
            for(int j = 1; j <= m; j++) g[i][j] = min(g[i][j-1], f[i][j]);//g[i][j] 表示把前i个机器人送到前j个机器的最小距离
        }

        return g[n][m];
    }
};

const int N = 110;

class Solution {
private:
    long long f[N][N];//前i个库装j个机器人的最小值
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        memset(f, 0x3f, sizeof f);
        int n = robot.size(), m = factory.size();
        for (int i = 0; i <= m; i++)
            f[i][0] = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                long long cost = 0;
                for (int k = 0; k <= min(factory[i - 1][1], j); k++) 
                {
                    if(k > 0)cost += abs(factory[i - 1][0] - robot[j - k]);
                    f[i][j] = min(f[i][j], f[i - 1][j - k] + cost);
                }
            }
        return f[m][n];
    }
};
