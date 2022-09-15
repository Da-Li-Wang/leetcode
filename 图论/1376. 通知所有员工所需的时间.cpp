#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//含权 自写的广度优先搜索不行
class Solution {
public:
    vector<vector<int>> edges;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        edges = vector<vector<int>>(n);
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
            {
                edges[manager[i]].push_back(i);
            }
        }
        queue<int> box;
        box.push(headID);
        while (!box.empty())
        {
            int members = box.size();
            int thistime = 0;
            while (members--)
            {
                int temp = box.front();
                cout << temp << endl;
                thistime = max(thistime, informTime[temp]);
                box.pop();
                for (auto employees : edges[temp])
                {
                    box.push(employees);    
                }
            }
            ans += thistime;
        }
        return ans;
    }     
};


//深度优先搜索
class Solution {
public:
     vector<vector<int>> edges;
     vector<int> telled;
     int ans = 0;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {      
        int temp = 0;
        edges = vector<vector<int>>(n);
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
            {
                edges[manager[i]].push_back(i);
            }
        }

        telled = vector<int>(n);
        dfs(headID, informTime, temp);
        return ans;
    }

    void dfs(int headID, vector<int>& informTime, int temp){
        telled[headID] = 1;
        temp += informTime[headID];
        if (!edges[headID].empty())
        {
            for (auto item : edges[headID] )
            {
                if (!telled[item])
                {
                    dfs(item, informTime, temp);
                }
            }
        }
        else
        {
            ans = max(ans, temp);
        }
    }
};