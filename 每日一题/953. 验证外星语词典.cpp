#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() < 2)
        {
            return true;
        }
        
        auto dic = vector<int>(26);
        
        for (int i = 0; i < order.size(); i++)
        {
            dic[order[i] - 'a'] = i;
        }

        for (int i = 1; i < words.size(); i++)
        {
            bool vaild = false;
            for (int j = 0; j < words[i].size() && j < words[i-1].size(); j++)
            {
                if (!vaild && dic[words[i-1][j] - 'a'] > dic[words[i][j] - 'a'])
                {
                    return false;
                }
                if (!vaild && dic[words[i-1][j] - 'a'] < dic[words[i][j] - 'a'])
                {
                    vaild = true;
                    break;
                }
                
                
            }

            if (words[i-1].size() > words[i].size())
            {
                return false;
            }
        }

        return true;
    }
};