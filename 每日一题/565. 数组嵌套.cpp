#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        set<int> choosed;
        int max = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int temp = 0, num = nums[i];
            while (!choosed.count(num))
            {
                choosed.emplace(num);
                num = nums[num];
                temp++;
            }
            if (temp > max)
            {
                max = temp;
            }
        }
        return max;
    }
};