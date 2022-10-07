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
    TreeNode* expandBinaryTree(TreeNode* root) {
        return dfs(root);
    }
    TreeNode* dfs(TreeNode* root)
    {
        if(!root) return nullptr;
        if(!root->left && !root->right) return root;
        if(root->left)
        {
            TreeNode* temp = root->left;
            root->left = new TreeNode(-1);
            root->left->left = temp;
            dfs(temp);
        }
        if (root->right)
        {
            TreeNode* temp = root->right;
            root->right = new TreeNode(-1);
            root->right->right = temp;
            dfs(temp);
        }
        return root;
    }
};
