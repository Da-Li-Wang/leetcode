#include <iostream>
#include <vector>
using namespace std;

//摩尔投票法 只投自己人
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int myboy = nums[0], points = 0;
        for(auto it : nums)
        {
            if(points == 0) myboy = it;
            if (it == myboy)
            {
                points++;
            }
            else
            {
                points--;
            } 
        }
        return myboy;
    }
};