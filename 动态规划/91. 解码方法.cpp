#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        set<string> book;
        int n = s.size();
        for (int i = 1; i < 27; i++)
        {
            book.emplace(to_string(i));
        }
        
        int k = 0, ans = 1, add = 1; 
        for (int i = 0; i < n-1; i++)
        {
            string it = s.substr(i, 2);
            if (book.find(it) == book.end())
            {
                if (s[1] == '0' && (s[0] - '0') > 2)
                {
                    return 0;
                }
                ans *= k;
                k = 0;
                add = 1;
            }
            else
            {
                add++;
                k += add;
                if (i == n-2)
                {
                    ans *= k;
                }
                
            }
         }
         
        return ans;
    }
};

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0') {
                f[i] += f[i - 1];
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                f[i] += f[i - 2];
            }
        }
        return f[n];
    }
};
