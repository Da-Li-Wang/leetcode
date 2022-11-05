//见括号类题常用栈模拟
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        for(auto it : expression)
        {
            if(it == ',') continue;
            else if(it != ')') stk.push(it);
            else
            {
                int f = 0, t = 0;
                while(stk.top() != '(')
                {
                    char c = stk.top();
                    stk.pop();
                    if(c == 'f') f++;
                    else if(c == 't') t++;
                }
                stk.pop();
                char cal = stk.top();
                stk.pop();
                if(cal == '|')
                {
                    if(t > 0) stk.push('t');
                    else stk.push('f');
                    //cout <<  stk.top() << endl;
                }
                else if(cal == '&')
                {
                    if(f > 0) stk.push('f');
                    else stk.push('t');
                    //cout <<  stk.top() << endl;
                }
                else
                {
                    if(f > 0) stk.push('t');
                    else stk.push('f');
                    //cout <<  stk.top() << endl;
                }
            }
        }   
        return stk.top() == 't';
    }
};