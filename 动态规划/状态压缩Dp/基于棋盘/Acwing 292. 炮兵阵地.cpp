#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 11, M = 1 << 10;

int n, m;
int g[110];
vector<int> state,head[M];
int cnt[M];
int f[2][M][M];


bool check(int state)//判断合法状态
{
    for(int i = 0; i < m; i++)
    {
        if((state >> i & 1) && ((state >> i + 1 & 1) || (state >> i+2 & 1)))//均不相邻
            return false;
    }
    return true;
}

int count (int state)//得到炮台个数
{
    int res = 0;
    for(int i = 0; i < m; i++) res += state >> i & 1;
    return res; 
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)//画地图
    {
        for(int j = 0; j < m; j++)
        {
            char c; 
            cin >> c;
            if(c == 'H') g[i] += 1 << j;
        }
    }

    for(int st = 0; st < 1 << m; ++st)//得到所有合法状态
    {
        if(check(st))
            state.push_back(st), cnt[st] = count(st);
    }

    for(int cur : state)
    {
        for(int pre : state)
        {
            if(!(cur & pre))//前后两行不并行
                head[cur].push_back(pre);
        }
    }

    for(int i = 1; i <= n+2; ++i)//得到前n+2行数据
    {
        for(int st : state)
        {
            if(!(g[i] & st))
            {
                for(int p1 : head[st])
                {
                    for(int p2 : head[p1])
                    {
                        if(!(st & p2))//隔行不并行
                        {
                            f[i & 1][st][p1] = max(f[i & 1][st][p1] , f[i-1 & 1][p1][p2] + cnt[st]);//滚动数组优化
                        }
                    }
                }
            }
        }
    }

    cout << f[n+2 &1][0][0];//输出
    return 0;
}