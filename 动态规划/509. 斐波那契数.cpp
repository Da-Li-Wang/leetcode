#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n < 2)
        {
            return n;
        }
            int a = 0, b = 1, temp;
            for (int i = 1; i < n; i++)
            {
                temp = b;
                b = a + b;
                a = temp;
            }
            return b;
          
    }
};