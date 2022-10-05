#include <iostream>
#include <queue>

using namespace std;


//优先级队列解法 nlogn
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size(),right = k-1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> que;
        for(int i = 0; i <= right; i++)
        {
            que.emplace(nums[i], i);
        }
        ans.push_back(que.top().first);
        right++;
        while(right < n)
        {
            que.emplace(nums[right], right);
            while(que.top().second <= right - k)
            {
                que.pop();
            }
            ans.push_back(que.top().first);
        }
        return ans;
    }
};


//动态滑动窗口法 n

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> rank;
        vector<int> ans;
        for(int i = 0; i < k; i++)
        {
            while(!rank.empty() && nums[i] > rank.back())
            {
                rank.pop_back();
            }
            rank.push_back(nums[i]);
        }
        ans.push_back(rank.front());

        for(int i = k; i < nums.size(); i++)
        {
            if(!rank.empty() && rank.front() == nums[i-k]) rank.pop_front();
            while(!rank.empty() && nums[i] > rank.back())
            {
                rank.pop_back();
            }
            rank.push_back(nums[i]);
            ans.push_back(rank.front());
        }
        return ans;
    }
};