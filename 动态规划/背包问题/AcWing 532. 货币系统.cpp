#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105, M = 25010;
int a[N], f[M];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 1; i < n; i++) cin >> a[i];
        sort(a, a+n);

        int m = a[n-1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for(int i = 0; i < n; i++)
        {
            if(!f[a[i]]) ans++;
            for(int j = a[i]; j <= m; j++)
            {
                f[j] += f[j-a[i]];
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}