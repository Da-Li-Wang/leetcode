#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int Max = nums[0], Min = nums[0];
        for (int i = 1; i < n; i++)
        {
            Max = max(nums[i], max(nums[i] * Max, nums[i] * Min));
            Min = min(nums[i], min(nums[i] * Max, nums[i] * Min));
        }
        return Max;
    }
};