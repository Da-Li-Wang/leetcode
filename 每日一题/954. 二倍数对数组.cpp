#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
         sort(arr.begin(), arr.end());
         map<int, int> count;
         for (int num : arr)
         {
             count[num]++;
         }
         for (int num : arr)
         {
             if (count[2*num])
             {
                 count[2*num]--;
                 count[num]--;
             }
         }
         for (auto item : count)
         {
             if(item.second != 0) return false;
         }
         
         return true;
    }
};