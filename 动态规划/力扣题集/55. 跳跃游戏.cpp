#include <iostream>
#include <vector>

using namespace std;

//初写
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> Dp(n);

        if(n == 1) return true;

        Dp[0] = 0 + nums[0];
        for (int i = 1; i < n; i++)
        {
            if (i <= Dp[i-1])
            {
                Dp[i] = max(Dp[i-1], i + nums[i]);
            }
            else
            {
                Dp[i] = 0;
            }
        }
        return Dp[n-1] ? true : false;
    }
};

//滚动数组优化（也不是）
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        //vector<int> Dp(n);

        if(n == 1) return true;

        int far = 0 + nums[0];
        for (int i = 1; i < n; i++)
        {
            if (i <= far)
            {
                far = max(far, i + nums[i]);
            }
            else
            {
                far = 0;
                return false;
            }
        }
        return far ? true : false;
    }
};
