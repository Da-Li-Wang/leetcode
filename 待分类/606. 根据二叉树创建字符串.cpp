#include <iostream>
#include <string>

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
    string res;
    string tree2str(TreeNode* root) {
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        res += to_string(root->val);
        if(!root->left && !root->right) return;
        res +=  '(';
        dfs(root->left);
        res += ")";
        if(root->right){
            res += '(';
            dfs(root->right);
            res += ')';
        }
    }
};

class Solution {
public:
    string tree2str(TreeNode* root) {
        if (!root)
        {
            return "()";
        }
        if (!root->left && !root->right )
        {
            return to_string(root->val);
        }
        if (!root->left && root->right)
        {
            return to_string(root->val) + "()" + "(" + tree2str(root->right) + ")";
        }
        if (root->left && !root->right)
        {
            return to_string(root->val) + "(" + tree2str(root->left) + ")";
        }
      
            return to_string(root->val) + "(" + tree2str(root->left) + ")" + "(" + tree2str(root->right) + ")";
    }
   

};

class Solution {
public:
    string res;
    string tree2str(TreeNode* root) {
        if (!root)
        {
            res +=  "()";
        }
        if (!root->left && !root->right )
        {
            res += to_string(root->val);
        }
        if (!root->left && root->right)
        {
            res += to_string(root->val) + "()" + "(" + tree2str(root->right) + ")";
        }
        if (root->left && !root->right)
        {
            res += to_string(root->val) + "(" + tree2str(root->left) + ")";
        }
      
        res += to_string(root->val) + "(" + tree2str(root->left) + ")" + "(" + tree2str(root->right) + ")";
        return res;
    }
   

};