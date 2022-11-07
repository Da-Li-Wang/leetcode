#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> dealpart(string part)
    {
        int n = part.size();
        vector<string> temp;
        if(part == "0" || part[0] == 0)
        {
            temp.push_back(part);
        }

        for(int pos = 1; pos < n; pos++)
        {
            if((part[0] == '0' && pos == 1) || part.back() == "0")
            {
                continue;
            }
            temp.push_back(part.substr(0,pos) + "." + part.substr(pos));
        }
        return temp;
    }
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        int n = s.size();
        
        s = s.substr(1, n-2);
        
        for(int i = 1; i < n-2; i++)
        {
            vector<string> left, right;
            left = dealpart(s.substr(0, i));
            if(left.empty()) continue;
            right = dealpart(s.substr(i, n-2-i));
            if (right.empty()) continue;
            for(auto it : left)
            {
                for(auto itt : right)
                {
                    ans.push_back("(" + it + "," + itt + ")");
                }
            } 
        }

        return ans;
    }
};


class Solution {
public:
    vector<string> getPos(string s) {
        vector<string> pos;
        if (s[0] != '0' || s == "0") pos.push_back(s);
        for (int p = 1; p < s.size(); ++p) {
            if ((p != 1 && s[0] == '0') || s.back() == '0') continue;
            pos.push_back(s.substr(0, p) + "." + s.substr(p));
        }
        return pos;
    }
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size() - 2;
        vector<string> res;
        s = s.substr(1, s.size() - 2);
        for (int l = 1; l < n; ++l) {
            vector<string> lt = getPos(s.substr(0, l));
            if (lt.empty()) continue;
            vector<string> rt = getPos(s.substr(l));
            if (rt.empty()) continue;
            for (auto& i : lt) {
                for (auto& j : rt) {
                    res.push_back("(" + i + ", " + j + ")");
                }
            }
        }
        return res;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/ambiguous-coordinates/solutions/1951931/mo-hu-zuo-biao-by-leetcode-solution-y1yz/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。