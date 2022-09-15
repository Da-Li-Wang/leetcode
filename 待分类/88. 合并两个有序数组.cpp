#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>temp = vector<int>(m+n);
        int i = 0, j = 0;
        int cnt = 0;
        while (i < m && j < n)
        {
            if(nums1[i] <= nums2[j])
            {
                temp[cnt++] = nums1[i++];
            }
            else
            {
                temp[cnt++] = nums2[j++];
            }
        }
        while (i<m)
        {
            temp[cnt++] = nums1[i++];
        }
        while (j < n)
        {
            temp[cnt++] = nums2[j++];
        }
        nums1 = temp;
    }
};