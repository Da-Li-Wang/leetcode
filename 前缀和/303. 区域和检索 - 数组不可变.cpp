#include <iostream>
#include <vector>

using namespace std;

//线段树
class NumArray {
public:
    vector<int> sums;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            sums[i + 1] = sums[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }
};


//线段树--懒计算

class NumArray {
private:
    vector<int> sumArr;
    int count = 0;
public:
    NumArray(vector<int>& nums) {
        sumArr = nums;
    }
    
    int sumRange(int i, int j) {
       
        while(count <= j){
            sumArr[count] = sumArr[count] + (count > 0? sumArr[count - 1] : 0);
            ++count;
         }
        return sumArr[j] - (i > 0? sumArr[i - 1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */