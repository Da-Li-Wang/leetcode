/*
#include <iostream>
#include <vector>

using namespace std;
    
const int N = 1010, M = 510, K = 110;
int f[K][N][M], v1[K], v2[K];
int main()
{

    int n , m , k;
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) cin >> v1[i] >> v2[i];

    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n ; j++)
        {
            for(int p = 1; p <= m-1; p++)
            {
                f[i][j][p] = f[i-1][j][p];
                if(j - v1[i] >= 0 && p - v2[i] >= 0) f[i][j][p] = max(f[i][j][p], f[i-1][j-v1[i]][p-v2[i]]+1);
            }
        }
    }

    cout << f[k][n][m-1] << ' ';
    int b = m-1;
    while (b > 0 && f[k][n][b-1] == f[k][n][m-1]) b--;
    cout << m - b;
    return 0;
}
*/
#include<iostream>
using namespace std;
const int N = 1010,M = 510, K = 110;
int pb[K],atk[K],f[N][M];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i<=k;i++)cin>>pb[i]>>atk[i];
    
    for(int i = 1;i<=k;i++){
        for(int j = n;j>=pb[i];j--){
            //注意这里血量从m-1开始
            for(int a= m-1;a>=atk[i];a--){
                f[j][a] = max(f[j][a],f[j-pb[i]][a-atk[i]]+1);
            }
        }
    }
    cout<<f[n][m-1]<<' ';
    int r;
    //约束一遍需要的血量的最小值
    for(int i = m-1;i>=0;i--){
        if(f[n][i]==f[n][m-1]){r = i;}
    }
    cout<<m-r<<endl;
    return 0;
}