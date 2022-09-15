#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size(), ans = -1;
        while(left < right)
        {
            int mid = (left + right)/2;
            if(nums[mid] >= target)//等号在此 取下界
            {
                right = mid;
                ans = mid;
            }
            if(nums[mid] < target)//等号在此 取上界
            {
                left = mid + 1;
                //ans = mid;
            }
        }
        return ans; 
    }
    int search(vector<int>& nums, int target) {
        int up =  binarySearch(nums, target + 1);
        int down = binarySearch(nums, target);
        if(down == -1 ) return 0;
        if (up == -1 ) return nums.size() - down;
        return up - down;
    }
};


class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int search(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return rightIdx - leftIdx + 1;
        }
        return 0;
    }
};

