#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int dp = values[0] + 0, ans = INT_MIN;

        for (int i = 1; i < n; i++)
        {
            dp = max(dp, values[i-1] + i-1);
            ans = max(dp + values[i] - i, ans);
        }
        
        return ans;
    }
};