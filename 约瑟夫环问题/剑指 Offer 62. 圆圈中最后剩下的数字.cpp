#include <iostream>

using namespace std;


//递归解法
class Solution {
public:
    int lastRemaining(int n, int m) {
        return f(n,m);
    }

    int f(int x, int y){
        if(x == 1) return 0;
        int pre = f(x-1, y);
        return (pre + y) % x;// (y % x + pre) % x
    }
};

//迭代解法
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        for(int i = 2; i <= n; ++i)
        {
            ans = (m  + ans) % i;
        }
        return ans;//求出来的为数组下标
    }
};


//https://blog.csdn.net/u011500062/article/details/72855826