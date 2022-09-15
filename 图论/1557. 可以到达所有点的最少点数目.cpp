#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inedges = vector<int>(n);
        vector<int> outedges = vector<int>(n);

        for (auto it : edges)
        {
            int innum = it[1];
            inedges[innum]++;
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (inedges[i] == 0)
            {
                ans.push_back(i);
            }
            
        }
        
        return ans;
        
    }
};