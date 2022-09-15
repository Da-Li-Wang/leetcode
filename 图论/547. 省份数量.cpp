#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

//深度优先搜索
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


//广度优先搜索
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        vector<int> visited(cities);
        int provinces = 0;
        queue<int> Q;
        for (int i = 0; i < cities; i++) {
            if (!visited[i]) {
                Q.push(i);
                while (!Q.empty()) {
                    int j = Q.front(); Q.pop();
                    visited[j] = 1;
                    for (int k = 0; k < cities; k++) {
                        if (isConnected[j][k] == 1 && !visited[k]) {
                            Q.push(k);
                        }
                    }
                }
                provinces++;
            }
        }
        return provinces;
    }
};


//并查集
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        vector<int> f;
        for (int i = 0; i < cities; i++)
        {
            f.push_back(i);
        }
        vector<int> r = vector<int>(cities);

        for (int i = 0; i < cities; i++)
        {
            for (int j = 0; j < cities; j++)
            {
                if (isConnected[i][j] && find(f,i) != find(f,j))
                {
                    merge(f,r,i,j);
                }
                
            }
            
        }
        
        set<int> count;
        for (int i = 0; i < cities; i++)
        {
            count.emplace(find(f,i));
        }
        return count.size();

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