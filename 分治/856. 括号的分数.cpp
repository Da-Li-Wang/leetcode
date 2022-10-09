#include <iostream>
#include <string>
#include <stack>

using namespace std;

//分治，时间复杂度 n^2

class Solution {
public:
    int scoreOfParentheses(string s) {
        int scoer = 0, ans = 0, len = 0, n = s.size();
        if(n == 2) return 1;
        for(int i = 0; i < n; i++)
        {
            scoer += s[i] == '(' ? 1 : -1;
            len++;
            if(!scoer)
            {
                if(len == n) return 2*scoreOfParentheses(s.substr(1, len-2));
                else
                {
                    return scoreOfParentheses(s.substr(0,len)) + scoreOfParentheses(s.substr(len, n - len));
                } 
            }
        }
        return 0;
    }
};

//栈
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        stk.push(0);
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                stk.push(0);
            }
            else
            {
                int temp = stk.top();
                stk.pop();
                stk.top() += max(2*temp, 1);
            }
        }
        return stk.top();
    }
};

//数学
class Solution {
public:
    int scoreOfParentheses(string s) {
        int scoer = 0, ans = 0;
        for(int i = 0; i  < s.size(); i++)
        {
            if(s[i] == '(') scoer++;
            else
            {
                scoer--;
                if(s[i-1] == '(') ans += 1 << scoer;
            }
        }
        return ans;
    }
};
