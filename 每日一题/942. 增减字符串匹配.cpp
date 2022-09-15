#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int maxnum = s.length(), minnum = 0;
        vector<int> ans;
        for (auto it : s)
        {
            if (it == 'I')
            {
                ans.push_back(minnum++);
            }
            else
            {
                ans.push_back(maxnum--);
            }
            
        }
        ans.push_back(minnum);
        return ans;
    }
};