#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int Ispositive = 1, Isnegative = -1;
        int n = nums.size(), len1 = 1, len2 = 1;
        vector<vector<int>> Dp(2, vector<int>(n + 1));
        Dp[0][1] = nums[0], Dp[1][1] = nums[0];
        for (int i = 1; i < n; i++)
        {
            if ((nums[i] - Dp[0][len1]) * Ispositive)
            {
                Ispositive = -1 * Ispositive;
                Dp[0][++len1] = nums[i];
            }
            if ((nums[i] - Dp[1][len2]) * Isnegative)
            {
                Isnegative = -1 * Isnegative;
                Dp[1][++len2] = nums[i];
            }
        }
         return max(len1, len2);

    }
};