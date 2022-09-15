#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for (auto&& p1: points) {
            for (auto && p2: points) {
                for (auto && p3: points) {
                    double x1 = p1[0];
                    double x2 = p2[0]-x1;
                    double x3 = p3[0]-x1;
                    double y1 = p1[1];
                    double y2 = p2[1]-y1;
                    double y3 = p3[1]-y1;
                    double s = abs(x2*y3-x3*y2)/2;
                    ans = max(ans, s);
                }
            }
        }
        return ans;
    }
};
