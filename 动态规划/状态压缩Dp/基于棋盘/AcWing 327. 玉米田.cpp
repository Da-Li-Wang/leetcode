#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 14, M = 1 << 12, mod = 1e8;

int n,m;
int g[N];//原有地图记录
vector<int> state;
vector<int> head[M];//可以从 M 状态开始转移的状态集合 
int f[N][M];

bool check(int state)
{
    for(int i = 0; i < m; i++)
    {
        if((state >> i & 1) && (state >> i+1 & 1)) return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            g[i] += !t << j;//原有地图记录（原有1代表能播种，需转换为0，反之亦然）
        }
    }

    for(int i = 0; i < 1 << m; i++)
    {
        if(check(i)) state.push_back(i);//所有不相邻播种状态
    }

    for(int i = 0; i < state.size(); i++)
    {
        for(int j = 0; j < state.size(); j++)
        {
            int a = state[i], b = state[j];
            if((a & b) == 0)
                head[i].push_back(j);//所有不相邻播种状态
        }
    }

    f[0][0] = 1;
    for(int i = 1; i <= n+1; i++)
    {
        for(int a = 0; a < state.size(); a++)
        {
            for(int b : head[a])
            {
                if(g[i] & state[a]) continue;//贫瘠土地
                f[i][a] = (f[i][a] + f[i-1][b]) % mod;
            }
        }
    }

    cout << f[n+1][0] << endl;//多进行一轮

    return 0;
}
