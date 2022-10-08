#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        vector<int> idx2(n);
        iota(idx2.begin(), idx2.end(),0);
        sort(idx2.begin(), idx2.end(), [&](int i, int j){return nums2[i] < nums2[j];});

        vector<int> ans(n);
        int left = 0, right = n-1;
        for(int i = 0; i < n; ++i)
        {
            if(nums1[i] > nums2[idx2[left]])
            {
                ans[idx2[left]] = nums1[i];
                ++left;
            }
            else{
                ans[idx2[right]] = nums1[i];
                --right;
            }
        }
        return ans;      
    }
};