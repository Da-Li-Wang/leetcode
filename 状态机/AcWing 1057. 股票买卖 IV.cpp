#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010, M = 110;

 int f[N][M][2], w[N];

 int main()
 {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i];

    memset(f, -0x3f, sizeof(f));
    for(int i = 0; i <= n; i++) f[i][0][0] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1] + w[i]);
            f[i][j][1] = max(f[i-1][j][1], f[i-1][j-1][0] - w[i]);
        }
    }

    int ans = 0;
    for(int i = 0; i <= m; i++) ans = max(ans, f[n][i][0]);
    cout << ans;
    return 0;
 }

class Solution {
public:
    const int N = 1010, M = 110;
    int f[1010][110][2];
    int maxProfit(int k, vector<int>& w) {
        int n = prices.size();
        memset(f, -0x3f, sizeof(f));
        for(int i = 0; i <= n; i++) f[i][0][0] = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1] + w[i-1]);
                f[i][j][1] = max(f[i-1][j][1], f[i-1][j-1][0] - w[i-1]);
            }
        }

        int ans = 0;
        for(int i = 0; i <= k; i++) ans = max(ans, f[n][i][0]);
        cout << ans;
        return ans;
    }
};