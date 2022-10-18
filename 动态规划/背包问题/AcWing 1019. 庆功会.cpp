#include <iostream>

using namespace std;

const int N = 6010;

int f[N];
int main()
{
    int n ,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        for(int j = m; j >= 0; j--)
        {
            for(int k = 0; k <= s; k++)
            {
                if(j >= k*v )f[j] = max(f[j], f[j - k*v] + w*k);
            }
        }
    }

    cout << f[m];
    return 0;
}