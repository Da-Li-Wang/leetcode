#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumAli = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumBob = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int wanted = sumAli - sumBob;
        if (wanted & 1)
        {
            return {};
        }
        wanted /= 2;
        for (int i = 0; i < aliceSizes.size(); i++)
        {
            for (int j = 0; j < bobSizes.size(); j++)
            {
                if (aliceSizes[i] - bobSizes[j] == -wanted)
                {
                    return{aliceSizes[i], bobSizes[j]};
                }
                
            }
            
        }
        return {};
    }
};