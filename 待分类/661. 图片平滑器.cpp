#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img[0].size();
        int n = img.size();
        vector<vector<int>> out;
        for (int i = 0; i < n; i++)
        {
            vector<int> inside;
            for (int j = 0; j < m; j++)
            {
                inside.push_back(Getit(img, j, i, m, n));
            }
            out.push_back(inside);
        }
        return out;
    }

    int Getit(vector<vector<int>>& img, int position_x, int position_y, int m, int n)
    {
        int sum = 0;
        int count = 0;
        if (position_x - 1 >= 0)
        {
            sum += img[position_y][position_x - 1];
            count++;
        }
        if (position_x + 1 < m)
        {
            sum += img[position_y][position_x + 1];
            count++;
        }
        if (position_y - 1 >= 0)
        {
            sum += img[position_y - 1][position_x];
            count++;
        }
        if (position_y + 1 < n)
        {
            sum += img[position_y + 1][position_x];
            count++;
        }
        if (position_x - 1 >= 0 && position_y - 1 >= 0)
        {
            sum += img[position_y - 1][position_x - 1];
            count++;
        }
        if (position_x + 1 < m && position_y + 1 < n)
        {
            sum += img[position_y + 1][position_x + 1];
            count++;
        }
        if (position_x + 1 < m && position_y - 1 >= 0)
        {
            sum += img[position_y - 1][position_x + 1];
            count++;
        }
        if (position_x - 1 >= 0 && position_y + 1 < n)
        {
            sum += img[position_y + 1][position_x - 1];
            count++;
        }
        sum += img[position_y][position_x];
        count++;
        return sum/count;            
    }
};