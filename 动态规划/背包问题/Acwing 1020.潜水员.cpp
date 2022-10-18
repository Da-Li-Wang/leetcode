#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


 
const int M = 79, N = 21;
int f[M*N+10][M*N+10];

//花费恰好为ij

int main()
{
    int m, n, k;
    cin >> m >> n >> k;

    memset(f, 1e9, sizeof(f));
    f[0][0] = 0;
    for(int i = 0; i < k; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        for(int j = M*N+9; j >= v1; j--)
        {
            for(int q = M*N+9; q >= v2; q--)
            {
                f[j][q] = min(f[j][q], f[j-v1][q-v2] + w);
            }
        }
    }
    int ans = 1e9;
    for(int i = M*N+9; i >= m; i--)
    {
        for(int j = M*N+9; j >= n; j--)
        {
            ans = min(ans, f[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}



#include <iostream>
#include <cstring>

using namespace std;

const int N = 22, M = 80;

int n, m, K;
int f[N][M];

//花费至少为ij

int main()
{
    cin >> n >> m >> K;

    memset(f, 0x3f, sizeof(f));

    f[0][0] = 0;

    while(K--)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        for(int i = n; i >= 0; i--)
        {
            for(int j = m; j >= 0; j--)
            {
                f[i][j] = min(f[i][j], f[max(i-v1, 0)][max(j-v2, 0)] + w);//当负数时为0
            }
        }
    }


    cout << f[n][m] << endl;
    return 0;
}