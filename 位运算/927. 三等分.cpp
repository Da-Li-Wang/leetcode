#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if( sum%3 ) return {-1,-1};

        int first = 0, second = 0, third = 0, cur = 0, n = arr.size(), paragraph = sum/3;
        if(paragraph == 0) return {0,2};
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == 1)
            {
                if(cur == 0) first = i;
                else if(cur == paragraph) second = i;
                else if(cur == 2*paragraph) third = i;
                cur++;
            }
        }

        int len = arr.size() - third;
        if(first + len <= second && second + len <= third)
        {
            int i = 0;
            while(third + i < arr.size())
            {
                if(arr[first+i] != arr[third+i] || arr[second+i] != arr[third+i])
                {
                    return{-1, -1};
                }
                i++;
            }
            return {first + len -1, second + len};
        }
        return {-1,-1};

    }
};