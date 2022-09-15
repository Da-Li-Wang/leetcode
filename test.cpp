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

///310
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
                int t = heap.top();
                heap.pop();
                heap.push(intervals[i][1]);
            }
        }
        return heap.size();
    }
};

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



