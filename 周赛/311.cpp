class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n % 2 == 0 || 2 % n == 0) return max(n , 2);
        return 2 * n;
    }
};

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size(), ans = 1;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++)
        {
            if(s[i] == s[i-1]+1)
            {
                dp[i] = dp[i-1] + 1;
                ans = max(ans, dp[i]);
            } 
        }
        return ans;
    }
};


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 //这个也写的非常傻逼 可以直接递归对值交换 我是傻逼！！！！
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* newroot = new TreeNode(root->val);
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> record;
        while (!que.empty())
        {
            int count = que.size();
            vector<int> cell;
            while(count--)
            {
                TreeNode* temp = que.front();
                que.pop();
                cell.push_back(temp->val);
                if(temp->left)
                {
                    que.push(temp->left);
                    que.push(temp->right);
                }
            }
            record.push_back(cell);
        }
        
        int n = record.size();
        queue<TreeNode*> newque;
        newque.push(newroot);
        for(int i = 1; i < n; i++)
        {
            if(i & 1) reverse(record[i].begin(), record[i].end());
            int count = newque.size(), it = 0;
            while(count--)
            {
                TreeNode* temp = newque.front();
                newque.pop();
                temp->left = new TreeNode(record[i][it++]);
                newque.push(temp->left);
                temp->right = new TreeNode(record[i][it++]);
                newque.push(temp->right);
                
            }
        }
        return newroot;
    }
};
//聪明人做法
class Solution {
    public TreeNode reverseOddLevels(TreeNode root) {
        dfs(root.left, root.right, 1);
        return root;
    }

    void dfs(TreeNode l, TreeNode r, int level) {
        if (l == null) {
            return;
        }
        if (level % 2 != 0) {
            int val = r.val;
            r.val = l.val;
            l.val = val;
        }
        dfs(l.left, r.right, level + 1);
        dfs(l.right, r.left, level + 1);
    }
}


//一开始写的 超时了
class Solution {
public:
    unordered_map<string, int> record;
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            Get(words[i]);
        }
        for(int i = 0; i < n; i++)
        {
            int temp = Getit(words[i]);
            ans.push_back(temp);
        }
        return ans;
    }

    void Get(string it)
    {
        int n = it.size();
        string temp = "";
        for(int i = n; i > 0; i--)
            {
                string temp = it.substr(0, i);
                if(!record.count(temp))
                {
                    record.emplace(temp, 1);
                }
                else
                {
                    record[temp]++;
                }
            }
        
        return;
    }
    int Getit(string it)
    {
        int sum = 0,n = it.size();
        for(int i = n; i > 0; i--)
            {
                string temp = it.substr(0, i);
                sum += record[temp];
            }
        return sum;
    }
};

//tire 前缀树解法
class Solution {
public:
    struct Node
    {
        Node* son[26];
        vector<int> ends;
        int score = 0;
    };
    
    vector<int> ans;

    void dfs(Node* node, int sum){
        sum += node->score;
        for(auto i : node->ends)
        {
            ans[i] = sum;
        }
        for(auto it : node->son)
        {
            if(it != nullptr) dfs(it, sum);
            //if(!it) dfs(it, sum); nullptr 不存在 ！nullptr
        }
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        Node* root = new Node();
        for(int i = 0; i < n; i++)
        {
            Node* cur = root;
            for(auto it : words[i])
            {
                it -='a';
                if(cur->son[it] == nullptr) cur->son[it] = new Node();
                cur = cur->son[it];
                ++cur->score;
            }
            cur->ends.push_back(i);
        }
        ans.resize(n);
        dfs(root, 0);
        return ans;
    }
};