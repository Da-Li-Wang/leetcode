#include <iostream>
#include <queue>
#include <vector>


using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> Minqueue;
    priority_queue<int, vector<int>, greater<int>> Maxqueue;

    MedianFinder() {

    }
    
    void addNum(int num) {
        if(Maxqueue.size() == Minqueue.size()+1)
        {
            Maxqueue.push(num);
            Minqueue.push(Maxqueue.top());
            Maxqueue.pop();
        }
        else{
            Minqueue.push(num);
            Maxqueue.push(Minqueue.top());
            Minqueue.pop();
        }
    }
    
    double findMedian() {
        if(Maxqueue.size() > Minqueue.size())
        {
            return Maxqueue.top();
        }
        else
        {
            return (Maxqueue.top() + Minqueue.top())/2;
        }
    }
};
