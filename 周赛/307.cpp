#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
/*
class Solution {
public:
    string largestPalindromic(string num) {
        map<char, int> book;
        for(int i = 0; i < num.size(); i++)
        {
            book[num[i]]++;
        }
        int maxji = 0, ans = 0, choose = 0;
        for(int i = 1; i < 10; i++)
        {
            if((book['0' + i] & 1) == 0)
            {
                ans += book['0' + i];
                choose++;
            }
            
            else maxji = max(maxji, book['0' + i]);
        }
        
        if(book['0'] > 0)
        {
            if((book['0'] & 1) > 0 && book['0'] > maxji && choose > 0)
            {
                ans += book['0'];
            }
            else if((book['0'] & 1) == 0 && choose > 0)
            {
                ans += book['0'];
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    string largestPalindromic(string num) {
        int cnt[10] = {0};
        for (char c : num) cnt[c - '0']++;
        // ans 表示对应的部分中的前一半，ans2 是 ans 的倒序
        string ans, ans2;
        // 求回文串两边对应的部分
        for (int i = 9; i >= 0; i--) {
            // 已经枚举到了 0，但是之前从来没有加入过别的数字。此时加入 0 将会导致前导 0，因此直接结束。
            if (i == 0 && ans.empty()) break;
            // 在这部分中出现过的数必须出现偶数次
            int t = cnt[i] / 2;
            for (int j = 0; j < t; j++) ans.push_back(i + '0');
            cnt[i] -= t * 2;
        }
        ans2 = ans;
        reverse(ans2.begin(), ans2.end());
        // 看看是否还有剩下的数，可以作为中间单独的一个数字
        for (int i = 9; i >= 0; i--) if (cnt[i]) {
            // 此时 0 无需跳过，因为单独一个 0 是合法的答案
            ans.push_back(i + '0');
            break;
        }
        return ans + ans2;
    }
};

class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> record(10, 0);
        for(auto it : num)
        {
            record[it - '0']++;
        }

        string ans = "", ans2;

        for(int i = 9; i >= 0; i--)
        {
            if(i == 0 && ans == "") break;
            int t = record[i] / 2;
            for(int j = t; j > 0; j--) ans += ('0' + i);
            record[i] -= 2*t;
        }

        ans2 = ans;
        reverse(ans2.begin(), ans2.end());

        for(int i = 9; i >=0; i--)
        {
            if(record[i] > 0)
            {
                ans += '0' + i;
                break;
            }
        }

        ans = ans + ans2;
        return ans;

    }
};

