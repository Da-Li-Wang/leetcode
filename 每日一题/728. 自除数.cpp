#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i < right + 1; i++)
        {
            if(judge(i, Getnums(i)))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<int> Getnums(int num)
    {
        vector<int> temp;
        while (num)
        {
            temp.push_back(num % 10);
            num /=10;
        }
        return temp;
    }
    bool judge(int num, vector<int> nums)
    {
        for (int i : nums)
        {
            if (i == 0)
            {
                return false;
            }
            if (num % i != 0)
            {
                return false;
            }
        }
        return true;
    }
};