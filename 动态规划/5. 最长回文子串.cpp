#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int begin = 0, max = 1;
        vector<vector<bool>> Dp(n, vector<bool>(n));
        for (int r = 1; r < n; r++)
        {
            for (int l = 0; l < r; l++)
            {
                if ((s[l] == s[r]) && (r-l <= 2 || Dp[l+1][r-1]))
                {
                    Dp[l][r] = true;
                    if (r - l + 1 > max)
                    {
                        max = r - l + 1;
                        begin = l;
                    }
                }
                
            }
            
        }
        return s.substr(begin, max);
    }
};