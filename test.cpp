#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
#include <vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
#include <set>
#include <queue>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <string>
using namespace std;
typedef long long ll;
const int maxn = 1e9 + 10;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<int, vector<int>> record;
        for(int i = 0; i < s.size(); i++)
        {
            record[s[i] - 'a'].push_back(i);
        }

        for(auto it : record)
        {
            if((it.second[1] - it.second[0] - 1) != distance[it.first]) return false;
        }
        return true;
    }
};

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
       int need =  abs(endPos - startPos) , mod = 1e9 + 7, ans;
       int more = k - need;
       if (more == 0) return 1;
       if (more < 0 || ((int)more & 1)) return 0;
       int count = more/2;
       
       ans = combo(more, more/2);
       for(int i = 0; i < need; i++)
       {
            ans += combo(more, more/2) - (i+1);
       }

       return ans%mod;  
    }
    int factorial(int n)
{
    int fc=1;
    for(int i=1;i<=n;++i) fc *= i;
    return fc;
}

//计算组合数
/*从n个不同元素中取出m(m≤n)个元素的所有组合的个数，叫做n个不同元素中取出m个元素的组合数。用符号c(n,m) 表示。
组合数公式：c(n,m)=n!/(m! * (n-m)!)
性质：c(n,m) = c(n,m-n)
递推公式：c(n,m) = c(n-1,m-1) + c(n-1,m)
*/
int combo(int n,int m)
{
    int com=factorial(n)/(factorial(m)*factorial(n-m));
    return com;
}
};

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
        {
            return n;
        }
        
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++)
        {
            if(nums[i] & nums[i-1] == 0)
            {
                dp[i] = max(dp[i], dp[i-1] + 1);
            }
        }

        return dp[n-1];

    }
};



class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = nums;
        int ans = 1, max = nums[0];
        for(int i = 1; i < n; i++)
        {
            if((dp[i] & dp[i-1]) >= max && max >= dp[i])
            {
                dp[i] = dp[i] & dp[i-1];
                ans++;
                max = dp[i];
            }
            else if((dp[i] & dp[i-1]) < max && (dp[i] & dp[i-1]) > dp[i]) continue;
            else if(dp[i] >= max && (dp[i] & dp[i-1]) < dp[i])
            {
                max = dp[i];
                ans = 1;

            }
        }
        return ans; 
    }
};



class Solution {
public:
    int commonFactors(int a, int b) {
       int ans = 1, maxans = __gcd(a,b);
        for(int i = 2; i < maxans;i++)
        {
            if((a % i == 0) && (b % i == 0)) ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        vector<vector<int>> record;
        int rows = grid.size(), cols = grid[0].size();
        for(int i = 0; i < rows; i++)
        {
            vector<int> temp(cols);
            for(int j = 0; j < cols; j++)
            {
                if(j == 0)
                {
                    temp[j] = grid[i][0];
                    continue;
                }
                else{
                    temp[j] = temp[j-1] + grid[i][j];
                }
            }
            record.push_back(temp); 
        }

        int ans = 0;
        for(int i = 1; i < rows - 1; i++)
        {
            for(int j = 1; j < cols - 1; j++)
            {
                if(j == 1)
                {
                    ans = max(ans, grid[i][j] + record[i-1][j+1] + record[i+1][j+1]);
                }
                else
                {
                    ans = max(ans, grid[i][j] + record[i-1][j+1] - record[i-1][j-2] + record[i+1][j+1] - record[i+1][j-2]);
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count2 = 0, count1 = 1;
        while(num2)
        {
            if(num2 & 1) count2++;
            num2 = num2 >> 1;
        }
        vector<int> record;

        int copynum1 = num1;

        while(copynum1)
        {
            if(copynum1 & 1) record.push_back(count1);
            count1++;
            copynum1 >> 1;
        }

        int ans = 0, n = record.size();

        if(count2 == n) return num1;
        if(count2 < n)
        {
            int j = n-1;
            while(count2--)
            {
                int temp = 1;
                temp = temp << record[j]-1;
                ans += temp;
                j--;
            }

        }
        if(count2 > n)
        {
            int need = count2 - n;
            ans = num1;
            int temp = 1;
            while(need)
            {
                if((ans & temp) == 0)
                {
                    ans += temp;
                    need--;
                    temp << 1;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = logs[0][0], time = logs[0][1];
        for(int i = 1; i < logs.size(); i++)
        {
            int temp = logs[i][1] - logs[i-1][1];
            if(temp > time) 
            {
                time = temp;
                ans = logs[i][0];
            }
            else if(temp == time) ans = min(ans, logs[i][0]);
        }
        return ans;
    }
};


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, count = 0;
        for(auto it : nums)
        {
            if(it%3 == 0)
            {
                sum+=it;
                count++;
            }
        }
        return count == 0 ? 0 : sum/count;
    }
};

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

    int getmax(long long n)
    {
        int maxnum = 0;
        while (n)
        {
            maxnum = max((int)(n % 10), maxnum);
            n /= 10;
        }
        return maxnum;    
    }


    long long makeIntegerBeautiful(long long n, int target) {
        long long ans = 0, add = 0, temp = n;
        string copy = to_string(n);
        int idx = copy.size() - 1;
        while(n || add)
        {
            if(getsum(temp) <= target) return ans;
            ans += (10 - (copy[idx] - '0') - add) * pow((copy.size() - 1) - idx, 10);
            idx--;
            add = 1;
            temp = n + ans;
        }
        return ans;
    }
};



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

    int getmax(long long n)
    {
        int maxnum = 0;
        while (n)
        {
            maxnum = max((int)(n % 10), maxnum);
            n /= 10;
        }
        return maxnum;    
    }


    long long makeIntegerBeautiful(long long n, int target) {
        long long ans = 0, add = 0, temp = n;
        string copy = to_string(n);
        int idx = copy.size() - 1;
        //cout << copy[idx]<< endl;
        while(n || add)
        {
            if(getsum(temp) <= target) return ans;
            ans += (10 - (copy[idx] - '0') - add) * pow((copy.size() - 1) - idx, 10);
            cout << (10 - (copy[idx] - '0') - add) * max((long long)1,(long long)pow((copy.size() - 1) - idx, 10));
            add = 1;
            idx--;
            temp = n + ans;
            //cout << copy[idx] - '0' << endl;
            //cout << ans << endl;
        }
        return ans;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


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

        string ans;
            }
};

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                nums[i] = 2*nums[i];
                nums[i+1] = 0;
            }
        }
        vector<int> ans(n);
        int ptr = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0){
                ans[ptr] = nums[i];
                ptr++;
            } 
        }
        return ans;
    }
};

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0, ans = -1;
        set<int> record;
        for (int i = 0, j = 0; j < n; ++j) {
            if(record.count(nums[j]) || j-i == 3)
            {
                record.erase(nums[i]);
                i++;
                sum -= nums[i];
            }
            record.emplace(nums[j]);
            sum += nums[j];
            if(record.size() == 3 && j - i == 2) ans = max(sum, ans);
        }
        return ans == -1 ? 0 : ans;
    }
};

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que1;
        //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que2;
        priority_queue<int, vector<int>, greater<>> que1;
        priority_queue<int, vector<int>, greater<>> que2;
        int n = costs.size() ,right = n-1, left = 0;
        long long ans = 0;
        while(k--)
        {
            while(left <= right && que1.size() < candidates)
            {
                que1.push(costs[left]);
                left++;
            }
            while(left <= right && que2.size() < candidates)
            {
                que2.push(costs[right]);
                right--;
            }

            if(!que1.empty() && !que2.empty() && que1.top() <= que2.top())
            {
                ans += que1.top();
                que1.pop();
            }
            else if(!que1.empty() && !que2.empty() && que1.top() > que2.top())
            {
                ans += que2.top();
                que2.pop();
            }
            else if(que2.empty() && !que1.empty())
            {
                ans += que1.top();
                que1.pop();
            }
            else if(que1.empty() && !que2.empty())
            {
                ans += que2.top();
                que2.pop();
            }
        }
        return ans;
    }
};



class Solution {
public:

    bool cmp(const int a,const int b)
    {
        return abs(a) < abs(b);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        long long ans;
        int n = robot.size(), m = factory.size();
        unordered_map<int, int> fac;
        
        sort(robot.begin(), robot.end(), cmp);
        for(int i = 0; i < m; i++)
        {
            factory[i][0] = factory[i][1]; 
        }

        for(int i = 0; i < n; i++)
        {
            int mindis = INT_MAX, minpos = 0;
            for(int j = 0; j < m; j++)
            {
                if(fac[factory[j][0]] > 0)
                {
                    if(mindis > abs(robot[i] - factory[j][0]))
                    {
                        mindis = abs(robot[i] - factory[j][0]);
                        minpos = factory[j][0];
                    }
                }
            }
            fac[minpos]--;
            ans += mindis;
        }

        return ans;
    }
};
  

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double one = celsius + 273.15;
        double two = celsius * 1.8 + 32.0;
        return {one, two};
    }
};

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        for(int )
    }
};


class Solution {
public:
        int gcd(int a, int b)
        {
            if(b) return gcd(b, a % b);
            else return a;
        }
 
    int subarrayLCM(vector<int>& nums, int k) {
        int len = nums.size();
        int res = 0;//数组数目
 
        for(int i = 0; i < len; i ++)
        {
            int x = nums[i];
            for(int j = i; j < len; j ++)
            {
                int temp = gcd(x, nums[j]);
                if(x*nums[j]/temp == k) res ++;
                else break;
            }
        }
 
        return res;
 
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMinSwaps(vector<int> &nums)
    {
    map<int, int>mp;    
    vector<int> sortedNums(nums);
    sort(sortedNums.begin(), sortedNums.end());
    for (int i = 0; i < sortedNums.size(); i++)mp[sortedNums[i]] = i ;

    int cnt = 0;
    for (int i = 0; i < nums.size();i++)
    {
        if (nums[i] == sortedNums[i])continue;
        swap(nums[i], nums[mp[nums[i]]]);
        cnt++;
    }
    return cnt;
    }


    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int n = que.size();
            vector<int> temp;
            while(n--)
            {
                auto it = que.front();
                que.pop();
                temp.push_back(it->val);
                if(root->left) que.push(root->left);
                if(root->right) que.push(root->right);
            }
            ans += getMinSwaps(temp);
        }
        return ans;
    }
};

class Solution {
public:
    #define N 100010
    #define MP make_pair
    multiset<pair<int,int> >S;
    vector<int>in[N],out[N];
    int maxEvents(vector<vector<int>>& events) {
        int mx=0,cnt=0;
        for (auto x:events){
            int l=x[0],r=x[1];
            mx=max(mx,r);
            in[l].push_back(cnt);
            out[r+1].push_back(cnt);
            cnt++;
        }
        int ans=0;
        for (int i=1;i<=mx;++i){
            for (auto x:in[i]) S.insert(MP(events[x][1],x));
            for (auto x:out[i]){
                auto it=S.find(MP(events[x][1],x));
                if (it!=S.end()) S.erase(it);
            }
            if (!S.empty()){
                S.erase(S.begin());
                ans++;
            }
        }
        return ans;
    }
    bool ishui(string str)
    {
        int len = str.length();
	    int j=len-1;
        bool flag = true;
	    for(int i = 0;i < j;i++,j--)
        {
		    if(str[i]!=str[j]) 
            {
			    flag=false;
			    break;
		    }
        }
        return flag;
	}
    int maxPalindromes(string s, int k) {
        int n = s.size();
        string temp;
        vector<vector<int>> record;
        for(int i = 0, j = 0; j < n; j++)
        {
            if(j-i >= k-1)
            {
                temp = s.substr(i, j-i+1);
                if(ishui(temp)) record.push_back({i,j});
            }
        }
        return maxEvents(record);
    }
};