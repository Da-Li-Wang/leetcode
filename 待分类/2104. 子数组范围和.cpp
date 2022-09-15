#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> minLeft(n), minRight(n), maxLeft(n), maxRight(n);
        stack<int> minStcak, maxStack;
        for (int i = 0; i < n; i++)
        {
            while (!minStcak.empty() && nums[i] < nums[minStcak.top()])
            {
                minStcak.pop();
            }
            minLeft[i] = minStcak.empty() ? -1 : minStcak.top();
            minStcak.push(i);

             while (!maxStack.empty() && nums[i] >= nums[maxStack.top()])
            {
                maxStack.pop();
            }
            maxLeft[i] = maxStack.empty() ? -1 : maxStack.top();
            maxStack.push(i);
        }
        
        minStcak =  stack<int>();
        maxStack =  stack<int>();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!minStcak.empty() && nums[i] <= nums[minStcak.top()])
            {
                minStcak.pop();
            }
            minRight[i] = minStcak.empty() ? n : minStcak.top();
            minStcak.push(i);

             while (!maxStack.empty() && nums[i] > nums[maxStack.top()])
            {
                maxStack.pop();
            }
            maxRight[i] = maxStack.empty() ? n : maxStack.top();
            maxStack.push(i);
        }
        long long sumMax = 0;
        long long sunMin = 0; 
        for (int i = 0; i < n; i++)
        {
            sumMax += static_cast<long long>((i - maxLeft[i]) * (maxRight[i] - i) * nums[i]);
            sunMin += static_cast<long long>((i - minLeft[i]) * (minRight[i] - i) * nums[i]);
        }
        return sumMax-sunMin; 
        
    }
};