#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
vector<vector<int>> memo;
string s,p;
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        this->s = s;
        this->p = p;
        memo.resize(n+1,vector<int>(m+1,-1));
        return dp(n,m);
    }
    int dp(int i,int j){
        //1. base case
        if(i==0 && j == 0) return true;
        if(i!=0 && j == 0) return false;
        if(i==0 && j!=0){
            if(p[j-1]=='*'){
                memo[i][j] = dp(i,j-2);
                return memo[i][j];
            }
            else{
                memo[i][j] =false;
                return false;
            }
        }
        //2. memo check
        if(memo[i][j]!=-1) return memo[i][j];
        //3. current node operation
        if(s[i-1]==p[j-1] || p[j-1]=='.'){
            memo[i][j] = dp(i-1,j-1);
        }
        else{
            if(p[j-1]!='*'){memo[i][j] = false;}
            else{
                if(s[i-1]==p[j-2] || p[j-2] == '.'){
                memo[i][j] = max(dp(i,j-2),dp(i-1,j-2));
                memo[i][j] = max(memo[i][j],dp(i-1,j));
                }
                else{
                    memo[i][j] = dp(i,j-2);
                }
            }
        }
        return memo[i][j];
    }
};


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if(i == 0) return false;
            if(p[j-1] == '.') return true;
            return s[i-1] == p[j-1];
        };

        vector<vector<int>> f(m+1, vector<int>(n+1));
        f[0][0] = true;

        for(int i = 0; i <= m; i++){
            for(int j = 1; j <= n; j++)
            {
                if(p[j-1] == '*')
                {
                    f[i][j] |= f[i][j-2];
                    if(matches(i, j-1))
                    {
                        f[i][j] |= f[i-1][j];
                    }
                }
                else
                {
                    if(matches(i,j))
                    {
                        f[i][j] |= f[i-1][j-1];
                    }
                }
            }
        }
        return f[m][n];        

    }
};
