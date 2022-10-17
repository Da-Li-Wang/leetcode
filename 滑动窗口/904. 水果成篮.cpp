#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0, right = 0, size = 0, temp = 0, ans = 0;       
        unordered_map<int, int> record;

        while(right < n)
        {
            if(!record[right])
            {
                size++;
            }
            temp++;
            record[right]++;
            right++;

            while(size > 2)
            {
                record[left]--;
                if(record[left] == 0) size--;
                temp--;
                left++;
            }

            ans = max(ans, temp);
        }
        return ans;
    }
};