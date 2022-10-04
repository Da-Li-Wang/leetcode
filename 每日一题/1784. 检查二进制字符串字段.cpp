#include <iostream>

using namespace std;


//最初解法
class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size(), count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1')
            {
                count++;
                while(i < n && s[i+1] == '1')
                {
                    i++;
                }
            }
        }
        return count <= 1;
    }
};

//官解
class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};
