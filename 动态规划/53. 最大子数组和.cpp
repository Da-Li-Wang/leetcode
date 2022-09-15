#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int memory = nums[0];
        int Max = nums[0];

        int n = nums.size();

        if (n == 1)
        {
            return Max;
        }

        for (int i = 1; i < n; i++)
        {
            memory = max(memory + nums[i], nums[i]);
            Max = max(Max, memory);
        }
        
        return Max;
        
    }
};