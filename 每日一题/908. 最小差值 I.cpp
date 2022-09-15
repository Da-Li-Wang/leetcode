#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        return maxNum - minNum <= 2 * k ? 0 : maxNum - minNum - 2 * k;
    }
};


/*

要取得[a,b)的随机整数，使用(rand() % (b-a))+ a;

要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;

要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1;

*/
