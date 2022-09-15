#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<int> box;
        for (int num : nums)
        {
            while (num > 0)
            {
                int temp = num % 10;
                box.push_back(temp);
                num = num / 10; 
            }
        }
        sort(box.begin(), box.end(), less());
        string out = "";
        for (int i = 0; i < box.size(); i++)
        {
            out += to_string(box[i]); 
        }
        return out;
    }
};