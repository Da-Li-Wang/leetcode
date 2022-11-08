#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<double, double> PDD;

const int N = 18, M = 1 << N;
const double eps = 1e-6;

PDD q[N];
int path[N][N], f[M], T, n, m;

bool cmp(double a, double b)
{
    if(fabs(a-b) < eps) return true;
    return false;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            cin>> q[i].first >> q[i].second;
        }

        memset(path, 0, sizeof(path));
        for(int i = 0; i < n; i++)
        {
            path[i][i] = 1 << i;
            for(int j = 0; j < n; j++)
            {
                double x1 = q[i].first, y1 = q[i].second, x2 = q[j].first, y2 = q[j].second;

                //计算抛物线
                if(cmp(x1, x2)) continue;
                double a = (y1/x1-y2/x2)/(x1 - x2);
                double b = (y1/x1 - a * x1);
                if(a > 0 || cmp(a, 0.0)) continue; // 需要a < 0

                //计算path[i][j] 覆盖点状态
                for(int k = 0; k < n; k++)
                {
                    double x = q[k].first, y = q[k].second;
                    if(cmp(a*x*x+ b*x, y)) path[i][j] += 1 << k;
                }  
            }
        }

        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for(int i = 0; i < 1 << n; i++)
        {
            int x = 0;
            for(int j = 0; j < n; j++)
            {
                if(i >> j & 1) continue;
                x = j;
                break;
            }

            for(int k = 0; k < n; k++)
            {
                f[i | path[x][k]] = min(f[i | path[x][k]], f[i] + 1);
            }

        }

        cout << f[(1 << n) - 1] << endl;
    }

    return 0;
}

