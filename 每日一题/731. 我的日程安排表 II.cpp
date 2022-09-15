#include <iostream>
#include <vector>
#include <map>
using namespace std;

//应该用线段树


/*
线段树解决的是「区间和」的问题，且该「区间」会被修改
*/


//差分解法

class MyCalendarTwo {
public:
    map<int, int> cnt;
    
    bool book(int start, int end) {
        int count = 0;
        cnt[start]++;
        cnt[end]--;//不能为n-1 因为到end才消除
        for (auto [_, it] : cnt)
        {
            count += it;
            if (count > 2)
            {
                cnt[start]--;
                cnt[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */