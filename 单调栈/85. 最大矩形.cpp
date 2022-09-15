#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        
        vector<vector<int>> record(row, vector<int>(col));

        for (int i = 0; i < row; i++)
        {
            int temp = 0;
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == '1')
                {
                    temp++;
                }
                else
                {
                    temp = 0;
                }
                record[i][j] = temp;
            }
        }

        int ans = 0;

        for(int i = 0; i < col; i++)
        {
            vector<int> up(row, 0), down(row, 0);
            stack<int> stk;

            for(int j = 0; j < row; j++)
            {
                while (!stk.empty() && record[stk.top()][i] >= record[j][i])
                {
                    stk.pop();
                }
                up[j] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }

            for(int j = row - 1; j >= row; j--)
            {
                while (!stk.empty() && record[stk.top()][i] >= record[j][i])
                {
                    stk.pop();
                }
                down[j] = stk.empty() ? row : stk.top();
                stk.push(i);
            }

            for (int j = 0; j < row; j++)
            {
                int height = down[j] - up[j] - 1;
                int area = height * record[j][i];
                ans = max(ans, area);
            }
        }
             return ans;   
    }
};

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0: left[i][j - 1]) + 1;
                }
            }
        }

        int ret = 0;
        for (int j = 0; j < n; j++) { // 对于每一列，使用基于柱状图的方法
            vector<int> up(m, 0), down(m, 0);

            stack<int> stk;
            for (int i = 0; i < m; i++) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }
            stk = stack<int>();
            for (int i = m - 1; i >= 0; i--) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                down[i] = stk.empty() ? m : stk.top();
                stk.push(i);
            }

            for (int i = 0; i < m; i++) {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                ret = max(ret, area);
            }
        }
        return ret;
    }
};
