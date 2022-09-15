#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        long long x = 0, y = 1;
        int index = 0, n = expression.size();
        while (index < n)
        {
            long long x1 = 0, sign = 1;
            if (expression[index] == '-' || expression[index] == '+')
            {
                sign = expression[index] == '-' ? -1 : 1;
                index++;
            }
            while (index < n && isdigit(expression[index]))
            {
                x1 = x1 * 10 + expression[index] - '0';
                index++;
            }

            x1 = sign * x1;
            index++;


            long long y1 = 0;
            while (index < n && isdigit(expression[index]))
            {
                y1 = y1 * 10 + expression[index] - '0';
                index++;
            }

            x = y * x1 + y1 * x;
            y *= y1;
            
        }
        if (x == 0)
            {
                return "0/1";
            }
            long long g = gcd(abs(x), y);
            return to_string(x/g) + "/" + to_string(y/g);
    }
};