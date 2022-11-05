#include <iostream>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n < 2)
        {
            return n;
        }
        if (n == 2)
        {
            return 1;
        }

        int a = 0, b = 1, c = 1, d;
        for (int i = 2; i < n; i++)
        {
            d = a;
            a = b;
            b = c;
            c = d + a + b;
        }
        return c;  
    }
};