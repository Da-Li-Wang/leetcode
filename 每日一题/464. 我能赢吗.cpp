#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int getmax = 0;
        if (maxChoosableInteger & 1)
        {
            getmax = (1 + maxChoosableInteger) * (maxChoosableInteger / 2 + 1) / 2;
        }
        else
        {
            getmax = (1 + maxChoosableInteger) * (maxChoosableInteger / 2) / 2;
        }
  
        if (desiredTotal <= getmax)
        {
            return true;
        }
        return false;
        
    }
};