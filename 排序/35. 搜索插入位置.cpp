#include <iostream>
#include <vector>

using namespace std;
//二分
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = (left + right) >> 1;
            if(nums[mid] > target) right = mid;
            else if(nums[mid] < target) left = mid + 1;
            else return mid;
        }
        return left;
    }
};