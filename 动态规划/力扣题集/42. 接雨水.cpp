#include <iostream>
#include <vector>

using namespace std;


//经典动态规划
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3)
        {
            return 0;
        }
        
        vector<int> Dpleftmax(n);
        vector<int> Dprightmax(n);

        Dpleftmax[0] = height[0];
        Dprightmax[n - 1] = height[n -1];
        
        for (int i = 1; i < n; ++i)
        {
            Dpleftmax[i] = max(height[i], Dpleftmax[i-1]); 
        }

        for (int i = n -2; i > -1; --i)
        {
            Dprightmax[i] = max(height[i], Dprightmax[i+1]);
        }

        int ans = 0;

        for (int i = 1; i < n - 1; i++)
        {
            ans += (min(Dpleftmax[i], Dprightmax[i]) - height[i]);
        }
        
        return ans; 
    }
};

//双指针

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        if (n < 3)
        {
            return 0;
        }
        
        int rightmax = height[n - 1], leftmax = height[0], left = 0, right = n - 1, ans = 0;
        while (left < right)
        {
            leftmax = max(leftmax, height[left]);
            rightmax = max(rightmax, height[right]);
            if (height[left] < height[right])
            {
                ans +=  leftmax - height[left];
                ++left;
            }
            else
            {
                ans += rightmax - height[right];
                --right;
            }   
            
        }
        
        return ans;
        

    }
};