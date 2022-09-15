#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//鄙人的愚蠢做法

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        map<int, vector<int>> Record;
        for(int i = 0; i < arr.size(); i++)
        {
            Record[abs(arr[i] - x)].push_back(arr[i]);
        }
        vector<int> ans;
        int cont = 0;
        for(auto it : Record)
        {
            if(cont == k) break;
            if(cont + it.second.size() <= k) 
            {
                ans.insert(ans.end(), it.second.begin(), it.second.end());
                continue;
            }
            for(int i = 0; i < it.second.size(); i++)
            {
                ans.push_back(it.second[i]);
                cont++;
                if(cont == k) break;
            }
        }
        return ans;
    }

};


//聪明蛋的自定义排序

class Solution {
public:
    static int x;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        this->x = x;
        /*
        lambda 函数法
        */
        sort(arr.begin(), arr.end(), [x](int a, int b) -> bool {
            return abs(a - x) < abs(b - x) || abs(a - x) == abs(b - x) && a < b;
        });
        sort(arr.begin(), arr.begin() + k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};

//大聪明蛋的二分查找
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;
        while (k--) {
            if (left < 0) {
                right++;
            } else if (right >= arr.size()) {
                left--;
            } else if (x - arr[left] <= arr[right] - x) {
                left--;
            } else {
                right++;
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};


