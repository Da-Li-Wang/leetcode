class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ret = 0;
        for(int i = 0, l = -1, r1 = -1, r2 = -1; i < n; ++i) {
            if(nums[i] > maxK || nums[i] < minK) l = i;
            if(nums[i] == maxK) r1 = i;
            if(nums[i] == minK) r2 = i;
            ret += max(0, min(r1, r2) - l);
        }
        return ret;
    }
};