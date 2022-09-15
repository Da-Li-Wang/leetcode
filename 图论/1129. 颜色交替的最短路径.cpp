#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> graph(n);
        vector<vector<int>> visited(n,vector<int>(2,0));
        //0表示red 1表示blue
        for(auto& edge:redEdges){
            int from=edge[0];
            int to=edge[1];
            graph[from].push_back({to,0});
        }
        for(auto& edge:blueEdges){
            int from=edge[0];
            int to=edge[1];
            graph[from].push_back({to,1});
        }
        queue<vector<int>> q;
        vector<int> dis(n,INT_MAX);
        dis[0]=0;
        q.push({0,0,1});//节点 距离 颜色
        q.push({0,0,0});
        while(!q.empty()){
            auto it=q.front();
            int from=it[0];
            int distance=it[1];
            int col=it[2];
            q.pop();
            for(auto& [to,colour]:graph[from]){
                if(colour==(!col) && !visited[to][colour]){
                    dis[to]=min(dis[to],distance+1);
                    q.push({to,distance+1,colour});
                    visited[to][colour]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dis[i]==INT_MAX)dis[i]=-1;
        }
        return dis;
    }
};

class Solution {
public:
   
    int minans = -1;
    vector<vector<int>> R_edges;
    vector<vector<int>> B_edges;
    vector<vector<int>> isfind;
    void dfs(int node,int minstep ,int color) // 1为红 0为蓝
    {
        if (!R_edges[node].empty() && color && !isfind[color][node])
        {
            for (auto item : R_edges[node])
            {
                isfind[color][node] = 1;
                cout<< "red : " << item << endl;
                if (item == 0)
                {
                    if (minans == -1)
                    {
                        minans = minstep;
                    }
                    else{
                        minans = min(minstep, minans);
                    }
                    //break;
                }
                
                if (item != 0 && item == node)
                {
                    dfs(item, minstep, 0);
                }
                
                else if (item != 0) dfs(item, minstep+1,0);
            }
            
        }
        
        
        else if (!B_edges[node].empty() && !color && !isfind[color][node])
        {
            for (auto item : B_edges[node])
            {
                isfind[color][node] = 1;
                cout<< "blue : " << item << endl;
                if (item == 0)
                {
                    if (minans == -1)
                    {
                        minans = minstep;
                    }
                    else{
                        minans = min(minstep, minans);
                    }
                    //break;
                }
                
                if (item != 0 && item == node)
                {
                    dfs(item, minstep, 1);
                }
                
                else if (item != 0) dfs(item, minstep+1, 1);
            }
            
        }
        
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        R_edges = vector<vector<int>>(n);
        B_edges = vector<vector<int>>(n);
        for (auto item : redEdges)
        {
            R_edges[item[1]].push_back(item[0]);
        }
        
        for (auto item : blueEdges)
        {
            B_edges[item[1]].push_back(item[0]);
        }

        vector<int> ans = vector<int>(n);

        for (int i = 0; i < n; i++)
        {
            cout << "this is RB: " << i << "//////" <<endl;
            minans = -1;
            int minstep = 0;
            isfind = vector<vector<int>>(2,vector<int>(n));
            dfs(i, minstep, 1);
            int temp = minans;
            minans = -1;
            isfind = vector<vector<int>>(2,vector<int>(n));
            cout << "this is BB: " << i << "//////" <<endl;
            dfs(i, minstep, 0);
            if (minans != -1 && temp != -1)
            {
                ans[i] = min(minans, temp);
            }
            else if(temp != -1 && minans == -1) ans[i] = temp;
            else if(temp == -1 && minans != -1) ans[i] = minans;
            else ans[i] = -1;
            
        }
        return ans;
    }
};

class Solution {
public:
   
    int minans = -1;
    vector<vector<int>> R_edges;
    vector<vector<int>> B_edges;
    vector<int> isfind;
    void dfs(int node,int minstep ,int color) // 1为红 0为蓝
    {
        if (!R_edges[node].empty() && color && !isfind[node])
        {
            for (auto item : R_edges[node])
            {
                isfind[node] = 1;
                cout<< "red : " << item << endl;
                if (item == 0)
                {
                    if (minans == -1)
                    {
                        minans = minstep;
                    }
                    else{
                        minans = min(minstep, minans);
                    }
                    break;
                }
                
                dfs(item, minstep+1,0);
            }
            
        }
        
        
        else if (!B_edges[node].empty() && !color && !isfind[node])
        {
            for (auto item : B_edges[node])
            {
                isfind[node] = 1;
                cout<< "blue : " << item << endl;
                if (item == 0)
                {
                    if (minans == -1)
                    {
                        minans = minstep;
                    }
                    else{
                        minans = min(minstep, minans);
                    }
                    break;
                }
                
                dfs(item, minstep+1, 1);
            }
            
        }
        
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        R_edges = vector<vector<int>>(n);
        B_edges = vector<vector<int>>(n);
        for (auto item : redEdges)
        {
            R_edges[item[1]].push_back(item[0]);
        }
        
        for (auto item : blueEdges)
        {
            B_edges[item[1]].push_back(item[0]);
        }

        vector<int> ans = vector<int>(n);
        ans[0] = 0;

        for (int i = 1; i < n; i++)
        {
            cout << "this is : " << i << endl;
            minans = -1;
            int minstep = 1;
            isfind = vector<int>(n);
            dfs(i, minstep, 1);
            int temp = minans;
            minans = -1;
            isfind = vector<int>(n);
            dfs(i, minstep, 0);
            if (minans != -1 && temp != -1)
            {
                ans[i] = min(minans, temp);
            }
            else if(temp != -1 && minans == -1) ans[i] = temp;
            else if(temp == -1 && minans != -1) ans[i] = minans;
            else ans[i] = -1;
            
        }
        return ans;
    }
};