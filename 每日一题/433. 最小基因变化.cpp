#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> q;
        for (string str : bank)
        {
            q.emplace(str);
        }
        
        int diff = 0;
        for (int i = 0; i < 8; i++)
        {
            if (start[i] != end[i]) diff++; 
        }
        
        if (diff > bank.size())
        {
            return -1;
        }
        int jud = diff;
        for (int count = 0; count < diff; count++)
        {
            for (int i = 0; i < 8; i++)
            {
                if (start[i] != end[i])
                {
                    string temp = start;
                    temp[i] = end[i];
                    if (q.count(temp))
                    {
                        jud--;
                        start = temp;
                    }
                    
                }
                
            }
            
        }
        return jud==0 ? diff : -1;
        
    }
};



class Solution {
public:    
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> cnt;
        unordered_set<string> visited;
        char keys[4] = {'A', 'C', 'G', 'T'};        
        for (auto & w : bank) {
            cnt.emplace(w);
        }
        if (start == end) {
            return 0;
        }
        if (!cnt.count(end)) {
            return -1;
        }
        queue<string> qu;
        qu.emplace(start);
        visited.emplace(start);
        int step = 1;
        while (!qu.empty()) {
            int sz = qu.size();
            for (int i = 0; i < sz; i++) {
                string curr = qu.front();
                qu.pop();
                for (int j = 0; j < 8; j++) {
                    for (int k = 0; k < 4; k++) {
                        if (keys[k] != curr[j]) {
                            string next = curr;
                            next[j] = keys[k];
                            if (!visited.count(next) && cnt.count(next)) {
                                if (next == end) {
                                    return step;
                                }
                                qu.emplace(next);
                                visited.emplace(next);
                            }
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};


class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> book;
        for (auto str : bank)
        {
            book.emplace(str);
        }
        
        set<string> visited;
        char change[4] = {'A', 'C', 'G', 'T'};

        if (start == end)
        {
            return 0;
        }

        if(!book.count(end)) return -1;

        int step = 0;
        queue<string> q;
        q.emplace(start);
        while (!q.empty())
        {
            string temp = q.front();
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (temp[i] != change[j])
                    {
                        temp[i] = change[j];
                        if (!visited.count(temp) && book.count(temp))
                        {
                            visited.emplace(temp);
                            if (temp == end)
                            {
                                return step + 1;
                            }
                            step++;
                            q.emplace(temp);
                        }
                        
                    }
                    
                }
                
            }
            
        }
        return -1;
    }
};


