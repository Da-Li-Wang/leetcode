#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if (connections.size() < n - 1) {
            return -1;
        }
        
        vector<int> f;
        for (int i = 0; i < n; i++)
        {
            f.push_back(i);
        }
        
        vector<int> r = vector<int>(n);

        for (auto item : connections)
        {
            if (find(f, item[0]) != find(f, item[1]))
            {
                merge(f,r,item[0],item[1]);
            }
        }
        

        set<int> connected;

        for (int i = 0; i < n; i++)
        {
            connected.emplace(find(f,i));
        }
        


        return connected.size()-1;
    
    }
    int find(vector<int>&f, int x)
    {
        while (x != f[x])
        {
            int parent = f[x];
            f[x] = f[parent];
            x = parent;
        }
        return x;
    }

    void merge(vector<int>& f, vector<int>& r, int x, int y)
    {
        int fx = find(f, x);
        int fy = find(f, y);
        if (fx == fy)
        {
            return;
        }

        if (r[fx] < r[fy])
        {
            f[fx] = fy;
        }
        else if(r[fy] < r[fx])
        {
           f[fy] = fx;
        }
        else{
            f[fx] = fy;
            r[fy]++;
        }
    }
};


class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int cities, int i) {
        for (int j = 0; j < cities; j++) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                visited[j] = 1;
                dfs(isConnected, visited, cities, j);
            } 
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        vector<int> visited(cities);
        int provinces = 0;
        for (int i = 0; i < cities; i++) {
            if (!visited[i]) 
            {
                dfs(isConnected, visited, cities, i);
                provinces++;
            }
        }
        return provinces;
    }
};


class Solution {
private:
    vector<vector<int>> edges;
    vector<int> used;

public:
    void dfs(int u) {
        used[u] = true;
        for (int v: edges[u]) {
            if (!used[v]) {
                dfs(v);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        edges.resize(n);
        for (const auto& conn: connections) {
            edges[conn[0]].push_back(conn[1]);
            edges[conn[1]].push_back(conn[0]);
        }
        
        used.resize(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                dfs(i);
                ++ans;
            }
        }
        
        return ans - 1;
    }
};
