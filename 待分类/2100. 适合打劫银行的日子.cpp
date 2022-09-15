#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) 
    {
        if (security.size() < 2 * time + 1) return {};
        
        if(time == 0)
        {
            vector<int> out;
            for(int n = 0; n < security.size(); n++)
            {
                out.push_back(n);
            }
            return out;
        }
        set<int> countbefore = beforeisok(security, time);
        set<int> countafter = afterisok(security, time);
        vector<int> out;
        for (int i : countafter)
        {
            if (countbefore.count(i))
            {
                out.push_back(i);
            }
            
        }
        return out;
    }
    set<int> beforeisok(vector<int>& security, int time)
    {
        int days = 0;
        set<int> countbefore;
        for (int i = 0; i < security.size() - time; i++)
        {
            if (security[i] >= security[i + 1])
            {
                days++;
                if ( i >= time && days >= time)
                {
                   countbefore.emplace(i);
                }
                if ( i + 1 >= time && days >= time)
                {
                    countbefore.emplace(i+1);
                }
            }
            else
            {
                days = 0;
            }
        }
        return countbefore;
    }
    set<int> afterisok(vector<int>& security, int time)
    {
        int days = 0;
        set<int> countafter;
        for (int i = security.size()-1; i > time; i--)
        {
            
            if (security[i] >= security[i - 1] )
            {
                days++;
                if ( i < security.size() - time && days >= time)
                {
                   countafter.emplace(i);
                }
                if ( i-1 < security.size() - time && days >= time)
                {
                    countafter.emplace(i-1);
                }
            }
            else
            {
                days = 0;
            }
        }
        return countafter;
    }

};