#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int Maxmemory = nums[0];
        int Max = nums[0];
        int Minmemory = nums[0];
        int Min = nums[0];
        int total = nums[0];

        int n = nums.size();

        for (int i = 1; i < n; i++)
        {
            Maxmemory = max(Maxmemory + nums[i], nums[i]);
            Max = max(Max, Maxmemory);
            Minmemory = min(Minmemory + nums[i], nums[i]);
            Min = min(Min, Minmemory);
            total += nums[i];
        }
        return  Max > 0 ? max(Max, total- Min) : Max;
    }
};