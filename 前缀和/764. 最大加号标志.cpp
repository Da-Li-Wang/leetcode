#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int N = 505;
int L2R[N][N], R2L[N][N], U2D[N][N], D2U[N][N];

class Solution {
public:

    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        set<int> record;
        memset(D2U, 0, sizeof(D2U));
        memset(U2D, 0, sizeof(U2D));
        memset(R2L, 0, sizeof(R2L));
        memset(L2R, 0, sizeof(L2R));
        for(auto it : mines)
        {
            record.emplace(it[0] * n + it[1]);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(record.count(i*n + j)) continue;
                L2R[i][j] = (j-1 < 0 ? 0 : L2R[i][j-1]) + 1;
            }
            for(int j = n-1; j >= 0; j--)
            {
                if(record.count(i*n + j)) continue;
                R2L[i][j] = (j+1 >= n ? 0 : R2L[i][j+1]) + 1;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(record.count(j*n + i)) continue;
                U2D[j][i] = (j-1 < 0 ? 0 : U2D[j-1][i]) + 1;
            }
            for(int j = n-1; j >= 0; j--)
            {
                if(record.count(j*n + i)) continue;
                D2U[j][i] = (j+1 >= n ? 0 : D2U[j+1][i]) + 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int temp = min(D2U[i][j], min(U2D[i][j] , min(L2R[i][j], R2L[i][j])));
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};