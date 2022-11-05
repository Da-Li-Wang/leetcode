#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> last(26, -1);
        vector<int> f(n, 1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                if(last[j] != -1)
                {
                    f[i] = (f[last[j]] + f[i]) % mod;
                }
            }
            last[s[i] - 'a'] = i;
        }

        int ans = 0;
        for(int i = 0; i < 26; i++)
        {
            if(last[i] != -1) ans = (ans + f[last[i]]) % mod;
        }
        return ans;
    }
};
  

class Solution {
public:
    int mod = 1e9+7;
    int distinctSubseqII(string s) {
        vector<int> g(26, 0);
        int n = s.size(), total = 0;
        for (int i = 0; i < n; ++i) {
            int oi = s[i] - 'a';
            int prev = g[oi];
            g[oi] = (total + 1) % mod;
           // cout << "----------" <<endl;
            //cout << oi << endl << g[oi] << endl << prev << endl;
            //cout << "----------" <<endl;
            total = ((total + g[oi] - prev) % mod + mod) % mod;//g[oi] - prev 减去原有部分，避免重复计算
        }
        return total;
    }
};