#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> f = vector<int>(26);
        for (int i = 0; i < f.size(); i++)
        {
            f[i] = i;
        }

        vector<int> r = vector<int>(26);

        for (auto str : equations)
        {
            if (str[1] == '=')
            {
                merge(f, r, str[0] - 'a', str[3] - 'a');
            }
        }
        
        for (auto str : equations)
        {
            if (str[1] == '!')
            {
                int first = find(f, str[0] - 'a');
                int second = find(f, str[3] - 'a');
                if(first != second) return false;
            }
        }
        return true;
    }

    int find(vector<int>& f, int x)
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
        else if (r[fy] < r[fx])
        {
            f[fy] = fx;
        }
        else
        {
            f[f[x]] = fy;
            r[fy]++;
        }
    }
};