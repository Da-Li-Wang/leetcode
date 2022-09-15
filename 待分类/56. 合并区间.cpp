#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& nums1, const vector<int>& nums2)
    {
        int a = nums1[0];
        int b = nums2[0];
        return a < b;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            int begin = res[res.size()-1][0];
            int end = res[res.size()-1][1];
            if (intervals[i][0] <= end)
            {
                if (intervals[i][1] > end)
                {
                    res[res.size()-1][1] = intervals[i][1];
                }
            }
            else if (intervals[i][0] > end)
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};