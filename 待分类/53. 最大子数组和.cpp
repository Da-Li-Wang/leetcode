#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) {

        int maxright = 0, maxleft = 0;
         int pre = 0, maxAns = nums[0];

        for(int i = 0; i < nums.size(); i++)
        {
            if (pre > 0)
            {
                pre += nums[i];
            }
            else
            {
                pre = nums[i];

            }

            if (maxAns < pre)
            {
                maxAns = pre;
                maxright = i;
            }
            
            return maxAns;
        }
        
    }
};