#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& box)
    {
        int n = box.size();
        if (n == 1)
        {
            return box[0];
        }

        int first = box[0], second = max(box[1], box[0]);
        for (int i = 2; i < n; i++)
        {
            int temp = second;
            second = max(second, first + box[i]);
            first = temp;
        }
        return second;
    }

    
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        int Max = 0;
        for (auto it : nums)
        {
            Max = max(it, Max);
        }

        vector<int> box(Max + 1);
        for (auto it : nums)
        {
            box[it] += it;
        }
        return rob(box);
    }
};