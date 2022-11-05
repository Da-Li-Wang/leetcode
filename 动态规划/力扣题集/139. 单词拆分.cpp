#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> book;
        for (auto it : wordDict)
        {
            book.insert(it);
        }
        int n = s.size();
        vector<bool> Dp(n + 1);
        Dp[0] = true;

        for (int i = 1; i <= n ; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (Dp[j] && book.find(s.substr(j, i -j)) != book.end())
                {
                    Dp[i] = true;
                    break;
                }
                
            }
            
        }
        return Dp[n];
    }
};