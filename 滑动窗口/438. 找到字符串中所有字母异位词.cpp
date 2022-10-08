#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> record, check;
        for(auto it : p) record[it]++;
        vector<int> ans;
        if(s.size() < p.size()) return {};
        int right = 0, left = 0, vaild = 0;
        while(right < p.size())
        {
            if(record.count(s[right]))
            {
                check[s[right]]++;
                if(check[s[right]] == record[s[right]])
                {
                    vaild++;
                }
            }
            if(vaild == record.size()) ans.push_back(left); 
            right++;
        }


        while(right < s.size())
        {
            if(record.count(s[right]))
            {
                check[s[right]]++;
                if(check[s[right]] == record[s[right]])
                {
                    vaild++;
                }
            }
            right++;

            if(record.count(s[left]))
            {
                
                if(check[s[left]] == record[s[left]])
                {
                    vaild--;
                }
                check[s[left]]--;
            }
            left++;
            if(vaild == record.size()) ans.push_back(left);
        }
        return ans;
    }
};