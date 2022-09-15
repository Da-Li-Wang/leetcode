#include <iostream>
#include <vector>
#include <stack>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1, nums2;
        Inorder(root1, nums1);
        Inorder(root2, nums2);

        vector<int> ans;

        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        while (i < m || j < n)
        {
            if (i == m )
            {
                ans.push_back(nums2[j++]);
            }
            else if (j == n)
            {
                ans.push_back(nums1[i++]);
            }
            else{
                if (nums1[i] > nums2[j]){
                    ans.push_back(nums2[j++]);
                }
                else{
                    ans.push_back(nums1[i++]);
                }
            }
        }
        return ans;
    }
    void Inorder(TreeNode* root, vector<int> &nums){
        if (root)
        {
            Inorder(root->left, nums);
            nums.push_back(root->val);
            Inorder(root->right, nums);
        }
    }
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1, st2;
        vector<int> ans;
        while (!st1.empty() || root1 != nullptr || !st2.empty() || root2 != nullptr)
        {
            while (root1 != nullptr)
            {
                st1.emplace(root1);
                root1 = root1->left;
            }
            while (root2 != nullptr)
            {
                st2.emplace(root2);
                root2 = root2->left;
            }
            
            if (!st1.empty() && !st2.empty())
            {
                if (st1.top()->val < st2.top()->val)
                {
                    root1 = st1.top();
                    st1.pop();
                    ans.emplace_back(root1->val);
                    root1 = root1->right;
                }else{
                    root2 = st2.top();
                    st2.pop();
                    ans.emplace_back(root2->val);
                    root2 = root2->right;
                }
            } 
            else if (!st1.empty())
            {
                root1 = st1.top();
                st1.pop();
                ans.emplace_back(root1->val);
                root1 = root1->right;
            }
            else{
                root2 = st2.top();
                st2.pop();
                ans.emplace_back(root2->val);
                root2 = root2->right;
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1, st2;
        vector<int> res;
        while (!st1.empty() || root1 != nullptr || !st2.empty() || root2 != nullptr) {
            while (root1 != nullptr) {
                st1.emplace(root1);
                root1 = root1->left;
            }
            while (root2 != nullptr) {
                st2.emplace(root2);
                root2 = root2->left;
            }
            if (!st1.empty() && !st2.empty()) {
                if (st1.top()->val < st2.top()->val) {
                    root1 = st1.top();
                    st1.pop();
                    res.emplace_back(root1->val);
                    root1 = root1->right;
                } else {
                    root2 = st2.top();
                    st2.pop();
                    res.emplace_back(root2->val);
                    root2 = root2->right;
                }
            } else if (!st1.empty()) {
                root1 = st1.top();
                st1.pop();
                res.emplace_back(root1->val);
                root1 = root1->right;
            } else {
                root2 = st2.top();
                st2.pop();
                res.emplace_back(root2->val);
                root2 = root2->right;
            }
        }
        return res;
    }
};