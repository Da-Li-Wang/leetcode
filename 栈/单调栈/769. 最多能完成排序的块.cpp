#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), ans = 0, temp = 0;
        for(int i = 0; i < n; i++)
        {
            temp = max(arr[i], temp);
            if(i == temp) ans++;
        }
        return ans;
    }
};


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        for(auto it : arr)
        {
            if(stk.empty() || stk.top() <= it)
            {
                stk.push(it);
            }
            else 
            {
                int temp = stk.top();
                stk.pop();
                while(!stk.empty() && stk.top() > it) stk.pop();
                stk.push(temp);
            }
        }
        return stk.size();
    }
};
