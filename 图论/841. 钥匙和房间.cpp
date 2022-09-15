#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

//广度优先
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> judge;
        queue<int> box;
        box.push(0);
        while (!box.empty())
        {
            int m = box.front();
            judge.emplace(m);
            box.pop();
            for (auto key : rooms[m])
            {
                box.emplace(key);
            }
        }
        if (judge.size() != rooms.size())
        {
            return false;
        }
        return true;
    }
};

//深度优先
class Solution {
public:
    vector<int> vis;
    int num;

    void dfs(vector<vector<int>>& rooms, int x) {
        vis[x] = true;
        num++;
        for (auto& it : rooms[x]) {
            if (!vis[it]) {
                dfs(rooms, it);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        num = 0;
        vis.resize(n);
        dfs(rooms, 0);
        return num == n;
    }
};

