#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;
        sort(arr.begin(), arr.end());
        map<int, int> book;
        int record = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (!book.count(arr[i]))
            {
                book[arr[i]] = record++;
            }
        }
        
        for (int i = 0; i < arr.size(); i++)
        {
            ans[i] = book[ans[i]];
        }
        return ans;
    }
};