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

class CBTInserter {
public:
    TreeNode* root;
    queue<TreeNode*> cestbon;
    CBTInserter(TreeNode* _root) {
        root = _root;

        queue<TreeNode*> box;
        box.push(root);
        while (!box.empty())
        {
            TreeNode* top = box.front();
            box.pop();
            if (top->left)
            {
                box.push(top->left);
            }
            if (top->right)
            {
                box.push(top->right);
            }
            if (!(top->left && top->right))
            {
                cestbon.push(top);
            }           
        }
    }
    
    int insert(int val) {
        TreeNode* child = new TreeNode(val);
        TreeNode* Node = cestbon.front();
        int ans = Node->val;
        if (!Node->left)
        {
            Node->left = child;
        }
        else
        {
            Node->right = child;
            cestbon.pop();
        }
        cestbon.push(child);
        return ans;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */