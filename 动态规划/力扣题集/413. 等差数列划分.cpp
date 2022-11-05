#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
        {
            return 0;
        }
        
        int add = 0, diff1 = 0, diff2 = 0;
        int ans = 0;
        for (int i = 2; i < n; i++)
        {
            diff1 = nums[i - 1] - nums[i - 2];
            diff2 = nums[i] - nums[i - 1];
            if (diff1 == diff2)
            {
                if (diff2 == 0)
                {
                    ans += add;
                }
                else
                {
                    add++;
                    ans += add;
                }
            }

            else
            {
                add = 1;
            }
        }
         return ans;
    }
};