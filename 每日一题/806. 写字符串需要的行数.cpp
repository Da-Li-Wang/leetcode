#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int temp = 0, ans = 1;
        for (char it : s)
        {
            if (temp + widths[it - 'a'] > 100)
            {
                temp = widths[it - 'a'];
                ans++;
                continue;
            }
            temp += widths[it - 'a'];
        }
        return {ans, temp};
    }
};