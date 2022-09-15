#include <iostream>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int end = n & 1;
        while (n != 0)
        {
            n = n >> 1;
            end = !end;
            if (n & 1 != end)
            {
                return false;
            }
            
        }
        return true;
    }
};