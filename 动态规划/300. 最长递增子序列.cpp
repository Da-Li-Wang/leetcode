#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//复杂度n^2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
        {
            return n;
        }
        
        vector<int> Dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    nums[i] = max(nums[j] + 1, nums[i]);
                }
                
            }
            
        }
        
        return *max_element(nums.begin(),nums.end());
    }
};

//复杂度nlogn

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        vector<int> Dp(n + 1);
        Dp[1] = nums[0];
        int len = 1;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] > Dp[len])
            {
                
                Dp[++len] = nums[i];
            }
            else
            {
                int l = 1, r = len, pos = 0;
                while(l <= r)
                {
                    int mid = (l + r) >> 1;
                    if(Dp[mid] < nums[i])
                    {
                        pos = mid;
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                    }
                }
                
                Dp[++pos] = nums[i];
            }
        }
        return len;

    }
};