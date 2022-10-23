#include <iostream>

using namespace std;

const int M = 100000;
long long f[M];

int main()
{
    int n, m;
    cin >> n >> m;
    f[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        int w;
        cin >> w;
        for(int j = w; j <= m; j++)
        {
             f[j] += f[j-w];
        }
    }

    cout << f[m] << endl;
    return 0;
}