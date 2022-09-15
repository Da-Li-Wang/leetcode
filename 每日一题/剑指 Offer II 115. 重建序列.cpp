#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size(), m = sequences.size();

        vector<int> Inedges(n + 1);
        vector<vector<int>> To(n + 1);

        for (int j = 0; j < m; j++)
        {
            int n = sequences[j].size();
            for (int i = 1; i < n; i++)
            {
                To[sequences[j][i-1]].push_back(sequences[j][i]);
                Inedges[sequences[j][i]]++;
            }
        }
        
        queue<int> judge;
        for (int i = 1; i < Inedges.size(); i++)
        {
            if (Inedges[i] == 0)
            {
                judge.push(i);
            }
            
        }

        while (judge.size())
        {
            if (judge.size() > 1)
            {
                return false;
            }

            int head = judge.front();
            judge.pop();
            for (int it : To[head])
            {
                Inedges[it]--;
                if (Inedges[it] == 0)
                {
                    judge.push(it);
                }
            }
        }
        
        for (auto it : Inedges)
        {
            if (it)
            {
                return false;
            }
            
        }
        return true;
    }
};

//屎山 模仿铁锁连环
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {

        int m = sequences.size(), n = nums.size();
        map<int, set<int>> book;
        vector<int> index(n + 1);
        
        //非顺序排列 记录index
        for (int i = 0; i < n; i++)
        {
            index[nums[i]] = i;
        }
        
        if (n == 1)
        {
            return true;
        }
        
        //记录左右节点
        for (int fm = 0; fm < m; fm++)
        {
            int j = sequences[fm].size();
            if (j == n)
            {
                return true;
            }
            if (j == 1)
            {
                continue;
            }
            
            for (int i = 0; i < j; i++)
            {
                if (i == 0)
                {
                    book[sequences[fm][i]].emplace(sequences[fm][i + 1]);
                }
                else if (i == j - 1)
                {
                    book[sequences[fm][i]].emplace(sequences[fm][i - 1]);
                }
                else
                {
                    book[sequences[fm][i]].emplace(sequences[fm][i + 1]);
                    book[sequences[fm][i]].emplace(sequences[fm][i - 1]);
                } 

           }         
        }
        /*
        调试部分
        for (auto it : book)
        {
            cout <<"book[" <<it.first << "] : " << endl;
            for (auto itt : it.second)
            {
                cout << " " << itt << " ";
            }
            cout << endl;
            
        }
        */
        
        
        //验证部分
        for (int i = 1; i <= n; i++)
        {
            if (index[i] == 0)
            {
                if (!book[i].count(nums[1]))
                {
                    return false;
                }
            }
            else if (index[i] == n-1)
            {
                if (!book[i].count(nums[n - 2]))
                {
                    return false;
                }
            }
            else{
                if (!book[i].count(nums[index[i] + 1]) || !book[i].count(nums[index[i] - 1]))
                {
                    return false;
                }
            }
            
        }
        return true;
    }
};