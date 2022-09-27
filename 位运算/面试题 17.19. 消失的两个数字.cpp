#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        int xy = 0;
        for(auto it : nums)
        {
            xy ^= it; 
        }
        for(int i = 1; i <= n; i++)
        {
            xy ^= i;
        }


        int lsb = xy & -xy;

        int num1 = 0, num2 = 0;
        for(auto it : nums)
        {
            if(lsb & it)
            {
                num1 ^= it; 
            }
            else
            {
                num2 ^= it;
            }
        }

        for(int i = 1; i <= n; i++)
        {
            if(lsb & i)
            {
                num1 ^= i; 
            }
            else
            {
                num2 ^= i;
            }
        }

        return{num1, num2};
    }
};