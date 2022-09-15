#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> out = vector<int>(nums.size());
        
        int i = 0, j = nums.size()-1;
        for (auto num : nums)
        {
            if ((num & 1) == 0)//注意运算符顺序
            {
                out[i++] = num; 
            }
            else
            {
               
                out[j--] = num;
            }
        }
        return out;

    }
};