#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        return max(GetlongestOnes(nums, k, 0), GetlongestOnes( nums, k, 1));
    }
    int GetlongestOnes(vector<int>& nums, int k, int target)
    {
        int n = nums.size();
        int ans = 0;
        for (int left = 0, right = 0, sum = 0; right < n; right++)
        {
            sum += nums[right] != target;
            while (sum > k)
            {
                sum -= nums[left++] != target;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};