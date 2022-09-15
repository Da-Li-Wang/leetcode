#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = INT_MAX;
        int devide = INT_MAX;
        for (int first = 0;first < n; first++)
        {
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            int third = n-1;
            int twotarget = target - nums[first];
            for (int second = first + 1; second < n; second++)
            {
                if (second > first + 1 && nums[second] == nums[second-1])
                {
                    continue;
                }
                 while (second < third && nums[third] + nums[second] > twotarget)
                {
                    int temp = nums[first] + nums[second] + nums[third];
                    if (abs(temp - target) < devide)
                    {
                        devide = abs(temp - target);
                        sum = temp;
                    }
                    third--; 
                }
                if (second < third && nums[third] + nums[second] < twotarget)
                {
                    int temp = nums[first] + nums[second] + nums[third];
                    if (abs(temp - target) < devide)
                    {
                        devide = abs(temp - target);
                        sum = temp;
                    }
                }
                if (third == second)
                {
                    break;
                }
            }
        }
        return sum;
    }
};