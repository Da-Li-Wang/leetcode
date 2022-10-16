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
    bool dfs(int curnode, int nowcolor, vector<int>& colors, vector<vector<int>>& f)
    {
        colors[curnode] = nowcolor;
        for(auto nextcode : f[curnode])
        {
            if(colors[nextcode] && colors[nextcode] == colors[curnode])
            {
                return false;
            }
            if(!colors[nextcode] && !dfs(nextcode, 3 ^ nowcolor, colors, f))
            {
                return false;
            }
        }
        return true;
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
            if(colors[i] == 0 && !dfs(i, 1, colors, f))
            {
                return false;
            }
        }
        return true;

    }
};

//bfs
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> f(n+1);
        vector<int> colors(n+1);

        for(auto it : dislikes)
        {
            f[it[0]].push_back(it[1]);
            f[it[1]].push_back(it[0]);
        }
        for(int i = 1; i <= n; ++i)
        {
            if(colors[i] == 0)
            {
                queue<int> que;
                que.push(i);
                colors[i] = 1;
                while(!que.empty()){
                    auto it = que.front();
                    que.pop();
                    for(auto next : f[it])
                    {
                        if(colors[next] && colors[next] == colors[it]) return false;
                        if(colors[next] == 0){
                            colors[next] = 3 ^ colors[it];
                            que.push(next);
                        }
                    }
                }
            }

        }

        return true;
    }
};

//并查集
class Solution {
public:
    int findfa(int x, vector<int>& fa)
    {
        return fa[x] < 0 ? x : fa[x] = findfa(fa[x], fa);
    }

    void unit(int x, int y, vector<int>& fa)
    {
        x = findfa(x, fa);
        y = findfa(y, fa);
        if(x == y) return;
        if(fa[x] < fa[y])
        {
            swap(x,y);
        }
        fa[x] += fa[y];
        fa[y] = x;
    }

    bool isconnect(int x, int y, vector<int>& fa)
    {
        x = findfa(x, fa);
        y = findfa(y, fa);

        return x == y;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> fa(n+1, -1);
        vector<vector<int>> f(n+1);
        for(auto it : dislikes)
        {
            f[it[0]].push_back(it[1]);
            f[it[1]].push_back(it[0]);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < f[i].size(); ++j) {
                unit(f[i][0], f[i][j], fa);
                if (isconnect(i, f[i][j], fa)) {
                    return false;
                }
            }
        }
        return true;
    }
};