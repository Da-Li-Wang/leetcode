#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

//直接遍历
class MyCalendar {
public:
   
    vector<pair<int, int>> booked;
    
    bool book(int start, int end) {
        for (auto &[l, r] : booked)
        {
            if (l < end && start < r)
            {
                return false;
            }
            
        }
        booked.emplace_back(start, end);
        return true;
    }
};



//二分查找

class MyCalendar {
    set<pair<int, int>> booked;

public:
    bool book(int start, int end) {
        auto it = booked.lower_bound({end, 0});//起点大于等于 end 的第一个区间
        if (it == booked.begin() || (--it)->second <= start) {
            booked.emplace(start, end);
            return true;
        }
        return false;
    }
};

//线段树

class MyCalendar {
    unordered_set<int> tree, lazy;

public:
    bool query(int start, int end, int l, int r, int idx) {
        if (r < start || end < l) {
            return false;
        }
        /* 如果该区间已被预订，则直接返回 */
        if (lazy.count(idx)) {
            return true;
        }
        if (start <= l && r <= end) {
            return tree.count(idx);
        }
        int mid = (l + r) >> 1;
        return query(start, end, l, mid, 2 * idx) ||
               query(start, end, mid + 1, r, 2 * idx + 1);
    }

    void update(int start, int end, int l, int r, int idx) {
        if (r < start || end < l) {
            return;
        }
        if (start <= l && r <= end) {
            tree.emplace(idx);
            lazy.emplace(idx);
        } else {
            int mid = (l + r) >> 1;
            update(start, end, l, mid, 2 * idx);
            update(start, end, mid + 1, r, 2 * idx + 1);
            tree.emplace(idx);
            if (lazy.count(2 * idx) && lazy.count(2 * idx + 1)) {
                lazy.emplace(idx);
            }
        }
    }

    bool book(int start, int end) {
        if (query(start, end - 1, 0, 1e9, 1)) {
            return false;
        }
        update(start, end - 1, 0, 1e9, 1);
        return true;
    }
};

