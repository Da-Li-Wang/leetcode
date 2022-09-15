#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <ciso646>

using namespace std;


class Solution {
public:
    vector<vector<int>> children;
    vector<int> childnum;
    
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        int ans = INT_MIN;
        int count = 0;
        children = vector<vector<int>>(n);
        childnum = vector<int>(n);
        for (int i = 0; i < parents.size(); i++)
        {
            if (parents[i] != -1)
            {
                children[parents[i]].push_back(i);
            }
        }
        dfs(0);
        for (int i = 0; i < n; i++)
        {
            long long temp = getscore(i);
            if (temp > ans)
            {
                ans = temp;
                count = 1;
            }
            else if (temp == ans)
            {
                count++;
            }
        }
        return count;
    }
    int dfs(int root)
    {
        if (!children[root].size())
        {
            return (childnum[root] = 1);
        }
        for(int i = 0; i < children[root].size(); i++)	childnum[root] += dfs(children[root][i]);
   		return ++childnum[root]; 
    }
    int getscore(int sonroot)
    {
        long long score = 1;
        score = childnum[0] - childnum[sonroot] == 0 ? 1 : childnum[0] - childnum[sonroot];
        for (int i = 0; i < children[sonroot].size(); i++)
        {
            score *= childnum[children[sonroot][i]];
        }
        return score;
    }
};
















class Solution {
public:
	vector<vector<int>> child;
    vector<int> childTreeNums;
	long long ans = INT_MIN;
	int len, sum, ret = 0;
    int countHighestScoreNodes(vector<int>& parents) {
    	len = parents.size();
    	child = vector<vector<int>>(len);
    	childTreeNums = vector<int>(len,0);
        //保存孩子节点
    	for(int i = 0; i < len; ++i) if(parents[i] != -1) child[parents[i]].push_back(i);
    	dfs(0);
        //节点总数
    	sum = childTreeNums[0];
        //获得等于最大值的最大数目
    	for(int i = 0; i < len; i++) {
    		long long temp = getScore(i);
    		if(temp > ans){
    			ret = 1;
    			ans = temp;
    		}else if(temp == ans) ret++;
    	} 
    	return ret;
    }
    //获得所有子树的值
   	int dfs(int root){
   		if(not child[root].size()) return (childTreeNums[root] = 1);
   		for(int i = 0; i < child[root].size(); i++)	childTreeNums[root] += dfs(child[root][i]);
   		return ++childTreeNums[root];
   	}
    //得出删去item节点的分数，注意要开Long long
    long long getScore(int item){
    	long long score = 1;
    	score = childTreeNums[0] - childTreeNums[item] == 0 ? 1 : childTreeNums[0] - childTreeNums[item];
    	for(int i = 0; i < child[item].size(); i++)	score *= childTreeNums[child[item][i]];
    	return score;
    }
};

class Solution {
public:
    unordered_map<int,int>zuo;//统计每个节点左子树节点个数
    unordered_map<int,int>you;
    int dfs(vector<int>&left,vector<int>&right,int head)
    {
        if(left[head]==-1&&right[head]==-1)
        {
            return 1;//如果没有儿子，直接返回1
        }
        int m=0,n=0;
        if(left[head]!=-1)
        {
            m=dfs(left,right,left[head]);//有左儿子，才去dfs
        }
        if(right[head]!=-1)
        {
            n=dfs(left,right,right[head]);
        }
        zuo[head]=m;//左子树节点个数
        you[head]=n;
        return m+n+1;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        vector<int>left(parents.size(),-1);//每个节点的左儿子，初始化为-1
        vector<int>right(parents.size(),-1);//每个节点的右儿子，初始化为-1
        int tou=-1;//头节点，初始化为-1；
        for(int i=0;i<parents.size();i++)
        {
            if(parents[i]==-1)
            {
                tou=i;//找到头节点了
                continue;
            }
            if(left[parents[i]]==-1)
            {
                left[parents[i]]=i;//i的父亲节点还没有左儿子，先安排i为左儿子。
            }
            else{
                right[parents[i]]=i;
            }
        }
        dfs(left,right,tou);
        long long mxfen=0;//最大的分数
        int ans=0;//答案，即最大分数节点的个数
        long long now=0;//当前节点的分数
        vector<long long>cnt;//每个节点的分数，最后算出mxfen后用来统计ans
        for(int i=0;i<parents.size();i++)
        {
            now=1;
            int m=zuo[i];//i左子树所有节点个数
            int n=you[i];
            int k=parents.size()-m-n-1;
            if(m)//如果左子树非空，我们才计算，所以你发现now初始化为1
            {
                now*=m;
            }
            if(n)//右子树非空
            {
                now*=n;
            }
            if(k)//父节点非空
            {
                now*=k;
            }
            cnt.push_back(now);
            mxfen=max(mxfen,now);
        }
        for(int i=0;i<parents.size();i++)
        {
            if(cnt[i]==mxfen)
            {
                ans++;//统计答案
            }
        }
        return ans;
    }
};
