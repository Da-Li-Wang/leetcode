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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++)
        {
            record[postorder[i]] = i;
        }

        return Gettree(preorder, postorder, 0, n-1, 0, n-1);
    }

    TreeNode* Gettree(vector<int>& preorder, vector<int>& postorder, int preorder_left, int preorder_right, int postorder_left, int postorder_right)
    {
        //边界条件
        if (preorder_left > preorder_right ) return nullptr;

        int preorder_root = postorder[postorder_right];

        int index = record[preorder[preorder_left + 1]];

        int lefttree = index - postorder_left + 1;

        TreeNode* root = new TreeNode(preorder_root);

        root->left = Gettree(preorder, postorder, preorder_left + 1, preorder_left + lefttree, postorder_left, index);

        root->right = Gettree(preorder, postorder, preorder_left + lefttree + 1, preorder_right, index + 1, postorder_right-1);

        return root;


    }
};

class Solution {
public:
    map<int, int> record;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++)
        {
            record[postorder[i]] = i;
        }

        return Gettree(preorder, postorder, 0, n-1, 0, n-1);
    }

    TreeNode* Gettree(vector<int>& preorder, vector<int>& postorder, int preorder_left, int preorder_right, int postorder_left, int postorder_right)
    {
        //边界条件
        if (preorder_left > preorder_right ) return nullptr;

        int preorder_root = postorder[postorder_right];
        TreeNode* root = new TreeNode(preorder_root);
        
        //防止越界
        if(preorder_left == preorder_right) return root;

        int index = record[preorder[preorder_left + 1]];

        int lefttree = index - postorder_left + 1;

        root->left = Gettree(preorder, postorder, preorder_left + 1, preorder_left + lefttree, postorder_left, index);

        root->right = Gettree(preorder, postorder, preorder_left + lefttree + 1, preorder_right, index + 1, postorder_right-1);

        return root;
    }
};

