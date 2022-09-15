 #include <iostream>
 #include <vector>
 #include <algorithm>

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
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        
        Getit(root); 

        return ans;
    }
    int Getit(TreeNode* root)
    {
        if(!root) return 0;
        
        
        int left = Getit(root->left), right = Getit(root->right), ansleft = 0, ansright = 0;

        if(root->left && root->left->val == root->val) ansleft = left + 1;
        if(root->right && root->right->val == root->val) ansright = right + 1;

        ans = max(ans, ansleft + ansright);

        return ansleft + ansright;
    }
};