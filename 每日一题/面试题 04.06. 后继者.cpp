#include <iostream>
#include <vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode *ans = nullptr;
    bool jud = false;
    TreeNode * inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root)
        {
            return NULL;
        }
        if (root->left)
        {
            inorderSuccessor(root->left, p);
        }
        
        if (jud)
        {
            ans = root;
            jud = false;
        }
        
        if (p->val == root->val)
        {
            jud = true;
        }
        
        if (root->right)
        {
            inorderSuccessor(root->right, p);
        }
        return ans;
    }
};


class Solution {
public:
    TreeNode *ans = nullptr;
    bool jud = false;
    TreeNode * inorderSuccessor(TreeNode* root, TreeNode* p) {
     if (root == nullptr || p == nullptr) {
        return nullptr;
    }
    //p节点的值比当前节点的值大或者相等，说明p节点的后继不可能在当前节点的左子树上（因为中序遍历的左子树的值比当前节点的值小）
    //要设法去当前节点的右子树上找
    if (root->val <= p->val) {
        return inorderSuccessor(root->right, p);
    } else {
        //p节点的值比当前节点小了
        //case1 left为null,说明在左子树上没找到，此时返回当前节点root
        //case2 left不为null，说明找到了返回left
        TreeNode* left = inorderSuccessor(root->left, p);
        return left == nullptr ? root : left;
    }
    }
};