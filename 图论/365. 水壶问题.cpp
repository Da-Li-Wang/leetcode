#include <iostream>
#include <stack>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;
/*
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z==0)return true;
        if(z<0 || z>x+y)return false;
        stack<int> s;
        set<int> memo;
        s.push(0);
        while(!s.empty()){
            int tmp = s.top();s.pop();
            if(tmp+x<=x+y && memo.insert(tmp+x).second)
                s.push(tmp+x);
            if(tmp+y<=x+y && memo.insert(tmp+y).second)
                s.push(tmp+y);
            if(tmp-x>=0 && memo.insert(tmp-x).second)
                s.push(tmp-x);
            if(tmp-y>=0 && memo.insert(tmp-y).second)
                s.push(tmp-y);
            if(memo.count(z)==1)
                return true;
        }
        return false;
    }
};
*/


class Solution {
public:
    int gcd(int a,int b){
        return b?gcd(b,a%b):a;
    }
    
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) {
            return false;
        }
        if (x == 0 || y == 0) {
            return z == 0 || x + y == z;
        }
        return z %  gcd(x, y) == 0;
    }
};


