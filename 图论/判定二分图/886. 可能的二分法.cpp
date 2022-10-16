#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;


//初见以为判断有无环 
//判断有无环 无向图 ：数学（节点数-1） dfs bfs 拓扑排序（度<=1)
//有向图 : 拓扑排序（入度为0） dfs bfs
//不是有无环类问题，
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> f(n+1);
        vector<int> edges(n+1);

        for(auto it : dislikes)
        {
            f[it[0]].push_back(it[1]);
            f[it[1]].push_back(it[0]);
            edges[it[0]]++;
            edges[it[1]]++;
        }

        set<int> record;
        queue<int> que;
        vector<int> box;

        for(int i = 1; i <= n; i++)
        {
            if(edges[i] <= 1) que.push(i),record.emplace(i);;
        }

        while(!que.empty())
        {
            int temp = que.front();
            box.push_back(temp);
            que.pop();
            for(auto it : f[temp])
            {
                edges[it]--;
                edges[temp]--;
                if(edges[it] <= 1 && !record.count(it)) que.push(it), record.emplace(it);
            }
        }

        return box.size() == n;
    }
};

//dfs
class Solution {
public:
    bool dfs(int curnode, int nowcolor, vector<int>& colors, vector<vector<int>>& g)
    {
        colors[curnode] = nowcolor;
        for()
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> f(n+1);
        vector<int> colors(n+1);

        for(auto it : dislikes)
        {
            f[it[0]].push_back(it[1]);
            f[it[1]].push_back(it[0]);
        }

        for(int i = 1; i<=n; i++)
        {
            if(colors[i] == 0 && dfs(i, 1, colors, f))
            {
                return false;
            }
        }
        return true;

    }
};