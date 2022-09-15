#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> record;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == c)
            {
                record.push_back(i);
            }
            
        }
        
        int first = 0;
        int second = 1;
        vector<int> ans;
        for (int i = 0; i < s.length(); i++)
        {
            if (i <= record[first] || record.size() == 1)
            {
                ans[i] = abs(i - record[first]);
            }
            else if (record.size()> 1 && i > record[first] && i <= record[second])
            {
                ans[i] = min(abs(i - record[first]), abs(i - record[second]));
            }
            else if (record.size()> 1 && i > record[second] )
            {
                if (second + 1 < s.length())
                {
                    second++;
                    first++;
                }
                ans[i] = min(abs(i - record[first]), abs(i - record[second]));
            }  

        }
            return ans;
    }
};