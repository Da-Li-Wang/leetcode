#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        string out;
        stack<int> nums;
        if (num < 0)
        {
            num = abs(num);
            out += "-"; 
        }
        
        while (num >= 7)
        {
            nums.push(num % 7);
            num = num /7;
        }
        out += to_string(num);
        while (!nums.empty())
        {
            out += to_string(nums.top());
            nums.pop();
        }
        return out;
    }
};