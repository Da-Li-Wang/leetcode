#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0) return true;
        queue<int> box;
        box.push(start);

        vector<int> visted = vector<int>(arr.size());

        while (!box.empty())
        {
            int temp = box.front();
            visted[temp] = 1;
            box.pop();
            if (temp + arr[temp] < arr.size() && !visted[temp + arr[temp]])
            {
                if (arr[temp + arr[temp]] == 0)
                {
                    return true;
                }
                box.push(temp + arr[temp]);
            }
            if (temp - arr[temp] < arr.size() && !visted[temp - arr[temp]])
            {
                if (arr[temp - arr[temp]] == 0)
                {
                    return true;
                }
                box.push(temp - arr[temp]);
            }
        } 
        return false;
    }
};

