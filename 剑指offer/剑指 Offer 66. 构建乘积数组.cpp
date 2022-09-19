#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        if(n <= 1) return a;
        vector<int> ans(n);
        ans[0] = 1;
       

        for(int i = 1; i < n; i++)
        {
            ans[i] = a[i-1]*ans[i-1];
        }

        int R = 1;
        for(int i = n-1; i > -1; i--)
        {
            ans[i] = ans[i]*R;
            R *= a[i];
        }
        return ans;
    }
};