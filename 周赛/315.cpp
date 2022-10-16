// 3/4 https://leetcode.cn/circle/discuss/RWOETn/


//与对应负数同时存在的最大正整数

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> record;
        int ans = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0) record.emplace(-nums[i]);
            else
            {
                if(record.emplace(nums[i]))
                {
                    ans = nums[i];
                }
            }
        }
        return ans;
    }
};


// 反转之后不同整数的数目

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        set<int> record;
        for(int i = 0; i < n; i++)
        {
            record.emplace(nums[i]);
            string temp = to_string(nums[i]);
            reverse(temp.begin(), temp.end());
            record.emplace(stoi(temp));
        }
        return record.size();
    }
};

//反转之后的数字和

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; i++)
        {
            string temp = to_string(i);
            reverse(temp.begin(), temp.end());
            int ri = stoi(temp);
            if(ri + i == num) return true;
        }
        return false;
    }
};


//统计定界子数组的数目
//初见

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int left = 0, right = 0;
        
        while(right < nums.size())
        {
            priority_queue<int, vector<int>, less<>> maxque;
            priority_queue<int, vector<int>, greater<>> minque;
            while (right < nums.size() && nums[right] <= maxK && nums[right] >= minK)
            {
                maxque.emplace(nums[right]);
                minque.emplace(nums[right]);
                if (maxque.top() == maxK && minque.top() == minK)
                {
                    ans++;
                }
                right++;
            }
            while (left <= right && maxque.top() == maxK && minque.top() == minK)
            {
                if(nums[left] == maxK) maxque.pop();
                if(nums[left] == minK) minque.pop();
                if(maxque.top() == maxK && minque.top() == minK) ans++, left++;
            }
            
            right++;
            left = right;
                
        }

        return ans;
    }
};

//官解

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ret = 0;
        for(int i = 0, l = -1, r1 = -1, r2 = -1; i < n; ++i) {
            if(nums[i] > maxK || nums[i] < minK) l = i;
            if(nums[i] == maxK) r1 = i;
            if(nums[i] == minK) r2 = i;
            ret += max(0, min(r1, r2) - l);
        }
        return ret;
    }
};