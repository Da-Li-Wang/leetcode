#include <iostream>

using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int first = -1, second = -1;
        int cur = 0, ans = 0;
        while (n)
        {
            if (n & 1 == 1)
            {
                if (first == -1)
                {
                    first == cur;
                }
                else if(first != -1 )
                {
                    second = first;
                    first = cur;
                    ans = max(first - second, ans);
                }
            }
            n = n >> 1;
            cur += 1;
        }
        return ans;
    }
};