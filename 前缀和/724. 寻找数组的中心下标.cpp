#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int sumbegin = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (2 * sumbegin + nums[i] == sum)
            {
                return i;
            }
            sumbegin += nums[i];
        }
        return -1;
    }
};