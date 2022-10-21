#include <iostream>

using namespace std;

const int N = 30010;
int f[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int w, l;
        cin >> w >> l;
        l = w*l;
        for(int j = n; j >= w; j--)
        {
            f[j] = max(f[j], f[j-w] + l);
        }
    }

    cout << f[n];
    return 0;
}