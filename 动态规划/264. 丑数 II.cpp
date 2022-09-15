#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; i++)
        {
            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
            dp[i] = min(num2, min(num3, num5));
            if (dp[i] == num2)
            {
                p2++;
            }
            if (dp[i] == num3)
            {
                p3++;
            }
            if (dp[i] == num5)
            {
                p5++;
            }
        }
        return dp[n];
    }
};
//不通过 改long
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, greater<>> heap;
        set<int> seen;
        int factors[3] = {2,3,5};
        seen.emplace(1);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int cur =  heap.top();
            heap.pop();
            for (auto it : factors)
            {
                int temp = it * cur;
                if (!seen.count(temp))
                {
                    heap.push(temp);
                    seen.emplace(temp);
                }
            }
           ans = cur; 
        }
        return ans;
    }
};