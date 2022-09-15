#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        if (n==1)
        {
            return 0;
        }
        int ans = 0;
        for (int num = 0; num < m; num++)
        {
            for (int i = 1; i < n; i++)
            {
                if(strs[i][num] < strs[i-1][num]) 
                {
                    ans++;
                    break;
                }
            }
            
        }
        return ans;
        
    }
};