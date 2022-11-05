#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/*
for 元素 in 列表:
    while 栈不为空 and 栈顶元素（大于或者小于）目标值：
	    出栈
		根据业务处理
	入栈
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> stk;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            while(!stk.empty() && height[i] > height[stk.top()])
            {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int left = stk.top();
                int width = i - left - 1,  Height = min(height[left], height[i]) - height[top];
                ans += width * Height;
            }
            stk.push(i);
        }
        return ans;
    }
};