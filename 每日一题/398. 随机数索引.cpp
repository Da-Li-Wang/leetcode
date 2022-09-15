#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            box[nums[i]].push_back(i);
        }
        
    }
    
    int pick(int target) {
        return box[target][rand() % box[target].size()];
    }

    map<int, vector<int>> box;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

//水塘抽样
class Solution {
public:
    vector<int> numstram;
    Solution(vector<int>& nums) : numstram(nums) {}
    
    int pick(int target) {
        int ans;
        for (int i = 0, cnt = 0; i < numstram.size(); ++i)
        {
            if (numstram[i] == target)
            {
                ++cnt;
                if (rand() % cnt == 0)
                {
                    ans = i;
                }   
            } 
        }
        return ans;
    }
};



