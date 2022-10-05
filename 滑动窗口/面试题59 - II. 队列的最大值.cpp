#include <iostream>
#include <deque>
#include <queue>

using namespace std;

class MaxQueue {
public:
    deque<int> que;
    queue<int> quee;
    MaxQueue() {
        
    }
    
    int max_value() {
        if(que.empty()) return -1;
        return que.front();
    }
    
    void push_back(int value) {
        while (!que.empty() && value > que.back())
        {
            que.pop_back();
        }
        que.push_back(value);
        quee.push(value);
    }
    
    int pop_front() {
        if(quee.empty()) return -1;
        if(que.front() == quee.front()) que.pop_front();
        int temp = quee.front();
        quee.pop();
        return temp;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */