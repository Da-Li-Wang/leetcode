#include <iostream>

using namespace std;

const int N = 101;
int n,m;
int w[N][N];
int f[N][N];

int main()
{
    int T ;
    cin >> T;

    while (T--)
    {
        cin >> n;
        cin >> m;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++)
            {
                cin >> w[i][j];
            }
        } 

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                f[i][j] = max(f[i-1][j], f[j-1][i]) + w[i][j];
            }
        }

        cout << f[n][m];
        return 0;
    }
     
}