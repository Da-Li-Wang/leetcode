#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>

using namespace std;


//dfs版 不能使用vector 时间复杂度超时
 
class Codec {
public:
    void rserialize(TreeNode* root, string& str) {
        if (root == nullptr) {
            str += "None,";
        } else {
            str += to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }

    string serialize(TreeNode* root) {
        string ret;
        rserialize(root, ret);
        return ret;
    }

    TreeNode* rdeserialize(list<string>& dataArray) {
        if (dataArray.front() == "None") {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        return root;
    }

    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;
        for (auto& ch : data) {
            if (ch == ',') {
                dataArray.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }
        return rdeserialize(dataArray);
    }
};


//bfs版

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // bfs
        string res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root); 

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front) {
                res += to_string(front->val) + ",";
                q.push(front->left);
                q.push(front->right);
            }
            else res += "null,";
        }
        return res.substr(0, res.size() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<string> s = split(data);
        
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(s[0]));
        q.push(root);
        int i = 1;

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (s[i] != "null") {
                front->left = new TreeNode(stoi(s[i]));
                q.push(front->left);
            }
            ++i;
            if (s[i] != "null") {
                front->right = new TreeNode(stoi(s[i]));
                q.push(front->right);
            }
            ++i;
        }
        return root;
    }

    vector<string> split(string& s) {
        vector<string> res;
        int n = s.size();
        int i = 0;

        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] != ',') ++j;
            res.push_back(s.substr(i, j - i));
            i = j + 1;
        }
        return res;
    }
};