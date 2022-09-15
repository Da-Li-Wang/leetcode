#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int sum = accumulate(nums.begin(), nums.end(), 0), count = 0, i = nums.size()-1;
        while (count < sum / 2)
        {
            ans.push_back(nums[i--]);
        }
        return ans;
        
    }
};