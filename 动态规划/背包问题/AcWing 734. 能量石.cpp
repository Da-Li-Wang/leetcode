#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 1e5 + 10;

int n, m;
struct Node
{
    int s, e, l;
    bool operator < (const Node& t) const
    {
        return s * t.l < t.s * l;
    }
}a[N];

int f[M];

void solve()
{
    memset(f, -0x3f, sizeof(f));
    f[0] = m = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].s >> a[i].e >> a[i].l, m+= a[i].s;
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= a[i].s; --j)
        {
            int pre = j - a[i].s;
            f[j] = max(f[j], f[pre] + a[i].e - pre * a[i].l);
        }
    }
    int res = 0;
    for(int j = 0; j <= m; ++j)
    {
        res = max(res, f[j]);
    }
    cout << res << endl;
}
int main()
{
    int T = 1, t = 1;
    cin >> T;
    while (T -- )
    {
        cout << "Case #" << t ++ << ": ";
        solve();
    }
    return 0;
}


