#include <iostream>
#include <string>
#include <stack>
#include <vector>


using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int pos = 0;
        int ans = 0;
        stack<int> st;

        while (pos < n) {
            /* 检测当前文件的深度 */
            int depth = 1;
            while (pos < n && input[pos] == '\t') {
                pos++;
                depth++;
            }
            /* 统计当前文件名的长度 */   
            int len = 0; 
            bool isFile = false;     
            while (pos < n && input[pos] != '\n') {
                if (input[pos] == '.') {
                    isFile = true;
                }
                len++;
                pos++;
            }
            /* 跳过换行符 */
            pos++;

            while (st.size() >= depth) {
                st.pop();
            }
            if (!st.empty()) {
                len += st.top() + 1;
            }
            if (isFile) {
                ans = max(ans, len);
            } else {
                st.emplace(len);
            }
        }
        return ans;
    }
};


/*
输入：input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext

输出：32
*/

class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int pos = 0;
        int ans = 0;
        vector<int> level(n + 1);

        while (pos < n) {
            /* 检测当前文件的深度 */
            int depth = 1;
            while (pos < n && input[pos] == '\t') {
                pos++;
                depth++;
            }
            /* 统计当前文件名的长度 */   
            int len = 0; 
            bool isFile = false;     
            while (pos < n && input[pos] != '\n') {
                if (input[pos] == '.') {
                    isFile = true;
                }
                len++;
                pos++;
            }
            /* 跳过换行符 */
            pos++;

            if (depth > 1) {
                len += level[depth - 1] + 1;
            }
            if (isFile) {
                ans = max(ans, len);
            } else {
                level[depth] = len;
            }
        }
        return ans;
    }
};

