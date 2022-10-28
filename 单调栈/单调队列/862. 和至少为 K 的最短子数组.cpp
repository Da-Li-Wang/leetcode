#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<long long> sum(n+1);
        
        for(int i = 1; i <= n; i++)
        {
            sum[i] = sum[i-1] + nums[i-1];
        }
        int ans = INT_MAX;
        deque<int> deq;
        for(int i = 0; i <= n; i++)
        {
            long long cur = sum[i];
            while(!deq.empty() && cur - sum[deq.front()] >= k)
            {
                ans = min(i - deq.front(), ans);
                deq.pop_front();
            }
            while (!deq.empty() && sum[deq.back()] >= cur)
            {
                deq.pop_back();
            }
            deq.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};