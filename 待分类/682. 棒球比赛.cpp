#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> sum;
        for (auto ch : ops)
        {
            switch (ch[0])
            {
            case '+':
                    int n = sum.size();
                    sum.push_back(sum[n - 1] + sum[n - 2]);
                    break;
            case 'D':
                    sum.push_back(2 * sum.back());
                    break;
            case 'C':
                    sum.pop_back();
                    break;
            default:
                    sum.push_back(stoi(ch));
                    break;
            }
        }
        return accumulate(sum.begin(), sum.end(), 0);
    }
};