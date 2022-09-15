#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    }; 
    int bestRotation(vector<int>& nums) {
        int max = INT_MIN;
        int score = 0;
        int mink = 0;
        LinkedNode* head = Makelist(nums);
        for (int k = 0; k < nums.size(); k++)
        {
            LinkedNode* cur = head;
            for (int i = 0; i < nums.size(); i++)
            {
                if (cur->val <= i)
                {
                    score++;
                }
                cur= cur->next;
            }
            if (score > max)
            {
                mink = k;
                max = score;
            }
            score = 0;
            head = head->next;
        }
        return mink;
    }
    struct LinkedNode * Makelist(vector<int>& nums)
    {
        LinkedNode* head = new LinkedNode(nums[0]);
        LinkedNode* cur = head;
        for (int i = 1; i < nums.size(); i++)
        {
            cur->next = new LinkedNode(nums[i]);
            cur = cur->next;
        }
        cur->next = head;
        return head; 
    };
    
};