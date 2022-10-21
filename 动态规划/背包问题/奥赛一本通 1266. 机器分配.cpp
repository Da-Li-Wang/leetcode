#include <iostream>
using namespace std;
const int N = 20, M = 20;

long long f[N][M];
long long n, m;
long long w[N][M];
long long way[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];

    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= j; k++)
                f[i][j] = max(f[i][j], f[i + 1][j - k] + w[i][k]);
        }
    }
    cout << f[1][m] << endl;


    int j = m;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k <= j; k++)
        {
            if (f[i][j] == f[i + 1][j - k] + w[i][k])
            {
                way[i] = k;
                j -= k;
                break;
            }
        }
    }
    if(m == 0) return 0;
    for (int i = 1; i <= n; i++)
        cout << i << " " << way[i] << endl;

    return 0;
}


