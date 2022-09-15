#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int all = rolls.size() + n;
        int sum = mean * all;
        int sumrolls = accumulate(rolls.begin(), rolls.end(), 0);
        int sumn = sum - sumrolls;
        if (sumn  > 6 * n || sumn < 1 * n)
        {
            return {};
        }
        
        vector<int> out = vector<int>(n);

        for (int i = 0; i < n; i++)
        {
            int avg = sumn / (n - i);
            out[i] = avg; 
            sumn -= avg;
        }
        
        return out;
    }
};