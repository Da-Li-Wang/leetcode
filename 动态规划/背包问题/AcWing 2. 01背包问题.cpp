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
        for(int j = 1; j <= c; j++)
        {
            f[i][j] = f[i-1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i-1][j-v[i]] + w[i]); 
        }
    }

    cout << f[n][c];
    return 0;
}


// 优化
//只用到了f【i-1】层
//j与j-v[i] 均小于j
//若用到上一层的状态时,从大到小枚举, 反之从小到大哦

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> v(n+1), w(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    vector<int> f(c+1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = c; j >= v[i]; j--)
        {
            //f[i][j] = f[i-1][j];
            //if(j >= v[i]) f[i][j] = max(f[i][j], f[i-1][j-v[i]] + w[i]);
             f[j] = max(f[j], f[j-v[i]] + w[i]);
        }
    }

    cout << f[c];
    return 0;
}