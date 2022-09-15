#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        vector<string> out;
        map<string, int> Maplist1;
        map<string, int> Maplist2;
        for (int i = 0; i < list1.size(); i++)
        {
            Maplist1.emplace(list1[i],i);
        }
        for (int i = 0; i < list2.size(); i++)
        {
            Maplist2.emplace(list2[i],i);
        }
        int count = INT_MAX;
        for (auto included : Maplist1)
        {
            if(Maplist2.count(included.first))
            {
                int countnum = Maplist2[included.first] + included.second;
                if (countnum == count)
                {
                     out.push_back(included.first);
                }
                if (countnum < count)
                {
                    out.clear();
                    count = countnum;
                    out.push_back(included.first);
                }
                
            }
        }
        
        return out;
    }
};