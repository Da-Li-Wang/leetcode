#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indeg;
    vector<int> result;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    { 
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            } 
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            result.push_back(u);
            for (int v : edges[u])
            {
                --indeg[v];
                if (indeg[v] == 0)
                {
                    q.push(v);
                }
                
            }
            
        }
        if (result.size() != numCourses) {
            return {};
        }
        return result;
        
    }
};

class Solution {
private:
    //存储有向图
    vector<vector<int>> edges;
    //标记每个节点的状态：0 = 未搜索，1 = 搜索中， 2 = 已完成
    vector<int> visted;
    //用数组模拟栈，下标0为栈底，n-1为栈顶
    vector<int> result;
    //判断图中是否有环
    bool vaild = true;
public:
    void dfs(int u){
        //将节点标记为 搜索中
        visted[u] = 1;
        //搜索相邻节点
        //只要发现有环，立即停止搜索
        for (int v : edges[u])
        {
            if (visted[v] == 0)
            {
                dfs(v);
                if (!vaild)
                {
                    return;
                }
            }
            else if(visted[v] == 1)
            {
                vaild = false;
                return;
            }
        }
        visted[u] = 2;
        result.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        edges.resize(numCourses);
        visted.resize(numCourses);
        for (const auto& info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
        }
        //每次挑选一个未搜索的节点 开始深度优先搜索
        for (int i = 0; i < numCourses && vaild; i++)
        {
            if (!visted[i])
            {
                dfs(i);
            }
            
        }
        
        if (!vaild)
        {
            return{};
        }
        reverse(result.begin(), result.end());
        return result;
    }
};