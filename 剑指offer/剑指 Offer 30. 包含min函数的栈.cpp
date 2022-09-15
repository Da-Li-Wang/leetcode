#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> helpstk;
    MinStack() {
        helpstk.push(INT_MAX);
    }
    
    void push(int x) {
        stk.push(x);
        helpstk.push(::min(helpstk.top(), x));
    }
    
    void pop() {
        stk.pop();
        helpstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return helpstk.top();
    }
};
