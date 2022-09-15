#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, base = 1, n = nums.size(), count = 0;
        for (int i = left; i < n; i++)
        {
            int temp = base * nums[i];
            while (temp >= k)
            {
                temp /= nums[left++];
            }
            count += i - left + 1;
        }
        return count;
    }
};