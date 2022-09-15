#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

// 时间复杂度过高

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candles;
        vector<int> out;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '|')
            {
                candles.push_back(i);
            }
        }
        for (auto input : queries)
        {
            int ans = 0;
            int begin = -1;
            for (int i = input[0]; i < input[1]; i++)
            {
               
            }
             out.push_back(ans);
        }
        return out;       
    }
};

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
         int n = s.length();
         vector<int> count(n);
         int cnt = 0;
         for (int i = 0; i < n;i++)
         {
             if (s[i] == '*')
             {
                 cnt++;
             }
             count[i] = cnt;
         }
         vector<int> left(n);
         int leftnum = -1;
         for (int i = 0; i < n;i++)
         {
             if (s[i] == '|')
             {
                 leftnum = count[i];
             }
             left[i] = leftnum;
         }
         vector<int> right(n);
         int rightnum = -1;
         for (int i = n-1; i >= 0;i--)
         {
             if (s[i] == '|')
             {
                 rightnum = count[i];
             }
             right[i] = rightnum;
         }
         vector<int> out;
         for (auto vec : queries)
         {
            int vecleft = right[vec[0]];
            int vecright = left[vec[1]];
            if (vecleft == -1 || vecright == -1 || vecright < vecleft)
            {
                out.push_back(0);
            }
            else
            {
                out.push_back(vecright - vecleft);
            }
            
         }
         return out;
    }
};