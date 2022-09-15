#include <iostream>
#include <vector>
#include <map>


using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        map<int, int> Menu;
        int count;
        for (int cookies : s)
        {
            Menu[cookies]++;
        }
        for (int ask : g)
        {
            for (auto &item : Menu)
            {
                if (item.first >= ask && item.second > 0)
                {
                    item.second--;
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};