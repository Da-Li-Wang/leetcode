#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> record, check;
        for(auto it : t)
        {
            record[it]++;
        }

        int n = s.size(), left = 0, right = 0, vaild = 0, len = INT_MAX, start = 0;
        while (right < n)
        {
            right++;
            if(record.count(s[right]))
            {
                check[s[right]]++;
                if(check[s[right]] == record[s[right]])
                {
                    vaild++;
                }
            }

            while(vaild == record.size())
            {
                if(right - left < len)
                {
                    len = right - left;
                    start = left; 
                }

                if (check.count(s[left]))
                {
                    if(check[s[left]] == record[s[left]])
                    {
                        vaild--;
                    }
                    check[s[left]]--;
                }
                left++;
            }
        }
        return len == INT_MIN ? "" : s.substr(start, len);
    }
};