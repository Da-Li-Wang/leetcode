#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (i == j || words[j].size() > words[i].size())
                {
                    continue;
                }
                if (words[i].find(words[j]) != words[i].npos)
                {
                    ans.push_back(words[j]);
                }
            }
            
        }
        return ans;
    }
};