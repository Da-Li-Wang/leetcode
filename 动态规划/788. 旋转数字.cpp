#include<iostream>
#include <string>
#include <vector>

using namespace std;

//枚举 时间复杂度nlogn

class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            string num = to_string(i);
            bool valid = true, diff = false;
            for (char ch: num) {
                if (check[ch - '0'] == -1) {
                    valid = false;
                }
                else if (check[ch - '0'] == 1) {
                    diff = true;
                }
            }
            if (valid && diff) {
                ++ans;
            }
        }
        return ans;
    }

private:
    static constexpr int check[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
};

//dp 时间复杂度n
class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            if (i == 3 || i == 4 || i == 7 ||
                dp[i % 10] == 1 || dp[i / 10] == 1) {
                dp[i] = 1;
            } else if (i == 2 || i == 5 || i == 6 || i == 9 ||
                dp[i % 10] == 2 || dp[i / 10] == 2) {
                dp[i] = 2;
                count++;
            }
        }
        return count;
    }
};

//数位DP 时间复杂度 logn
class Solution {
public:
    int a[6];
    int dp[6][2];

    int rotatedDigits(int n) {
        memset(dp, -1, sizeof(dp));
        int len = 0;
        while (n) {
            a[++len] = n % 10;
            n /= 10;
        }
        return dfs(len, 0, true);
    }

    int dfs(int pos, int ok, bool limit) {
        if (pos <= 0) {
            return ok;
        }
        if (!limit && dp[pos][ok] != -1) {
            return dp[pos][ok];
        }
        int up = limit ? a[pos] : 9;
        int ans = 0;
        for (int i = 0; i <= up; ++i) {
            if (i == 0 || i == 1 || i == 8) {
                ans += dfs(pos - 1, ok, limit && i == up);
            }
            if (i == 2 || i == 5 || i == 6 || i == 9) {
                ans += dfs(pos - 1, 1, limit && i == up);
            }
        }  
        if (!limit) {
            dp[pos][ok] = ans;
        }
        return ans;
    }
};




