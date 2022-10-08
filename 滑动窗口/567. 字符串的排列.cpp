#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>record, check;
        if(s1.size() > s2.size()) return false;
        for(auto it : s1)
        {
            record[it]++;
        }
        
        int left = 0, right = 0, vaild = 0;
        while (right < s2.size())
        {
            if(record.count(s2[right]))
            {
                check[s2[right]]++;
                if(check[s2[right]] == record[s2[right]])
                {
                    vaild++;
                }
            }
            right++;

            while(right-left > s1.size())
            {
                if(record.count(s2[left]))
                { 
                    if(check[s2[left]] == record[s2[left]])
                    {
                        vaild--;
                    }
                    check[s2[left]]--;
                }
                left++;
            }
            if(vaild == record.size()) return true;
        }
        return false;
    }
};