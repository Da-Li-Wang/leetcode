#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//暴力法 多少沾点 时间复杂度 n*k
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k == 0)
        {
            vector<int> ans(n, 0);
            return ans;
        }
        if(k > 0)
        {
            vector<int> ans(n);
            for(int i = 0; i < n; i++)
            {
                int sum = 0;
                for(int j = 1; j <= k; j++)
                {
                    sum += code[(i + j) % n];
                }
                ans[i] = sum;
            }
            return ans;
        }
        if(k < 0)
        {
            vector<int> ans(n);
            for(int i = 0; i < n; i++)
            {
                
                int sum = 0;
                for(int j = 1; j <= -k; j++)
                {
                    sum += code[(i + n - j) % n];
                }
                ans[i] = sum;
            }
            return ans;
        }
        return {};
    }
};

//前缀和 时间复杂度n
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        if(k == 0) return ans;
        vector<int> sum(2*n + 1);//前缀和需要比原数组+1
        for(int i = 1; i < 2*n + 1; ++i)
        {
            sum[i] += sum[i-1] + code[i % n];
        }
        for(int i = 0; i < n; ++i)
        {
            if(k > 0)
            {
                ans[i] = sum[i + k + 1] - sum[i + 1];
            }
            if(k < 0)
            {
                ans[i] = sum[i + n] - sum[i + n - k];
            }
        }
        return ans;
    }
};

//滑动窗口
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        code.resize(2*n);
        if(k == 0) return ans;
        copy(code.begin(), code.begin()+n, code.begin()+n);
        int left = k > 0 ? 1 : n+k;
        int right = k > 0 ? k : n-1;
        int sum = 0;
        
        for(int i = left; i <= right; i++)
        {
            sum += code[i];
        }

        for(int i = 0; i < n; i++)
        {
            ans[i] = sum;
            sum -= code[left];
            sum += code[right+1];
            left++;
            right++;
        }

        return ans;
    }
};