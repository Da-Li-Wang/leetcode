#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

// 超时报错
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
        {
            return {};
        }
        if (n == 3)
        {
            int sum = 0;
            for (int i : nums)
            {
                sum += i;
            }
            if (!sum)
            {
                return {nums};
            }
            else{
                return {};
            }
            
        }
        
        vector<vector<int>> out;
        for (int i = 7; i <= 7 * pow(2, n-3); i++)
        {
            int sum = 0, j = 0, cur = i;;
            vector<int> temp;
            while (cur)
            {
                if (cur & 1)
                {
                    temp.push_back(nums[j]);
                    sum += nums[j];
                }
                cur = cur >> 1;
                j++;
            }
            if (temp.size() == 3 && sum == 0)
            {
                if (!out.size())
                {
                    out.push_back(temp);
                }
                else
                {
                    bool input = true;
                    for (auto item : out)
                    {
                        int same = 0;
                        map<int, int> judge;
                        for (auto num : item)
                        {
                            if (!judge.count(num))
                            {
                                judge.emplace(num, 1);
                            }
                            else
                            {
                                judge[num]++;
                            }
                        }
                        for (auto judgenum : temp)
                        {
                            if (judge.count(judgenum))
                            {
                                same++;
                                judge[judgenum]--;
                            }
                        }
                        if (same == 3)
                        {
                            input = false;
                            break;
                        }
                    }
                    if (input)
                    {
                        out.push_back(temp);
                    }
                    
                    
                }
                
                
            }       
        }
        return out;
    }
};

//

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        for (int first = 0; first < n; first++)
        {
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            int third = n - 1;
            int target = - nums[first];
            for (int second = first + 1; second < n; second++)
            {
                if (second > first + 1 && nums[second] == nums[second-1])
                {
                    continue;
                }
                while (second < third && nums[third] + nums[second] > target)
                {
                    third--; 
                }
                if (third == second)
                {
                    break;
                }
                if (nums[third] + nums[second] == target)
                {
                    out.push_back({nums[first], nums[second], nums[third]});
                }
            }
            
        }
        return out;
    }
};