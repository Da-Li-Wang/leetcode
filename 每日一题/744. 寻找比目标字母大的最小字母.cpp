#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int record = 0;
        int jud = INT_MAX;
        for (int i = 0; i < letters.size(); i++)
        {
            if ((letters[i] - target) > 0 && (letters[i] - target) < jud)
            {
                jud = letters[i] - target;
                record = i;
            }
            
        }
        if(jud == INT_MAX) return letters[0];
        return letters[record];
    }
};


//二分查找
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n;
         while (l < r) {
            int mid = l + r >> 1;
            if (letters[mid] > target) r = mid;
            else l = mid + 1;
        }
        return letters[r] > target ? letters[r] : letters[0];
    }
};