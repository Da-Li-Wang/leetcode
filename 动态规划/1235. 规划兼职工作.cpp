#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n = s.size();
        
        vector<vector<int>> time;
        
        for(int i = 0; i < n; i++)
        {
            time.push_back({s[i], e[i], p[i]});
        }

        sort(time.begin(), time.end(), [&](vector<int> &a, vector<int>& b)){
            return a[1] < b[1];
        };

        sort(e.begin(), e.end());
        vector<int> dp(n+1);
        for(int i = 1; i <= n; i++)
        {
            int l = time[i-1][0], v = time[i-1][2];
            int t = upper_bound(e.begin(), e.end(), l) - e.begin();
            dp[i] = max (dp[i-1], dp[t] + v);
        }

        return dp[n];
    }
};