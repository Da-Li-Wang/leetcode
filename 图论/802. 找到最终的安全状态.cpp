#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

//深度优先搜索
class Solution {
public:
    vector<int> colors;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        colors = vector<int>(n);

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (dfs(i, graph))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool dfs(int node, vector<vector<int>>& graph)
    {
        if (colors[node] > 0) {
                return colors[node] == 2;
            }
            colors[node] = 1;
            for (int y : graph[node]) {
                if (!dfs(y, graph)) {
                    return false;
                }
            }
            colors[node] = 2;
            return true;
    }
};

//拓扑排序
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        //反图，邻接表存储
        vector<vector<int>> new_graph(n);
        //节点入度
        vector<int> Indeg(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int x : graph[i])
            {
                new_graph[x].push_back(i);
            }
            Indeg[i] = graph[i].size();
        }

        //拓扑排序
        queue<int> q;
        
        for (int i = 0; i < n; i++)
        {
            if (!Indeg[i])
            {
                q.push(i);
            }
        }
        
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int x : new_graph[cur])
            {
                Indeg[x]--;
                if (!Indeg[x]) q.push(x);
            }
        }

        vector<int> ret;
        for (int i = 0; i < n; i++)
        {
            if (!Indeg[i]) ret.push_back(i);
        }
        
        return ret;
        
    }
};