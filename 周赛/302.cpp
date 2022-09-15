#include <iostream>
#include <vector>
#include <map>

using namespace std;

//6120. 数组能形成多少数对

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        if (nums.size() == 1) return {0,1};

        map<int, int> book;

        for (auto num : nums)
        {
            if (!book.count(num))
            {
                book.emplace(num, 1);
            }
            else
            {
                book[num]++;
            }
        }
        int combine = 0, left = 0;

        for (auto numm : book)
        {
            combine += numm.second / 2;
            left += numm.second % 2;
        }
        
        return {combine, left};
    }
};