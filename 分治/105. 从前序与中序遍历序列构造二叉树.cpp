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
    map<int, int> Index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < preorder.size(); i++)
        {
            Index[inorder[i]] = i;
        }

        return Gettree(preorder, inorder, 0, preorder.size()-1, 0, preorder.size()-1);
    }

    TreeNode* Gettree(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right)
    {
        //边界条件
        if(preorder_left > preorder_right) return nullptr;
        int preorder_root = preorder_left;
        int inorder_root = Index[preorder[preorder_root]];

        TreeNode* root = new TreeNode(preorder[preorder_root]);

        cout << inorder_root << endl << preorder_left << endl << preorder_right << endl << "--------" << endl;
        int lefttree = inorder_root - inorder_left;

        root->left = Gettree(preorder, inorder, preorder_left + 1, preorder_left + lefttree, inorder_left, inorder_root - 1);

        root->right = Gettree(preorder, inorder, preorder_left + lefttree + 1, preorder_right, inorder_root + 1, inorder_right);

        return root;
    }


};