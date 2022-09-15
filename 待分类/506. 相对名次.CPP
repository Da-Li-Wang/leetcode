#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        vector<string> res(score.size());
        map<int, int,greater<int>> list;
        for (int i = 0; i < score.size(); i++)
        {
            list.emplace(score[i], i);
        }
        int num = 1;
        for (auto item : list)
        {
            if (num == 1)
            {
                res[item.second] = "Gold Medal";
            }
            else if(num == 2)
            {
                res[item.second] = "Silver Medal";
            }
            else if(num == 3)
            {
                res[item.second] = "Bronze Medal";
            }
            else
            {
                res[item.second] = to_string(num);
            }
            num++;
        }
        return res;
    }
};