#include <iostream>
#include <vector>

using namespace std;

//
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }

        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }
        
        
        vector<int> Dp(n);
        Dp[0] = nums[0], Dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i <= n-1; i++)
        {
            Dp[i] = max(Dp[i-2] + nums[i], Dp[i-1]);
        }
        

        if (n & 1)
        {
            if (Dp[0] == Dp[1])
            {
                /* code */
            }
            
        }
        
        return Dp[n-1];
    }
};

//stupid解法 纯纯nt 纯纯异想天开

class Solution {
public:
    int rob(vector<int>& nums) {
        int odd = 0, even = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i & 1)
            {
                odd += nums[i];
            }
            else
            {
                even += nums[i];
            }
            
        }
        return max(odd, even);
    }
};