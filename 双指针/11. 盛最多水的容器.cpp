#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n =  height.size(), ptr1 = 0, ptr2 = n-1;
        int ans = 0;
        while(ptr1 < ptr2)
        {
            ans = max(ans ,min(height[ptr1],height[ptr2])*(ptr2 - ptr1)); 
            if(height[ptr1] > height[ptr2]) ptr2--;
            else ptr1++;
        } 
        return ans;
    }
};