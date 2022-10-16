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
    int commonFactors(int a, int b) {
       int ans = 1, maxans = __gcd(a,b);
        for(int i = 2; i < maxans;i++)
        {
            if((a % i == 0) && (b % i == 0)) ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        vector<vector<int>> record;
        int rows = grid.size(), cols = grid[0].size();
        for(int i = 0; i < rows; i++)
        {
            vector<int> temp(cols);
            for(int j = 0; j < cols; j++)
            {
                if(j == 0)
                {
                    temp[j] = grid[i][0];
                    continue;
                }
                else{
                    temp[j] = temp[j-1] + grid[i][j];
                }
            }
            record.push_back(temp); 
        }

        int ans = 0;
        for(int i = 1; i < rows - 1; i++)
        {
            for(int j = 1; j < cols - 1; j++)
            {
                if(j == 1)
                {
                    ans = max(ans, grid[i][j] + record[i-1][j+1] + record[i+1][j+1]);
                }
                else
                {
                    ans = max(ans, grid[i][j] + record[i-1][j+1] - record[i-1][j-2] + record[i+1][j+1] - record[i+1][j-2]);
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count2 = 0, count1 = 1;
        while(num2)
        {
            if(num2 & 1) count2++;
            num2 = num2 >> 1;
        }
        vector<int> record;

        int copynum1 = num1;

        while(copynum1)
        {
            if(copynum1 & 1) record.push_back(count1);
            count1++;
            copynum1 >> 1;
        }

        int ans = 0, n = record.size();

        if(count2 == n) return num1;
        if(count2 < n)
        {
            int j = n-1;
            while(count2--)
            {
                int temp = 1;
                temp = temp << record[j]-1;
                ans += temp;
                j--;
            }

        }
        if(count2 > n)
        {
            int need = count2 - n;
            ans = num1;
            int temp = 1;
            while(need)
            {
                if((ans & temp) == 0)
                {
                    ans += temp;
                    need--;
                    temp << 1;
                }
            }
        }
        return ans;
    }
};

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

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> record;
        int ans = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0) record.emplace(-nums[i]);
            else
            {
                if(record.emplace(nums[i]))
                {
                    ans = nums[i];
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        set<int> record;
        for(int i = 0; i < n; i++)
        {
            record.emplace(nums[i]);
            string temp = to_string(nums[i]);
            reverse(temp.begin(), temp.end());
            record.emplace(stoi(temp));
        }
        return record.size();
    }
};

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; i++)
        {
            string temp = to_string(i);
            reverse(temp.begin(), temp.end());
            int ri = stoi(temp);
            if(ri + i == num) return true;
        }
        return false;
    }
};



class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int left = 0, right = 0;
        
        while(right < nums.size())
        {
            priority_queue<int, vector<int>, less<>> maxque;
            priority_queue<int, vector<int>, greater<>> minque;
            while (right < nums.size() && nums[right] <= maxK && nums[right] >= minK)
            {
                maxque.emplace(nums[right]);
                minque.emplace(nums[right]);
                if (maxque.top() == maxK && minque.top() == minK)
                {
                    ans++;
                }
                right++;
            }
            while (left <= right && maxque.top() == maxK && minque.top() == minK)
            {
                if(nums[left] == maxK) maxque.pop();
                if(nums[left] == minK) minque.pop();
                if(maxque.top() == maxK && minque.top() == minK) ans++, left++;
            }
            
            right++;
            left = right;
                
        }

        return ans;
    }
};












