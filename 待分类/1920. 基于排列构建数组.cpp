#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> out(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            out[nums[i]] = nums[i];
        }
        return out;
        
    }
};
