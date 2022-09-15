#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++)
        {
            swim(nums, i);
        }
        
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > nums[0]) {
                swap(nums[0], nums[i]);
                sink(nums, 0, k - 1);
            }
        }
        return nums[0];
    }
private:
    bool priorityThan(int v1, int v2){ return v1 < v2; }

    void swim(vector<int> &heap, int i)
    {
        while (i > 0 && priorityThan(heap[i], heap[(i-1)/2]))
        {
            swap(heap[i], heap[(i-1) / 2]);
            i = (i-1)/2;
        }
        
    }

    void sink(vector<int>& heap, int i, int N)
    {
        while (2 * i + 1 <= N)
        {
            int j = 2 * i + 1;
            if (j + 1 <= N && priorityThan(heap[j + 1], heap[j])) {
                j++;
            }
            if (priorityThan(heap[i], heap[j])) {
                break;
            }
            swap(heap[i], heap[j]);
            i = j;
        }
        
    }
};

//快排



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size(), nums.size() - k);
    }

    int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q, index);
        }
    }

    int randomPartition(vector<int>& a, int l, int r) {
        int temp;
        temp = a[l];
        int radom = rand() % (r - l) + r;
        a[l] = a[radom];
        a[radom] = temp;

        int pivot = a[l];
        r--;
        while (l <  r)
        {
            while (l < r)
             {
                if (pivot - a[r] < 0)
                {
                    r--;
                }
                else
                {
                    a[l++] = a[r];
                    break;
                }
            }
            while (l < r)
            {
                if (pivot - a[l] > 0)
                {
                    l++;
                }
                else
                {
                    a[r--] = a[l];
                    break;
                }
                
            }  
        }
        a[r] = pivot;
        return l;
    }
};