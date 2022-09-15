#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
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
    int regionsBySlashes(vector<string>& grid) 
    {
        int n = grid.size();


        vector<int> f(n * n * 4);
        for (int i = 0; i < n*n*4; i++)
        {
            f[i] = i;
        }
        

        vector<int> r(n * n * 4);
        for (int i = 0; i < n*n*4; i++)
        {
            r[i] = 1;
        }
        
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int idx = i * n + j;
                if (i < n - 1)
                {
                    int bottom = idx + n;
                    merge(f, r, idx * 4 + 2, bottom*4);
                }
                if (j < n - 1)
                {
                    int right = idx + 1;
                    merge(f, r, idx * 4 + 1, right * 4 + 3);
                }
                if (grid[i][j] == '/')
                {
                    merge(f, r, idx * 4, idx * 4 + 3);
                    merge(f, r, idx * 4 + 1, idx * 4 + 2);
                }
                else if (grid[i][j] == '\\')
                {
                    merge(f, r, idx*4, idx*4 + 1);
                    merge(f, r, idx*4 + 2, idx*4 + 3);
                }
                else{
                    merge(f, r, idx * 4, idx * 4 + 1);
                    merge(f, r, idx * 4 + 1, idx * 4 + 2);
                    merge(f, r, idx * 4 + 2, idx * 4 + 3);
                }    
            }
        }
        unordered_set<int> fathers;
        for (int i = 0; i < n * n * 4; i++)
        {
            int fa = find(f, i);
            fathers.insert(fa);
        }
        return fathers.size();
    }
};