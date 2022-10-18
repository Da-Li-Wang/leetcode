#include <iostream>

using namespace std;

const int N = 1010;
int f[N];
int vi[4] = {10, 20, 50, 100};
int main()
{
    int n;
    cin >> n;
    f[0] = 1;//根据 最多 恰好 至少 选择边界设置
    for(int i = 0; i < 4; i++)
    {
        int v = vi[i];
        for(int j = v; j <= n; j++)//根据 最多 恰好 至少 选择边界设置
        {
            f[j] = f[j]+ f[j-v];
        }
    }

    cout <<f[n];
    return 0;
}