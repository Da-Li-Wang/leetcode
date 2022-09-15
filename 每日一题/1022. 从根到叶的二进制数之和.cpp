#include <iostream>
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
    int sumRootToLeaf(TreeNode* root) {
        if (!root->left)
        {
            /* code */
        }
        
    }
    bool isleaf(TreeNode* root)
    {
        if(!root->left && !root->right)
        {
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        stack<TreeNode *> st;
        int val = 0, ret = 0;
        TreeNode *prev = nullptr;
        while (root != nullptr || !st.empty()) {
            while (root != nullptr) {
                val = (val << 1) | root->val;
                st.push(root);
                root = root->left;
            }
            root = st.top();
            if (root->right == nullptr || root->right == prev) {
                if (root->left == nullptr && root->right == nullptr) {
                    ret += val;
                }
                val >>= 1;
                st.pop();
                prev = root;
                root = nullptr;
            } else {
                root = root->right;
            }
        }
        return ret;
    }
};

