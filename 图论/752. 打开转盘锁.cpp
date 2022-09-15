#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // 哈希表vis中存储不可能入队的结点，包括deadends和已访问过的结点
        unordered_set<string> vis;
        vis.insert(deadends.begin(), deadends.end()); 
        if(vis.count("0000")) 
            return -1;
        int step = 0;
        queue<string> st;
        st.push("0000");
        while(!st.empty()){            
            int length = st.size();
            for(int i = 0; i < length; i++){
                string curr = st.front();
                st.pop();
                // 找到目标元素，直接返回答案
                if(curr == target)
                    return step;
                // 处理curr周围的八个相邻结点
                for(int j = 0; j < 4; ++j){
                    // 自增1与自减1
                    for(int t = -1; t < 2; t += 2){
                        // 完美的字符处理方式，利用ascⅡ码之差之后加上t并取余作为新得到的整型，然后再加上0的ascⅡ码值返回字符
                        char a = (curr[j] -'0' + 10 + t) % 10 + '0';
                        string newOne = curr;
                        newOne[j] = a;
                        // 若哈希集中找不到此状态，则加入哈希集同时入队
                        if(!vis.count(newOne)){
                            st.push(newOne);
                            vis.emplace(newOne);
                        }
                    }                 
                }
            }
            // 本层队列中元素处理完成，到达下一转动步数，步数加1
            step++;
        }
        return -1;
    }
};

