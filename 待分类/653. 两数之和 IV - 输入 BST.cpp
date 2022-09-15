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
    vector<int> box;
    bool findTarget(TreeNode* root, int k) {
        Getbox(root);
        int left = 0, right = box.size()-1;
        while (left < right)
        {
            if (box[left] + box[right] < k)
            {
                left++;
            }
            else if (box[left] + box[right] > k)
            {
                right--;
            }
            else if (box[left] + box[right] == k)
            {
                return true;
            }
        }
        
        return false;

    }
    void Getbox(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        Getbox(root->left);
        box.push_back(root->val);
        Getbox(root->right);
    }
};