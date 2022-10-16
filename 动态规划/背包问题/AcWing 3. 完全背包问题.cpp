#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> v(n+1), w(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    vector<vector<int>> f(n+1, vector<int>(c+1));
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= c; j++)
        {
            f[i][j] = f[i-1][j];
            if(j >= v[i]) f[i][j] = max(f[i-1][j],f[i][j-v[i]] + w[i]);
        }
    }

    cout << f[n][c];
    return 0;
}  

//优化
int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> v(n+1), w(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    vector<int> f(c+1);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = v[i]; j <= c; j++)//空间优化成一维后 只有完全背包问题由小到大循环
        {
            if(j >= v[i]) f[j] = max(f[j],f[j-v[i]] + w[i]);
        }
    }

    cout << f[c];
    return 0;
}  