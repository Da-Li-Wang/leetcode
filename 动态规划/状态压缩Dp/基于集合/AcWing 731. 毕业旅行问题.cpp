#include <iostream>
#include <cstring>

using namespace std;

const int N = 20, M = 1 << N;
int f[M][N], w[N][N], n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> w[i][j]; 
        }
    }

    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for(int i = 1; i < 1 << n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i >> j & 1)
            {
                for(int k = 0; k < n; k++)
                {
                    if(i - (1 << j) >> k & 1)
                    {
                        f[i][j] = min(f[i - (1 << j)][k] + w[k][j], f[i][j]);
                    }
                }
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for(int k = 1; k < n; k++) ans = min(f[(1 << n) - 1][k] + w[k][0], ans);
    cout << ans;
    return 0;
}