#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        sort(citations.begin(), citations.end());
        int record = 0;
        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i]>= citations.size() - i )
            {
                record = citations.size() - i;
                break;
            }
        }
        return record;
    }
};


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), tot = 0;
        vector<int> counter(n + 1);
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) {
                counter[n]++;
            } else {
                counter[citations[i]]++;
            }
        }
        for (int i = n; i >= 0; i--) {
            tot += counter[i];
            if (tot >= i) {
                return i;
            }
        }
        return 0;
    }
};

