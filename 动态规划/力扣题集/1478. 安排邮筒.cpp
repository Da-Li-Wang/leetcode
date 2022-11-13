#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105;

int f[N][N], dis[N][N];//f[i][j] 表示前i个房子送到前j个邮箱的最小值

class Solution {
public:
    int minDistance(vector<int>& h, int k) {
        int n = h.size();
        sort(h.begin(), h.end());

        memset(f, 0x3f, sizeof(f));
        
        for(int i = n-2; i >= 0; --i)
        {
            for(int j = i+1; j < n; ++j)
            {
                dis[i][j] = dis[i+1][j-1] + h[j] - h[i];
            }
        }

        for(int i = 0; i < n; i++)
        {
            f[i][1] = dis[0][i];
            for(int j = 2; j <= k && j <= i+1; ++j)
            {
                f[i][j] = f[i][j-1];
                for(int i0 = 0; i0 <= i; ++i0)
                {
                    f[i][j] = min(f[i][j], f[i - i0][j-1] + dis[i-i0+1][i]);
                }
            }
        }


        return f[n-1][k];
    }
};