#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if(trust.empty() && n == 1) return 1;
        vector<int> trustcount = vector<int>(n);
        int max = 0, record = 0;
        for (auto item : trust)
        {
            trustcount[item[1]-1]++;
            if (trustcount[item[1]-1] > max)
            {
                max = trustcount[item[1]-1];
                record = item[1];
                //cout << record <<endl;
            }
        }
        for (auto item : trust)
        {
            if (item[0] == record)
            {
                return -1;
            }
            if (item[1] != record && trustcount[item[1]-1] == max)
            {
                return -1;
            }
        }

        if(max == n-1) return record;
        return -1;
        
    }
};


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegrees(n + 1);
        vector<int> outDegrees(n + 1);
        for (auto& edge : trust) {
            int x = edge[0], y = edge[1];
            ++inDegrees[y];
            ++outDegrees[x];
        }
        for (int i = 1; i <= n; ++i) {
            if (inDegrees[i] == n - 1 && outDegrees[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};

