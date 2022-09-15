#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

class Solution {
public:
    
        bool cmp(vector<int> one, vector<int> two)
        {
            return one[0] < two[1];
        } 
           
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        auto record = map<int, int>();
        auto record2 = map<int, int>();
        
        for (int i = 0; i < n; i++)
        {
            record.emplace(intervals[i][0], i); 
        }

        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < n; i++)
        {
            record2.emplace(intervals[i][0], i); 
        }

        auto ans = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            if (record.count(intervals[i][1] + 1))
            {
                /* code */
            }
            
        }
        
        
    }
};

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            startIntervals.emplace_back(intervals[i][0], i);
        }
        sort(startIntervals.begin(), startIntervals.end());

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(startIntervals.begin(), startIntervals.end(), make_pair(intervals[i][1], 0));//只取首元素
            if (it != startIntervals.end()) {
                ans[i] = it->second;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startIntervals;
        vector<pair<int, int>> endIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            startIntervals.emplace_back(intervals[i][0], i);
            endIntervals.emplace_back(intervals[i][1], i);
        }
        sort(startIntervals.begin(), startIntervals.end());
        sort(endIntervals.begin(), endIntervals.end());

        vector<int> ans(n, -1);
        for (int i = 0, j = 0; i < n && j < n; i++) {
            while (j < n && endIntervals[i].first > startIntervals[j].first) {
                j++;
            }
            if (j < n) {
                ans[endIntervals[i].second] = startIntervals[j].second;
            }
        }
        return ans;
    }
};


