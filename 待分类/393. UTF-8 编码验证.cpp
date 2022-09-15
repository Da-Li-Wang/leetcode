#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static const int MASK1 = 1 << 7;
    static const int MASK2 = (1 << 7) + (1 << 6);

    bool validUtf8(vector<int>& data) {
        int datalength = data.size();
        int n = 0;
        int index = 0;
        while(index < datalength)
        {
                n = getUtf8(data[index]);
                if (index + n > datalength || n < 0)
                {
                    return false;
                }
                for (int i = index + 1; i < index + n ; i++)
                {
                    if(!isValid(data[i]))
                    {
                        return false;
                    }
                }
                index = index + n ;
        }
                
        
        return true;
    }

    int getUtf8(int num)
    {
        if ((num & MASK1) == 0) {
            return 1;
        }
        int n = 0;
        int mask = MASK1;
        while ((num & mask) != 0) {
            n++;
            if (n > 4) {
                return -1;
            }
            mask >>= 1;
        }
        return n >= 2 ? n : -1;
    }
    bool isValid(int num)
    {
        return (num & MASK2) == MASK1;
    }
};