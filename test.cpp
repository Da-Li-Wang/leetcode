#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
#include <vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
#include <set>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn = 1e9 + 10;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<int, vector<int>> record;
        for(int i = 0; i < s.size(); i++)
        {
            record[s[i] - 'a'].push_back(i);
        }

        for(auto it : record)
        {
            if((it.second[1] - it.second[0] - 1) != distance[it.first]) return false;
        }
        return true;
    }
};

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
       int need =  abs(endPos - startPos) , mod = 1e9 + 7, ans;
       int more = k - need;
       if (more == 0) return 1;
       if (more < 0 || ((int)more & 1)) return 0;
       int count = more/2;
       
       ans = combo(more, more/2);
       for(int i = 0; i < need; i++)
       {
            ans += combo(more, more/2) - (i+1);
       }

       return ans%mod;  
    }
    int factorial(int n)
{
    int fc=1;
    for(int i=1;i<=n;++i) fc *= i;
    return fc;
}

//计算组合数
/*从n个不同元素中取出m(m≤n)个元素的所有组合的个数，叫做n个不同元素中取出m个元素的组合数。用符号c(n,m) 表示。
组合数公式：c(n,m)=n!/(m! * (n-m)!)
性质：c(n,m) = c(n,m-n)
递推公式：c(n,m) = c(n-1,m-1) + c(n-1,m)
*/
int combo(int n,int m)
{
    int com=factorial(n)/(factorial(m)*factorial(n-m));
    return com;
}
};

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
        {
            return n;
        }
        
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++)
        {
            if(nums[i] & nums[i-1] == 0)
            {
                dp[i] = max(dp[i], dp[i-1] + 1);
            }
        }

        return dp[n-1];

    }
};

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> record;
        for(int i = 0; i < names.size(); i++)
        {
            record[heights[i]] = names[i];
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

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = nums;
        int ans = 1, max = nums[0];
        for(int i = 1; i < n; i++)
        {
            if((dp[i] & dp[i-1]) >= max && max >= dp[i])
            {
                dp[i] = dp[i] & dp[i-1];
                ans++;
                max = dp[i];
            }
            else if((dp[i] & dp[i-1]) < max && (dp[i] & dp[i-1]) > dp[i]) continue;
            else if(dp[i] >= max && (dp[i] & dp[i-1]) < dp[i])
            {
                max = dp[i];
                ans = 1;

            }
        }
        return ans; 
    }
};


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