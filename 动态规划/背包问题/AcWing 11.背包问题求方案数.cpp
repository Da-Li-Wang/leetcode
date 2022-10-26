#include <iostream>

using namespace std;

int mod = 1e9 + 7;

const int N = 1010;
int f[N], g[N];

int main()
{
    int n , c;
    cin >> n >> c;
    
    g[0] = 1;

    for(int i = 0; i < n; i++)
    {
        int v, w;
        cin >> v >> w;
        for(int j = c; j >= v; j--)
        {
            int maxw = max(f[j], f[j-v] + w);
            int cnt = 0;
            if(maxw == f[j]) cnt += g[j];
            if(maxw == f[j-v]) cnt += g[j-v];
            g[j] = cnt % mod;
            f[j] = maxw;
        } 
    }

    int res = 0;
    for(int i = 0; i < c; i++) res = max(res, f[i]);
    int cnt = 0;

    for(int i = 0; i <= m; i++)
    {
        if(res == f[i]) cnt = (cnt + g[i]) % mod;
    }

    cout << cnt;

    return 0;
}