#include <iostream>
#include <vector>

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
    vector<int> nums;
    void dfs(TreeNode* root)
    {
        if(!root) return;
        if(root->left) dfs(root->left);
        nums.push_back(root->val);
        if(root->right) dfs(root->right);
    }

    TreeNode* Maketree(vector<int> nums,int left, int right)
    {
        if(left >= right) return nullptr;
        int maxnum = -1, maxptr = -1;
        for(int i = left; i < right; i++)
        {
            if(nums[i] > maxnum)
            {
                maxnum = nums[i];
                maxptr = i;
            }
        }
        TreeNode* root = new TreeNode(maxnum);
        root->left = Maketree(nums, left, maxptr);
        root->right = Maketree(nums, maxptr + 1, right);
        return root;
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* Node = new TreeNode(val);
        if(Node->val > root->val)
        {
            Node->left = root;
            return Node;
        }

        dfs(root);
        nums.push_back(val);
        return Maketree(nums, 0, nums.size());
    }
};

//递归解法

class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(!root)   return new TreeNode(val);
        if(root->val < val){
            TreeNode* p = new TreeNode(val);
            p->left = root;
            return p;
        }else{
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
    }
};
