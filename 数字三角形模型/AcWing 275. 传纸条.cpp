#include <iostream>

using namespace std;

const int N = 55;

int n,m;
int g[N][N];
int f[N*2][N][N];

int main()
{
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }

    for(int k = 2; k <= n + m; k++)
    {
        for(int i = 1; i < k; i++)
        {
            for(int j = 1; j < k; j++)
            {
                int temp = g[i][k-i];
                if(i != j)
                {
                    temp += g[j][k-j];
                }
                f[k][i][j] = max(f[k-1][i-1][j] + temp, f[k][i][j]);
                f[k][i][j] = max(f[k-1][i-1][j-1] + temp, f[k][i][j]);
                f[k][i][j] = max(f[k-1][i][j-1] + temp, f[k][i][j]);
                f[k][i][j] = max(f[k-1][i][j] + temp, f[k][i][j]);
            }
        }
    }

    cout << f[n+m][n][n];
    return 0;

}