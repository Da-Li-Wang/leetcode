//https://leetcode.cn/contest/weekly-contest-313/

//3/4

//2427. 公因子的数目 枚举
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
       int ans = 1, maxans = __gcd(a,b);
        for(int i = 2; i <= maxans;i++)
        {
            if((a % i == 0) && (b % i == 0)) ans++;
        }
        return ans;
    }
};

//2428. 沙漏的最大总和 前缀和
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        vector<vector<int>> record;
        int rows = grid.size(), cols = grid[0].size();
        for(int i = 0; i < rows; i++)
        {
            vector<int> temp(cols);
            for(int j = 0; j < cols; j++)
            {
                if(j == 0)
                {
                    temp[j] = grid[i][0];
                    continue;
                }
                else{
                    temp[j] = temp[j-1] + grid[i][j];
                }
            }
            record.push_back(temp); 
        }

        int ans = 0;
        for(int i = 1; i < rows - 1; i++)
        {
            for(int j = 1; j < cols - 1; j++)
            {
                if(j == 1)
                {
                    ans = max(ans, grid[i][j] + record[i-1][j+1] + record[i+1][j+1]);
                }
                else
                {
                    ans = max(ans, grid[i][j] + record[i-1][j+1] - record[i-1][j-2] + record[i+1][j+1] - record[i+1][j-2]);
                }
            }
        }
        return ans;
    }
};


//2429. 最小 XOR 位运算加贪心
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count2 = 0, count1 = 1;
        while(num2)
        {
            if(num2 & 1) count2++;
            num2 >>= 1;
        }
        vector<int> record;

        int copynum1 = num1;

        while(copynum1)
        {
            if(copynum1 & 1) record.push_back(count1);
            count1++;
            copynum1 >>= 1;
        }

        int ans = 0, n = record.size();

        cout << count2 << endl << n << endl;
        
        if(count2 == n) return num1;
        
        if(count2 < n)
        {
            int j = n-1;
            while(count2--)
            {
                int temp = 1;
                temp = temp << record[j]-1;
                ans += temp;
                j--;
            }

        }
        if(count2 > n)
        {
            int need = count2 - n;
            ans = num1;
            int temp = 1;
            while(need)
            {
                if((ans & temp) == 0)
                {
                    ans += temp;
                    need--;
                }
                temp <<= 1;
            }
        }
        return ans;
    }
};

//2430. 对字母串可执行的最大删除数 动态规划
class Solution {
public:
    int deleteString(string s) {
        int n = s.length();
        int lcp[n+1][n+1];
        memset(lcp, 0, sizeof(lcp));
        for(int i = n-1; i >= 0; --i)
        {
            for(int j = n-1; j > i;--j)
            {
                if(s[i] == s[j])
                {
                    lcp[i][j] = lcp[i+1][j+1] + 1;
                }
            }
        }

        int f[n];
        memset(f, 0, sizeof(f));
        for(int i = n-1; i >= 0; --i)
        {
            for(int j = 1; i + j*2 <= n; ++j)
            {
                if(lcp[i][i+j] >= j)
                {
                    f[i] = max(f[i], f[i+j]);
                }
            }
            ++f[i];
        }
        return f[0];
    }
};