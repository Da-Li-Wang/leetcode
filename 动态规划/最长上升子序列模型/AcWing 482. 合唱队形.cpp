#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n ;
    cin >> n;
    vector<int> a(n), f(n), g(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        f[i] = 1;
        for (int j = 0; i < j; j++)
        {
            if(a[i] > a[j]) f[i] = max(f[i], f[j]+1);
        }
    }

    for(int i = n-1; i>-1; i--)
    {
        g[i] = 1;
        for(int j = n-1; j > i; j--)
        {
            if(a[i] > a[j]) g[i] = max(g[i], g[j] + 1);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, f[i] + g[i] - 1);
    }
    cout << n - ans;
    return 0;
}