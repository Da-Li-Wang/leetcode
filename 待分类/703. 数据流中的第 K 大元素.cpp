#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, less<int>> topK;
    int topnum;
    KthLargest(int k, vector<int>& nums) {
        topnum  = k;
        for (int i : nums)
        {
            topK.push(i);
        }
    }
    
    int add(int val) {
        topK.push(val);
        while (topK.size() > topnum)
        {
            topK.pop();
        }
        return topK.top();
    }
};
