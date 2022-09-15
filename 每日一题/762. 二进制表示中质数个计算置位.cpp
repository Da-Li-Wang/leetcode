#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++)
        {
            int temp = i;
            int count = 0;
            while (temp)
            {
                if(temp & 1)
                {
                    count++;
                }
                temp = temp >> 1;
            }
            if (isPrime(count))
            {
                ans++;
            }
            
        }
        return ans;
    }

    bool isPrime(int x) {
        if (x < 2) {
            return false;
        }
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

};