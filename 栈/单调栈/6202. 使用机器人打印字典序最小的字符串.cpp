//栈 单调性
class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> f(n+1);
        f[n] = 'z' + 1;
        for(int i = n-1; i >-1; --i)
        {
           f[i] = min(s[i], f[i+1]); 
        }

        string ans;
        stack<char> str;
        for(int i = 0; i < n; i++)
        {
            str.push(s[i]);
            while(!str.empty() && str.top() <= f[i+1]) ans.push_back(str.top()), str.pop();
        }

        return ans;
    }
};