  #include <iostream>
  #include <vector>
  #include <cstring>
  using namespace std;
//朴素解法
int main()
{
    int n, c;
    cin >> n >> c;

    vector<int> v(n+1),w(n+1),s(n+1);
    vector<vector<int>> f(n+1, vector<int>(c+1));
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            for(int k = 0; k <= s[i] && k*v[i] <= j; k++)
            {
                f[i][j] = max(f[i][j], f[i-1][j - v[i]*k] + w[i]*k);
            }
        }
    }

    cout << f[n][c];
    return 0;
}




// logs 优化
//转化为01背包
  int main(){
    int n, c;
    cin >> n >> c;
    
    int cnt = 0;
    vector<int> v(25000), w(25000);
    for(int i = 1; i <= n; i++)
    {
        int a,b,s;
        cin >> a >> b >> s;
        int k = 1;
        while (k <= s)
        {
            cnt++;
            v[cnt] = a*k;
            w[cnt] = b*k;
            s -= k;
            k *= 2;
        }
        if(s > 0)
        {
            cnt++;
            v[cnt] = a*s;
            w[cnt] = b*s;
        }
    }
    
    vector<int> f(c+1);

    n = cnt;
    for(int i = 1; i <= n; i++)
    {
        for(int j = c; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j-v[i]] + w[i]);
        }
    }

    cout << f[c];
    return 0;
  }

  //滑动窗口 + 单调队列优化
 
const int N = 20010;
int dp[N], pre[N], q[N];
int n, m;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        memcpy(pre, dp, sizeof(dp));
        int v, w, s;
        cin >> v >> w >> s;
        for(int j = 0; j < v; j++)
        {
            int head = 0, tail = -1;
            for(int k = j; k <= m; k += v)
            {
                if(head <= tail && k - s*v > q[head]) ++head;
                
                while (head <= tail && pre[q[tail]] - (q[tail]-j)/v * w <= pre[k] - (k-j)/v * w)
                {
                    tail--;
                }

                if(head <= tail) dp[k] = max(dp[k], pre[q[head]] + (k - q[head])/v * w);

                q[++tail] = k;
            }
        }
    }

    cout << dp[m];
    return 0;
}