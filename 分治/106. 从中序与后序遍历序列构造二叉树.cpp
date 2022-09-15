#include <iostream>
#include <vector>
#include <map>

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
    map<int, int> record;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            record[inorder[i]] = i;
        }
        
        return Gettree(inorder, postorder, 0, n-1, 0, n-1);
    }
    TreeNode* Gettree(vector<int>& inorder, vector<int>& postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right)
    {
        //边界条件
        if(inorder_left > inorder_right) return nullptr;

        int postorder_root = postorder[postorder_right];
        int index = record[postorder_root];

        int lefttree = index - inorder_left;

        TreeNode* root = new TreeNode(postorder_root);

        root->left = Gettree(inorder, postorder, inorder_left, index - 1, postorder_left, postorder_left + lefttree - 1);

        root->right = Gettree(inorder, postorder, index + 1, inorder_right,postorder_left + lefttree ,postorder_right-1);
        
        return root;
    }
 };