#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> stk;

    void dfs(vector<vector<int>>& graph, int x, int n) {
        if (x == n) {
            ans.push_back(stk);
            return;
        }
        for (auto& y : graph[x]) {
            stk.push_back(y);
            dfs(graph, y, n);
            stk.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        stk.push_back(0);
        dfs(graph, 0, graph.size() - 1);
        return ans;
    }
};

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
public:
    void dfs(vector<vector<int>>& graph, int x, int target)
    {
        if (x == target)
        {
            ans.push_back(temp);
            return;
        }
        
        for (auto i : graph[x])
        {
            temp.push_back(i);
            dfs(graph, i, target);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        temp.push_back(0);
        dfs(graph, 0, graph.size() - 1);
        return ans;
    }
};