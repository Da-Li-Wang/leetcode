#include <iostream>
#include <vector>
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* begin = root;
        queue<TreeNode*> list;
        list.push(root);
        int count = 1, record = 1;;
        if (!list.empty())
        {
            if (count == depth - 1)
            {
                while (record)
                {
                    auto it = list.front();
                    list.pop();
                    if (it->left)
                    {
                        auto temp = it->left;
                        it->left =  new TreeNode(val);
                        it->left->left = temp;
                    }
                    if (it->right)
                    {
                        auto temp = it->right;
                        it->right =  new TreeNode(val);
                        it->right->right = temp;
                    }
                    record--;
                }
                return root;
            }
            
            while (record)
            {
                auto it = list.front();
                list.pop();
                if (it->left)
                {
                    list.push(it->left);
                }
                if (it->right)
                {
                    list.push(it->right);
                }
                record--;
            }
            record = list.size();
            count++;
        }
        return root; 
    }
};