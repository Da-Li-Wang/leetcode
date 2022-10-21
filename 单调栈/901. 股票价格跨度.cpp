#include <iostream>
#include <stack>

using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> record;
    int ans;
    StockSpanner() {
        ans = 0;
        record = stack<pair<int, int>>();
    }
    
    int next(int price) {
        while (!record.empty() && price >= record.top().first)
        {
            record.pop();
        }
        
        if(record.empty())
        {
            record.push({price, ans++});
            return ans;
        }

        int temp = ans - record.top().second; 
        record.push({price, ans++});
        return temp;
    }
};