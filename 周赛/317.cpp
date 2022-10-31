// 3/4
// https://leetcode.cn/contest/weekly-contest-317/

// 可被三整除的偶数的平均值 WA:偶数
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, count = 0;
        for(auto it : nums)
        {
            if(it%3 == 0 && (it % 2 == 0))
            {
                sum+=it;
                count++;
            }
        }
        return count == 0 ? 0 : sum/count;
    }
};

//最流行的视频创作者 WA:爆int
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string, long long> record;
        map<string, pair<int, string>> record2;
        int n = creators.size();
        long long temp1 = -1;
        vector<vector<string>> ans;
        vector<string> names;
        for(int i = 0; i < n; i++)
        {
            record[creators[i]] += views[i];
            
            
            if(!record2.count(creators[i]) || record2[creators[i]].first < views[i])
            {
                record2[creators[i]].first = views[i];
                record2[creators[i]].second = ids[i];
            }
            else if(record2[creators[i]].first == views[i])
            {
                if(record2[creators[i]].second > ids[i])
                {
                    record2[creators[i]].second = ids[i];
                }
            }
            


            if(record[creators[i]] == temp1)
            {
                names.push_back(creators[i]);
            }
            else if(record[creators[i]] > temp1)
            {
                temp1 = record[creators[i]];
                names.clear();
                names.push_back(creators[i]);
            }
        }

        for(int i = 0; i < names.size(); i++)
        {
            ans.push_back({names[i], record2[names[i]].second});
        }

        return ans;

    }
};

//美丽整数的最小增量 WA:tle
class Solution {
public:
    long long getsum(long long n)
    {
        long long sum = 0;
        while(n)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }


    long long makeIntegerBeautiful(long long n, int target) {
        long long ans = 0, add = 0, temp = n;
        string copy = to_string(n);
        int idx = copy.size() - 1;
        while(1)
        {
            if(getsum(temp) <= target) return ans;
            ans += (10 - (copy[idx] - '0') - add) * pow(10, (copy.size() - 1) - idx);
            add = 1;
            idx--;
            temp = n + ans;
        }
        return ans;
    }
};

//移除子树后的二叉树高度 没时间做 两次遍历
class Solution {
public:
    int maxdepth = 0;
    unordered_map<int, int> lr;
    unordered_map<int, int> rl;
    void dfs(TreeNode* root,int depth, bool ltor)
    {
        if(ltor) lr[root->val] = maxdepth;
        else rl[root->val] = maxdepth;

        maxdepth = max(maxdepth, depth);
        
        if(ltor)
        {
            if(root->left) dfs(root->left, depth+1, ltor);
            if (root->right) dfs(root->right, depth+1, ltor);
        }
        else
        {
            if(root->right) dfs(root->right, depth+1, ltor);
            if (root->left) dfs(root->left, depth+1, ltor);
        }
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int>ans;
        dfs(root, 0, true);
        maxdepth = 0;
        dfs(root, 0, false);

        for(auto it : queries)ans.push_back(max(lr[it], rl[it]));
        return ans;
    }
};



