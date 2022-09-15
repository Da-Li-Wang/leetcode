#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = INT_MIN;
        int max_out;
        int second = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max && nums[i] > second)
            {
                second = max;
                max_out = i;
                max = nums[i];
            }
            else if (nums[i] < max && nums[i] > second)
            {
                second = nums[i];
            }
        }
        if (max >= 2*second || second == INT_MIN)
        {
            return max_out;
        }
        return -1;
    }
};