#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
        {
            return {{}};
        }
        vector<vector<int>> out;
        queue<Node*> box;
        box.emplace(root);
        while (!box.empty())
        {
            int m = box.size();
            vector<int> temp;
            while (m--)
            {
                Node *tempnode = box.front();
                if (tempnode)
                {
                    temp.push_back(tempnode->val);
                    for (auto item : tempnode->children)
                    {
                        if (item)
                        {
                            box.emplace(item);
                        }
                        
                    }
                    
                }
                box.pop();
            }
            out.push_back(temp);
        }
        return out;
    }
};