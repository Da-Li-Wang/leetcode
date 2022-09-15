#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> degrees(n + 1);
        for (auto edge : edges)
        {
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        for (int i = 1; ; i++)
        {
            if (degrees[i] = n - 1)
            {
                return i;
            }
        }
        return NULL;
    }
};