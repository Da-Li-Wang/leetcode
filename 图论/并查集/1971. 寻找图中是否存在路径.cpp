#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> f = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            f[i] = i;
        }

        vector<int> r = vector<int>(n);

        for (auto item : edges)
        {
            if (find(f, item[0]) != find(f, item[1]))
            {
                merge( f, r, item[0], item[1]);
            }
        }

        if (find(f, source) == find(f, destination))
        {
            return true;
        }
        return false;
    }
    int find(vector<int>&f, int x)
    {
        while (x != f[x])
        {
            int parent = f[x];
            f[x] = f[parent];
            x = parent;
        }
        return x;
    }

    void merge(vector<int>& f, vector<int>& r, int x, int y)
    {
        int fx = find(f, x);
        int fy = find(f, y);
        if (fx == fy)
        {
            return;
        }

        if (r[fx] < r[fy])
        {
            f[fx] = fy;
        }
        else if(r[fy] < r[fx])
        {
           f[fy] = fx;
        }
        else{
            f[fx] = fy;
            r[fy]++;
        }
    }
};    
