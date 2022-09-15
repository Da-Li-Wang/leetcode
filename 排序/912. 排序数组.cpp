#include <iostream>
#include <vector>

using namespace std;


//官例 归并
class Solution {

    vector<int> temp;
    void merge(vector<int>& nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int mid = (left + right) >> 1;
        merge(nums, left, mid);
        merge(nums, mid+1, right);
        int i = left, j = mid + 1;
        int cnt = 0;
        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
            {
                temp[cnt++] = nums[i++];
            }
            else
            {
                temp[cnt++] = nums[j++];
            } 
        }
        while (i <= mid)
        {
            temp[cnt++] = nums[i++];
        }
        while (j <= right)
        {
            temp[cnt++] = nums[j++];
        }
        for (int i = 0; i < right- left + 1; ++i)
        {
            nums[i + left] = temp[i];
        }
    }
        
 public:       
    vector<int> sortArray(vector<int>& nums) {
        temp.resize(nums.size(), 0);
        merge(nums, 0, nums.size() -1);
        return nums;
    }
};


//自写 归并

class Solution {
public:
    vector<int> temp;
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size());
        return nums;
    }
    void sort(vector<int>& nums, int begin, int end)
    {
        if (end - begin < 2)
        {
            return;
        }
        int mid = (begin + end) >> 1;
        sort(nums, begin, mid);
        sort(nums, mid, end);
        temp = vector<int>((end - begin)>>1);
        int li = 0, le = mid - begin;
        int ri = mid, re = end;
        int ai = begin;
        for (int i = li; i < le; i++)
        {
            temp[i] = nums[begin + i];
        }
        while(li < le)
        {
            if (ri < re && temp[li] > nums[ri] )
            {
                nums[ai++] = nums[ri++];
            }
            else
            {
                nums[ai++] = temp[li++];
            }
        }
    }
};

//快排 官例
class Solution {
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] < pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }
    void randomized_quicksort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};

//快排 小马哥
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size());
        return nums;
    }
    void sort(vector<int>& nums, int begin, int end)
    {
        if (end - begin < 2)
        {
            return;
        }
        int middle = privoIndex(nums, begin, end);
        sort(nums, begin, middle);
        sort(nums, middle+1, end);
    }
    int privoIndex(vector<int>& nums, int begin, int end)
    {
        int temp;
        temp = nums[begin];
        int radom = rand() % (end - begin) + begin;
        nums[begin] = nums[radom];
        nums[radom] = temp;
        
        int pivot = nums[begin];
        end--;
        while (begin < end)
        {
            while (begin < end)
            {
                if (pivot - nums[end] < 0)
                {
                    end--;
                }
                else
                {
                    nums[begin++] = nums[end];
                    break;
                }
            }
            while (begin < end)
            {
                if (pivot - nums[begin] > 0)
                {
                    begin++;
                }
                else
                {
                    nums[end--] = nums[begin];
                    break;
                }
                
            }  
        }
        nums[begin] = pivot;
        return begin;

    }
};

//手写快排
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        Quicksort(nums, 0, n);
    }
    
    void Quicksort(vector<int>& nums, int begin, int end)
    {
        if (begin >= end)
        {
            return;
        }
        int mid = Getcenter(nums, begin, end);
        Quicksort(nums, begin, mid);
        Quicksort(nums, mid + 1, end);
    }
    
    int Getcenter(vector<int>& nums, int begin, int end)
    {
        
        int radom = rand() % (end - begin) + begin;
        int center = nums[radom];
        swap(nums[radom], nums[begin]);
        

        /*
        int temp;
        temp = nums[begin];
        int radom = rand() % (end - begin) + begin;
        nums[begin] = nums[radom];
        nums[radom] = temp;

        int center = nums[begin];
        */
        end--;
        while (begin < end)
        {
            while (begin < end)
            {
                if (center < nums[end])
                {
                    end--;
                }
                else
                {
                    nums[begin++] = nums[end];
                    break;
                }
            }

            while (begin < end)
            {
                if (center > nums[begin])
                {
                    begin++;
                }
                else
                {
                    nums[end--] = nums[begin];
                    break;
                }
            }
        }
        nums[begin] = center;
        return begin;
    }
};

//手写归并
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int end = nums.size();

        Mergesort(nums, 0, end);
    }
    void Mergesort(vector<int>& nums, int begin, int end)
    {
        if (end - begin < 2)
        {
            return;
        }
        int mid = (begin + end) >> 1;
        Mergesort(nums, begin, mid);
        Mergesort(nums, mid, end);
        temp = vector<int>((end - begin)>>1);
        int li = 0, le = mid - begin, ri = mid, re = end;
        int ai = begin;
        for (int i = li; i < le; i++)
        {
            temp[i] = nums[begin + i];
        }
        while (li < le)
        {
            if (ri < re && nums[ri] < nums[li])
            {
                nums[ai++] = nums[ri++];
            }
            else{
                nums[ai++] = temp[li++];
            } 
        }
    }
private:
    vector<int> temp;
};