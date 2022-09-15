#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

// 第三题 模拟 AC
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        set<int> M, G, P;
        int ansM = 0, ansG = 0, ansP = 0, maxM = 0, maxG = 0, maxP = 0;
        for(int i = 0; i < garbage.size(); i++)
        {
            for(int j = 0; j < garbage[i].size(); j++)
            {
                if(garbage[i][j] == 'M')
                {
                    ansM++;
                    maxM = max(maxM, i);
                }
                if(garbage[i][j] == 'P')
                {
                    ansP++;
                    maxP = max(maxP, i);
                }
                if(garbage[i][j] == 'G')
                {
                    ansG++;
                    maxG = max(maxG, i);
                }
            }
        }

        vector<int> cost(garbage.size());
        cost[0] = 0;
        for(int i = 1; i < garbage.size(); i++)
        {
            cost[i] = cost[i-1] + travel[i-1];
        }
        
        int ans = ansG + ansM + ansP + cost[maxG] + cost[maxM] + cost[maxP];
        return ans; 

    }
};

class Solution {
public:
    string removeStars(string s) {
        set<int> record;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '*') 
            {
                record.emplace(i);
                int temp = i;
                while(record.count(temp))
                {
                temp--;
                }
                record.emplace(temp);  
            }
        }
        /*
        if(2*record.size() == s.size()) return "";
        
        for(auto it : record)
        {
            int temp = it;
            while(record.count(temp))
            {
                temp--;
            }

            record.emplace(temp);
        }
        */
        string ans;
        for(int i = 0; i < s.size(); i++)
        {
            if(!record.count(i))
            {
                ans += s[i]; 
            }
        }
        
        return ans;
    }
};

// 第二题 模拟 AC
class Solution {
public:
    string removeStars(string s) {
        vector<int> record;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '*')
            {
                record.pop_back();
                continue;
            }
            record.push_back(i);
        }

        string ans;
        for(int i = 0; i < record.size(); i++)
        {
            ans += s[record[i]];
        }
        return ans;
    }
};

//第四题 拓扑排序 WA
class Solution {
public:
    vector<int> topo_sort(int k, vector<vector<int>> edges)
        {
            vector<vector<int>> g(k);
            vector<int> in_deg(k);

            for(auto e : edges){
                int x = e[0] - 1, y = e[1] - 1;
                g[x].push_back(y);
                ++in_deg[y];
            }

            vector<int> order;
            queue<int> q;
            for (int i = 0; i < k; i++)
            {
                if (in_deg[i] == 0)
                {
                    q.push(i);
                }
            }

            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                order.push_back(x);
                for(int y : g[x])
                {
                    if (--in_deg[y] == 0)
                    {
                        q.push(y);
                    }
                }
            }
            return order;            
        }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) 
    {
        auto row = topo_sort(k, rowConditions), col = topo_sort(k, colConditions);
        if(row.size() < k || col.size() < k) return {};
        vector<int> pos(k);
        for(int i = 0; i < k; ++i)
        {
            pos[col[i]] = i;
        }
        vector<vector<int>> ans(k, vector<int>(k));
        for(int i = 0; i < k; ++i)
        {
            ans[i][pos[row[i]]] = row[i] + 1;
        }
        return ans;
    }
};