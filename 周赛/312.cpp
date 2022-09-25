//一题掉大分！
// 6188. 按身高排序   https://leetcode.cn/problems/sort-the-people/


//优化方法 可以按照-heights[i]加入,这样就是递减

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> record;
        for(int i = 0; i < names.size(); i++)
        {
            record[heights[i]] = names[i];//record[-heights[i]] = names[i];
        }

        vector<string> ans;
        for(auto it : record)
        {
            ans.push_back(it.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//6189. 按位与最大的最长子数组
//由于 AND 不会让数字变大，那么最大值就是数组的最大值！
//脑筋急转弯 

//傻逼写的 WA五次 还没过
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = nums;
        int max = nums[0], ans = 1;
        for(int i = 1; i < n; i++)
        {
            int cur = (dp[i] & dp[i-1]);
            if(cur >= max)
            {
                if(cur >= dp[i])
                {
                    dp[i] = cur;
                    max = cur;
                    ans++;
                }
                else if(cur < dp[i])
                {
                    max = dp[i];
                    ans = 1;
                }
            }
            else if(cur < max)
            {
                if(dp[i] >= max)
                {
                    ans = 1;
                    max = dp[i];
                }
                else if(dp[i] < max)
                {
                    continue;
                }
            } 
        }
        return ans;
    }
};

//正确解法 连续最大数组
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxnum = 0, ans = 1;
        for(auto it : nums)
        {
            if(maxnum < it)
            {
                maxnum = it;
            }
        }

        for(int i = 0; i < nums.size(); i++)
        {
            int temp = 0;
            while(i < nums.size()&& nums[i] == maxnum )
            {
                temp++;
                i++;
            }
            ans = max(temp, ans);
        }
        return ans;
    }
};


//6190. 找到所有好下标
//https://leetcode.cn/problems/find-all-good-indices/

//傻逼写法 一定会超时

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> feidijianset, feidizengset;
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(i+k < n)
            {
                bool feidijan = true;
                for(int j = i + 2; j <= i+k; j++)
                {
                    if(nums[j] < nums[j-1]) 
                    {
                        feidijan = false;
                        break;
                    }
                }
                if(feidijan) feidijianset.emplace(i);
            }
            if(i-k >= 0)
            {
                bool feidizeng = true;
                for(int j = i - k; j <= i-2; j++)
                {
                    if(nums[j] > nums[j+1]) 
                    {
                        feidizeng = false;
                        break;
                    }
                }
                if(feidizeng) feidizengset.emplace(i);
            }
            if(feidijianset.count(i) && feidizengset.count(i)) ans.push_back(i);
        }
    }
};


//预处理解法

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> stupid1(n, 1), stupid2(n, 1);
        for(int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i-1])
            {
                stupid1[i] = stupid1[i-1] + 1; 
            }
        }

        for(int i = n-2; i >= 0; i--)
        {
            if (nums[i] <= nums[i+1])
            {
                stupid2[i] = stupid2[i+1] + 1; 
            }
        }     

        vector<int> ans;
        for (int i = k; i < n - k; i++) 
        {
            if (stupid1[i - 1] >= k && stupid2[i + 1] >= k) 
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};