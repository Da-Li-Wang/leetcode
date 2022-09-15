#include <iostream>
#include <vector>
#include <string>
#include <queue>

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
    vector<vector<string>> printTree(TreeNode* root) {
        int Height = GetHeight(root);
        int row = Height, col = pow(2, Height) - 1;
        vector<vector<string>> ans(row, vector<string>(col, ""));
        dfs(ans, root, 0, (col-1)/2, Height);
        return ans;

    }

    int GetHeight(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        int Left = GetHeight(root->left);
        int Right = GetHeight(root->right);

        return max(Left, Right) + 1;
    }

    void dfs(vector<vector<string>> &ans, TreeNode* root, int r, int c, int height)
    {
        ans[r][c] = to_string(root->val);
        
        if(root->left){
            dfs(ans, root->left, r+1, c - pow(2, height-r-2), height);
        }
        
        if(root->right){
            dfs(ans, root->right, r+1, c + pow(2, height-r-2), height);
        }
    }
};