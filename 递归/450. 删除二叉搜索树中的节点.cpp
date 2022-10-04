#include <iostream>

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
    TreeNode* deleteNode(TreeNode* root, int key) {

    }
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->val == key) {
            if (!root->left && !root->right) {
                return nullptr;
            }
            if (!root->right) {
                return root->left;
            }
            if (!root->left) {
                return root->right;
            }
            TreeNode *successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }
            root->right = deleteNode(root->right, successor->val);
            successor->right = root->right;
            successor->left = root->left;
            return successor;
        }
        return root;
    }
};


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *cur = root, *curParent = nullptr;
        while (cur && cur->val != key) {
            curParent = cur;
            if (cur->val > key) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        if (!cur) {
            return root;
        }
        if (!cur->left && !cur->right) {
            cur = nullptr;
        } else if (!cur->right) {
            cur = cur->left;
        } else if (!cur->left) {
            cur = cur->right;
        } else {
            TreeNode *successor = cur->right, *successorParent = cur;
            while (successor->left) {
                successorParent = successor;
                successor = successor->left;
            }
            if (successorParent->val == cur->val) {
                successorParent->right = successor->right;
            } else {
                successorParent->left = successor->right;
            }
            successor->right = cur->right;
            successor->left = cur->left;
            cur = successor;
        }
        if (!curParent) {
            return cur;
        } else {
            if (curParent->left && curParent->left->val == key) {
                curParent->left = cur;
            } else {
                curParent->right = cur;
            }
            return root;
        }
    }
};

