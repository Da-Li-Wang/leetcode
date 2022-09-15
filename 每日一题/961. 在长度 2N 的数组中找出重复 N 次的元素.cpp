#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> record;
        int ans;
        for (auto it : nums)
        {
            if (record.count(it))
            {
                ans = it;
                break;
            }
            else
            {
                record.emplace(it);
            }
        }
        return ans;
    }
};