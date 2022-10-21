#include <iostream>

using namespace std;

const int N = 1010, M = 1010;
int f[N][M];
int v[N], w[N];
int main()
{
    int n, c;
    cin >> n >> c;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for(int i = n; i >= 1; i--)
    {
        for(int j = 0; j <= c; j++)
        {
            f[i][j] = f[i+1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i+1][j-v[i]] + w[i]);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(c >= v[i] && f[i][c] == f[i+1][c-v[i]] + w[i]) cout << i << ' ', c =  c-v[i];
    }

    return 0;
}