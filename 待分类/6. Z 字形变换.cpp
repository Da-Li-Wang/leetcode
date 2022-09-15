#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if ( numRows == 1|| numRows >= n)
        {
            return s;
        }
        vector<string> record(numRows);
        for (int i = 0, x = 0, t = 2 * numRows - 2; i < n; i++)
        {
            record[x] += s[i];
            i % t < numRows - 1 ? x++ : x--;
        }
        for (int i = 1; i < numRows; i++)
        {
            record[0] += record[i]; 
        }
        return record[0];
    }
};