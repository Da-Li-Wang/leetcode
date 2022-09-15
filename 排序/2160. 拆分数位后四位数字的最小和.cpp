#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        vector<int> nums;
        while(num)
        {
            int temp = num % 10;
            if (temp > 0)
            {
                nums.push_back(temp);
            }
            num /= 10;
        }
        int n1 = nums.size()/2;
        int n2 = nums.size() - n1;

        sort(nums.begin(), nums.end());
        if (n1 > 1)
        {
            int num1 = nums[0]*10 + nums[2];
            int num2 = nums[1]*10 + nums[3];
            return num1 + num2;
        }
        if (n2 > 1)
        {
            return nums[0]*10 + nums[1] + nums[2];
        }
        if(nums.size() == 1) return nums[0];
        return nums[1]+nums[0];
    }
};