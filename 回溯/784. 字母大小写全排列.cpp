#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> ans;
    void dfs(string cur ,string s, int pos)
    {
        if(pos == s.size()) 
        {
            ans.push_back(cur);
            return;
        }

        if(isdigit(s[pos]))
        {
            cur.push_back(s[pos]);
            dfs(cur, s, pos+1);
        }
        else
        {
            cur.push_back(s[pos]^32);
            dfs(cur, s, pos+1);
            cur.pop_back();
            cur.push_back(s[pos]);
            dfs(cur, s, pos+1);
        }
         
    }

    vector<string> letterCasePermutation(string s) {
        dfs("", s, 0);
        return ans;
    }
};