#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string temp;
        int n = s.size(), left = 0, ans = 0;
        for(int right = 0; right < n; right++)
        {
            while(!temp.empty() && temp.find(s[right]) != temp.npos)
            {
                temp.erase(temp.begin());
            }
            temp += s[right];
            ans = max(ans, (int)temp.size());
        }
        return ans;
    }
};