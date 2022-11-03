#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double dis(int x1, int y1, int x2, int y2)
    {
        return sqrt((double)pow((x1-x2), 2) + (double)pow((y1-y2), 2));
    }
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int x_max = INT_MIN, y_max = INT_MIN;
        for(auto it : towers)
        {
            x_max = max(x_max, it[0]);
            y_max = max(y_max, it[1]);
        }
        int ansx = 0, ansy = 0, ansqua = 0;

        for(int x = 0; x <= x_max; x++)
        {
            for(int y = 0; y <= y_max; y++)
            {
                int qua = 0;
                for(auto it : towers)
                {
                    double tmp = dis(x,y,it[0],it[1]); 
                    if(pow((x-it[0]), 2) + pow((y-it[1]), 2) <= radius*radius)
                    {
                        qua += (double)it[2]/(1 + tmp);
                    }
                }
                if(qua > ansqua) ansqua = qua, ansx = x, ansy = y;
            }
        }

        return {ansx, ansy};
    }
};