#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> que;
        for(int i = 0, j = 0; j < n; j++)
        {
            que.push({nums[j], j});
            while(que.top().second <= j - k) que.pop();
            if(j - i == k-1)
            {
                ans.push_back(que.top().first);
                i++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> deq;
        for(int i = 0, j = 0; j < n; j++)
        {
            while(!deq.empty() && deq.front() <= j - k) deq.pop_front();
            while(!deq.empty() && nums[deq.back()] <= nums[j]) deq.pop_back();
            deq.push_back(j);
            if(j - i == k-1)
            {
                ans.push_back(nums[deq.front()]);
                i++;
            }
        }
        return ans;
    }
};