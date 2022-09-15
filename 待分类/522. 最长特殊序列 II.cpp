#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        
        for (int i = 0, j; i < strs.size(); i++)
        {
            for (j = 0; j < strs.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (isSubStr(strs[j], strs[i]))
                {
                    break;
                }
            }
            if (j == strs.size())
            {
                ans = max((int)strs[i].length(), ans);
            }
        }
        return ans;
    }
    bool isSubStr(string &a, string &b){//判断a是否为b的子串
        int i = 0;
        for (auto c: b)
            if (i < a.size() && c == a[i]) i++ ;
        return i == a.size();
    }
};

/* 
关于位运算列子数组的方法值得学习
public class Solution {
    public int findLUSlength(String[] strs) {
        HashMap < String, Integer > map = new HashMap < > ();
        for (String s: strs) {
            for (int i = 0; i < (1 << s.length()); i++) {
                String t = "";
                for (int j = 0; j < s.length(); j++) {
                    if (((i >> j) & 1) != 0)
                        t += s.charAt(j);
                }
                if (map.containsKey(t))
                    map.put(t, map.get(t) + 1);
                else
                    map.put(t, 1);
            }
        }
        int res = -1;
        for (String s: map.keySet()) {
            if (map.get(s) == 1)
                res = Math.max(res, s.length());
        }
        return res;
    }
}



*/