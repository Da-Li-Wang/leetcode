#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
//超时
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        int ans = INT_MIN;
        for (int i = n; i > 0; i--)
        {
            int temp = 0;
            for (int j = 0; j < n; j++)
            {
                temp += nums[i+j] * j;
            }
            ans = max(temp, ans);
        }
        return ans;
    }
};

//官例
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f = 0, n = nums.size();
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++) {
            f += i * nums[i];
        }
        int res = f;
        for (int i = n - 1; i > 0; i--) {
            f += numSum - n * nums[i];
            res = max(res, f);
        }
        return res;
    }
};
/*
记数组 \textit{nums}nums 的元素之和为 \textit{numSum}numSum。根据公式，可以得到：

F(0) = 0 \times \textit{nums}[0] + 1 \times \textit{nums}[1] + \ldots + (n-1) \times \textit{nums}[n-1]F(0)=0×nums[0]+1×nums[1]+…+(n−1)×nums[n−1]
F(1) = 1 \times \textit{nums}[0] + 2 \times \textit{nums}[1] + \ldots + 0 \times \textit{nums}[n-1] = F(0) + \textit{numSum} - n \times \textit{nums}[n-1]F(1)=1×nums[0]+2×nums[1]+…+0×nums[n−1]=F(0)+numSum−n×nums[n−1]
更一般地，当 1 \le k \lt n1≤k<n 时，F(k) = F(k-1) + \textit{numSum} - n \times \textit{nums}[n-k]F(k)=F(k−1)+numSum−n×nums[n−k]。我们可以不停迭代计算出不同的 F(k)F(k)，并求出最大值。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/rotate-function/solution/xuan-zhuan-shu-zu-by-leetcode-solution-s0wd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


*/